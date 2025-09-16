
#if defined(__has_include)
#if __has_include(<pico/version.h>)
#include <pico/version.h>
#endif
#endif

#if defined(PICO_SDK_VERSION_STRING) || defined(ARDUINO_ARCH_RP2040)
#include "HAL/NVM.h"

#include <hardware/flash.h>
#include <hardware/sync.h>

namespace HAL_NVM
{

    // 所需对齐大小（RP2040要求）
    inline constexpr uint32_t REQUIRED_ALIGNMENT = 4096U;

    // 总存储空间大小（128KB）
    inline constexpr uint32_t TOTAL_SIZE = 128 * 1024;
    static_assert((TOTAL_SIZE % REQUIRED_ALIGNMENT) == 0,
                  "TOTAL_SIZE must be multiple of required platform alignment");

    // 扇区大小（4KB）
    inline constexpr uint32_t SECTOR_SIZE = REQUIRED_ALIGNMENT;
    static_assert((SECTOR_SIZE % REQUIRED_ALIGNMENT) == 0,
                  "SECTOR_SIZE must be multiple of required platform alignment");

    // 扇区数量（128KB / 4KB = 32）
    inline constexpr uint32_t SECTOR_COUNT = TOTAL_SIZE / SECTOR_SIZE;

    // RP2040: 使用最后128KB的Flash空间
    inline constexpr uint32_t PHYSICAL_START_ADDR = PICO_FLASH_SIZE_BYTES - TOTAL_SIZE;

    size_t GetTotalSize()
    {
        return TOTAL_SIZE;
    }

    size_t GetSectorSize()
    {
        return SECTOR_SIZE;
    }

    size_t GetSectorCount()
    {
        return SECTOR_COUNT;
    }

    ErrorCode Init()
    {
        LOG_PRINTF(Log::INFO, "[HAL_NVM::Init] - Initialized: %d sectors of %d bytes each\n",
                    GetSectorCount(), GetSectorSize());
        return ERROR_CODE::NONE; // RP2040无需特别初始化
    }

    ErrorCode Erase(uint8_t sector)
    {
        LOG_PRINTF(Log::INFO, "[HAL_NVM::Erase] - Start! Sector: %d\n", sector);

        if (sector >= GetSectorCount())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM::Erase] - Invalid sector %d (max %d)\n",
                        sector, GetSectorCount() - 1);
            return ERROR_CODE::GENERAL;
        }

        // 禁用中断以确保原子操作
        uint32_t offset = PHYSICAL_START_ADDR + sector * GetSectorSize();
        uint32_t ints = save_and_disable_interrupts();
        flash_range_erase(offset, GetSectorSize());
        restore_interrupts(ints);

        LOG_PRINTF(Log::INFO, "[HAL_NVM::Erase] - Sector %d erased at 0x%x\n", sector, offset);
        return ERROR_CODE::NONE;
    }

    ErrorCode Write(uint8_t sector, const uint8_t *data, size_t size)
    {
        LOG_PRINTF(Log::INFO, "[HAL_NVM::Write] - Start! Sector: %d, Size: %d\n", sector, size);

        if (sector >= GetSectorCount())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM::Write] - Invalid sector %d (max %d)\n",
                        sector, GetSectorCount() - 1);
            return ERROR_CODE::GENERAL;
        }
        if (size > GetSectorSize())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM::Write] - Size %u exceeds sector size %u\n",
                        size, GetSectorSize());
            return ERROR_CODE::GENERAL;
        }
        if (data == nullptr)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM::Write] - Data pointer is null\n");
            return ERROR_CODE::GENERAL;
        }

        uint32_t offset = PHYSICAL_START_ADDR + sector * GetSectorSize();

        // 禁用中断以确保原子操作
        uint32_t ints = save_and_disable_interrupts();

        // 先擦除整个扇区
        flash_range_erase(offset, GetSectorSize());

        // 写入数据
        flash_range_program(offset, data, size);

        // 恢复中断
        restore_interrupts(ints);

        LOG_PRINTF(Log::INFO, "[HAL_NVM::Write] - Wrote %u bytes to sector %d at 0x%x\n",
                    size, sector, offset);
        return ERROR_CODE::NONE;
    }

    ErrorCode Read(uint8_t sector, uint8_t *buffer, size_t size)
    {
        LOG_PRINTF(Log::INFO, "[HAL_NVM::Read] - Start! Sector: %d, Size: %d\n", sector, size);

        if (sector >= GetSectorCount())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM::Read] - Invalid sector %d (max %d)\n",
                        sector, GetSectorCount() - 1);
            return ERROR_CODE::GENERAL;
        }
        if (size > GetSectorSize())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM::Read] - Size %u exceeds sector size %u\n",
                        size, GetSectorSize());
            return ERROR_CODE::GENERAL;
        }
        if (buffer == nullptr)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM::Read] - Buffer pointer is null\n");
            return ERROR_CODE::GENERAL;
        }

        // 计算物理地址（XIP_NOCACHE_NOALLOC_BASE用于访问Flash）
        const uint8_t *flash_addr = (const uint8_t *)(XIP_NOCACHE_NOALLOC_BASE +
                                                      PHYSICAL_START_ADDR + sector * GetSectorSize());
        memcpy(buffer, flash_addr, size);

        LOG_PRINTF(Log::INFO, "[HAL_NVM::Read] - Read %u bytes from sector %d at 0x%x\n",
                    size, sector, (uint32_t)flash_addr);
        return ERROR_CODE::NONE;
    }

}
#endif
