
#if defined(ARDUINO) &&              \
    !defined(ARDUINO_ARCH_RP2040) && \
    !defined(ARDUINO_ARCH_ESP32)
#include "HAL/NVM.h"

#include <Arduino.h>
#include <EEPROM.h>

namespace HAL_NVM
{

    size_t GetTotalSize()
    {
        return EEPROM.length();
    }

    size_t GetSectorSize()
    {
        return EEPROM.length();
    }

    size_t GetSectorCount()
    {
        return 1; // 始终为1，因为EEPROM是连续存储
    }

    ErrorCode Init()
    {
        // EEPROM.begin();
        LOG_PRINTF(Log::INFO, "[HAL_NVM] Initialized: %d sectors of %d bytes each\n",
                    GetSectorCount(), GetSectorSize());
        return ERROR_CODE::NONE;
    }

    ErrorCode Erase(uint8_t sector)
    {
        if (sector >= GetSectorCount())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM] Invalid sector %d (max %d)\n",
                        sector, GetSectorCount() - 1);
            return ERROR_CODE::GENERAL;
        }

        for (size_t i = 0; i < GetTotalSize(); i++)
        {
            EEPROM.write(i, 0xFF);
        }

        if (!EEPROM.commit())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM] Erase failed\n");
            return ERROR_CODE::GENERAL;
        }

        LOG_PRINTF(Log::INFO, "[HAL_NVM] Erased all data\n");
        return ERROR_CODE::NONE;
    }

    ErrorCode Write(uint8_t sector, const uint8_t *data, size_t size)
    {
        if (sector >= GetSectorCount())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM] Invalid sector %d (max %d)\n",
                        sector, GetSectorCount() - 1);
            return ERROR_CODE::GENERAL;
        }
        if (size > GetSectorSize())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM] Write size %u exceeds sector size %u\n",
                        size, GetSectorSize());
            return ERROR_CODE::GENERAL;
        }
        if (data == nullptr)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM] Write data is null pointer\n");
            return ERROR_CODE::GENERAL;
        }

        for (size_t i = 0; i < size; i++)
        {
            EEPROM.write(i, data[i]);
        }

        if (EEPROM.commit())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM] Write commit failed\n");
            return ERROR_CODE::GENERAL;
        }

        LOG_PRINTF(Log::INFO, "[HAL_NVM] Wrote %d bytes %d\n", size);
        return ERROR_CODE::NONE;
    }

    ErrorCode Read(uint8_t sector, uint8_t *buffer, size_t size)
    {
        if (sector >= GetSectorCount())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM] Invalid sector %d (max %d)\n",
                        sector, GetSectorCount() - 1);
            return ERROR_CODE::GENERAL;
        }
        if (size > GetSectorSize())
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM] Read size %u exceeds sector size %u\n",
                        size, GetSectorSize());
            return ERROR_CODE::GENERAL;
        }
        if (buffer == nullptr)
        {
            LOG_PRINTF(Log::ERROR, "[HAL_NVM] Read buffer is null pointer\n");
            return ERROR_CODE::GENERAL;
        }

        for (size_t i = 0; i < size; i++)
        {
            buffer[i] = EEPROM.read(i);
        }

        LOG_PRINTF(Log::INFO, "[NVM] Read %d bytes %d\n", size);
        return ERROR_CODE::NONE;
    }

}
#endif
