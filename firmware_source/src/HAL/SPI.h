#pragma once

#include "Library/common.h"
#include "hal_public.h"

namespace HAL_SPI::Master
{

    // 时钟极性
    enum ClockPolarity
    {
        CPOL_0 = 0, // 时钟空闲时为低电平
        CPOL_1 = 1, // 时钟空闲时为高电平
    };

    // 时钟相位
    enum ClockPhase
    {
        CPHA_0 = 0, // 数据在时钟的第一个边沿采样
        CPHA_1 = 1, // 数据在时钟的第二个边沿采样
    };

    // 位顺序
    enum BitOrder : uint8_t
    {
        MSB_FIRST, // 最高位先传输
        LSB_FIRST, // 最低位先传输
    };

    // SPI 总线配置
    struct BusConfig
    {
        GPIONumber mosi_pin = GPIO_UNUSED; ///< 主设备发送引脚 (Master Out Slave In)
        GPIONumber miso_pin = GPIO_UNUSED; ///< 主设备接收引脚 (Master In Slave Out)
        GPIONumber sclk_pin = GPIO_UNUSED; ///< 时钟引脚 (Serial Clock)
    };

    // SPI 设备配置
    struct DeviceConfig
    {
        uint32_t freq = 10 * 1000 * 1000; ///< SPI 时钟频率 (Hz)，默认 10MHz
        ClockPolarity cpol = CPOL_0;      ///< 时钟极性，默认 CPOL_0
        ClockPhase cpha = CPHA_0;         ///< 时钟相位，默认 CPHA_0
        BitOrder bit_order = MSB_FIRST;   ///< 位顺序，默认 MSB_FIRST
    };

    /**
     * @brief 初始化 SPI 总线
     * @param port SPI 端口号
     * @param config 总线配置
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     *
     * 平台特定说明：
     * - RP2040:
     *   - 支持两个 SPI 总线（端口 0 和 1）
     * - ESP32:
     *   - 支持多个 SPI 总线（具体数量取决于芯片型号）
     * - 其他平台:
     *   - 只支持一个 SPI 总线（端口 0）
     *   - 使用默认引脚
     */
    ErrorCode InitBus(uint8_t port, const BusConfig &config = {});

    /**
     * @brief 去初始化 SPI 总线
     * @param port SPI 端口号
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     *
     * 此函数释放指定 SPI 总线的资源：
     * - 禁用 SPI 总线
     * - 释放相关硬件资源
     * - 相关引脚恢复为普通 GPIO
     */
    ErrorCode DeinitBus(uint8_t port);

    /**
     * @brief 初始化 SPI 设备
     * @param port SPI 端口号
     * @param cs_pin 片选引脚（GPIO_UNUSED 表示不使用片选控制）
     * @param config 设备配置
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode InitDevice(uint8_t port, GPIONumber cs_pin,
                         const DeviceConfig &config = {});

    /**
     * @brief 去初始化 SPI 设备
     * @param port SPI 端口号
     * @param cs_pin 片选引脚（GPIO_UNUSED 表示不使用片选控制）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode DeinitDevice(uint8_t port, GPIONumber cs_pin);

    /**
     * @brief 写入数据到 SPI 设备
     * @param port SPI 端口号
     * @param cs_pin 片选引脚（GPIO_UNUSED 表示不使用片选控制）
     * @param write_buffer 写入数据缓冲区
     * @param write_size 写入数据大小（字节）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode Write(uint8_t port, GPIONumber cs_pin,
                    const uint8_t *write_buffer, size_t write_size);

    /**
     * @brief 从 SPI 设备读取数据
     * @param port SPI 端口号
     * @param cs_pin 片选引脚（GPIO_UNUSED 表示不使用片选控制）
     * @param repeated_tx_data 读取时发送的重复数据
     * @param read_buffer 读取数据缓冲区
     * @param read_size 读取数据大小（字节）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode Read(uint8_t port, GPIONumber cs_pin,
                   uint8_t repeated_tx_data, uint8_t *read_buffer, size_t read_size);

    /**
     * @brief 先写后读操作（复合操作）
     * @param port SPI 端口号
     * @param cs_pin 片选引脚（GPIO_UNUSED 表示不使用片选控制）
     * @param write_buffer 写入数据缓冲区
     * @param write_size 写入数据大小（字节）
     * @param repeated_tx_data 读取时发送的重复数据
     * @param read_buffer 读取数据缓冲区
     * @param read_size 读取数据大小（字节）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode WriteRead(uint8_t port, GPIONumber cs_pin,
                        const uint8_t *write_buffer, size_t write_size,
                        uint8_t repeated_tx_data, uint8_t *read_buffer, size_t read_size);

    /**
     * @brief 初始化 SPI 设备（无片选引脚）
     * @param port SPI 端口号
     * @param config 设备配置
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    inline ErrorCode InitDevice(uint8_t port, const DeviceConfig &config = {})
    {
        return InitDevice(port, GPIO_UNUSED, config);
    }

    /**
     * @brief 去初始化 SPI 设备（无片选引脚）
     * @param port SPI 端口号
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    inline ErrorCode DeinitDevice(uint8_t port)
    {
        return DeinitDevice(port, GPIO_UNUSED);
    }

    /**
     * @brief 写入数据到 SPI 设备（无片选引脚）
     * @param port SPI 端口号
     * @param write_buffer 写入数据缓冲区
     * @param write_size 写入数据大小（字节）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    inline ErrorCode Write(uint8_t port,
                           const uint8_t *write_buffer, size_t write_size)
    {
        return Write(port, GPIO_UNUSED, write_buffer, write_size);
    }

    /**
     * @brief 从 SPI 设备读取数据（无片选引脚）
     * @param port SPI 端口号
     * @param repeated_tx_data 读取时发送的重复数据
     * @param read_buffer 读取数据缓冲区
     * @param read_size 读取数据大小（字节）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    inline ErrorCode Read(uint8_t port,
                          uint8_t repeated_tx_data, uint8_t *read_buffer, size_t read_size)
    {
        return Read(port, GPIO_UNUSED, repeated_tx_data, read_buffer, read_size);
    }

    /**
     * @brief 先写后读操作（复合操作，无片选引脚）
     * @param port SPI 端口号
     * @param write_buffer 写入数据缓冲区
     * @param write_size 写入数据大小（字节）
     * @param repeated_tx_data 读取时发送的重复数据
     * @param read_buffer 读取数据缓冲区
     * @param read_size 读取数据大小（字节）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    inline ErrorCode WriteRead(uint8_t port,
                               const uint8_t *write_buffer, size_t write_size,
                               uint8_t repeated_tx_data, uint8_t *read_buffer, size_t read_size)
    {
        return WriteRead(port, GPIO_UNUSED, write_buffer, write_size,
                         repeated_tx_data, read_buffer, read_size);
    }

}
