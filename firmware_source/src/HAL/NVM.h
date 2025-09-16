#pragma once

#include "Library/common.h"
#include "Middleware/Log.h"

namespace HAL_NVM
{

    // 获取总存储空间大小（字节）
    size_t GetTotalSize();

    // 获取扇区大小（字节）
    size_t GetSectorSize();

    // 获取扇区数量
    size_t GetSectorCount();

    /**
     * @brief 初始化NVM存储系统
     * @return 错误代码（ERROR_CODE::NONE表示成功）
     */
    ErrorCode Init();

    /**
     * @brief 擦除指定扇区
     * @param sector 扇区号（0到GetSectorCount()-1）
     * @return 错误代码（ERROR_CODE::NONE表示成功）
     */
    ErrorCode Erase(uint8_t sector);

    /**
     * @brief 写入数据到指定扇区
     * @param sector 扇区号（0到GetSectorCount()-1）
     * @param data 要写入的数据指针
     * @param size 要写入的数据大小（字节）
     * @return 错误代码（ERROR_CODE::NONE表示成功）
     */
    ErrorCode Write(uint8_t sector, const uint8_t *data, size_t size);

    /**
     * @brief 从指定扇区读取数据
     * @param sector 扇区号（0到GetSectorCount()-1）
     * @param buffer 接收数据的缓冲区指针
     * @param size 要读取的数据大小（字节）
     * @return 错误代码（ERROR_CODE::NONE表示成功）
     */
    ErrorCode Read(uint8_t sector, uint8_t *buffer, size_t size);

    // 调试函数：打印扇区内容
    inline void DumpSector(uint8_t sector)
    {
        if (sector >= GetSectorCount())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM::DumpSector] - Invalid sector %d (max %d)\n",
                        sector, GetSectorCount() - 1);
            return;
        }

        uint8_t buffer[GetSectorSize()] = {0};

        if (!Read(sector, buffer, GetSectorSize()))
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM::DumpSector] - Failed to read sector %d\n", sector);
            return;
        }

        LOG_PRINTF(Log::INFO, "[HAL_NVM::DumpSector] - Sector %d dump (%d bytes):\n",
                    sector, GetSectorSize());
        for (size_t i = 0; i < GetSectorSize(); i += 16)
        {
            LOG_PRINTF(Log::INFO, "%04X: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\n",
                        i,
                        buffer[i], buffer[i + 1], buffer[i + 2], buffer[i + 3],
                        buffer[i + 4], buffer[i + 5], buffer[i + 6], buffer[i + 7],
                        buffer[i + 8], buffer[i + 9], buffer[i + 10], buffer[i + 11],
                        buffer[i + 12], buffer[i + 13], buffer[i + 14], buffer[i + 15]);
        }
    }

}
