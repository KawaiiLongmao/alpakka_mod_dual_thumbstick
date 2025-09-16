#pragma once

#include "Library/common.h"
#include "hal_public.h"

namespace HAL_I2C::Master
{

    /**
     * @brief 初始化 I2C 总线
     * @param port I2C 端口号（0,1,...）
     * @param sda_pin SDA 引脚号（GPIO_UNUSED 表示使用默认引脚）
     * @param scl_pin SCL 引脚号（GPIO_UNUSED 表示使用默认引脚）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     *
     * 平台特定说明：
     * - RP2040:
     *   - 支持两个 I2C 总线（端口 0 和 1）
     *   - 默认引脚：
     *     - 端口 0: SDA=4, SCL=5
     *     - 端口 1: SDA=26, SCL=27
     *   - 引脚设置为 GPIO_UNUSED 时使用默认引脚
     * - ESP32:
     *   - 支持两个 I2C 总线（端口 0 和 1）
     *   - 默认引脚：
     *     - 端口 0: SDA=8, SCL=9
     *     - 端口 1: 无默认引脚（必须指定）
     *   - 端口 1 必须指定引脚，否则可能导致异常
     * - 其他平台:
     *   - 只支持一个 I2C 总线（端口 0）
     *   - 引脚参数被忽略，使用默认引脚
     */
    ErrorCode InitBus(uint8_t port,
                      GPIONumber sda_pin = GPIO_UNUSED, GPIONumber scl_pin = GPIO_UNUSED);

    /**
     * @brief 去初始化 I2C 总线
     * @param port I2C 端口号
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     *
     * 此函数释放指定 I2C 总线的资源：
     * - 禁用 I2C 总线
     * - 释放相关硬件资源
     * - 相关引脚恢复为普通 GPIO
     */
    ErrorCode DeinitBus(uint8_t port);

    /**
     * @brief 初始化 I2C 设备
     * @param port I2C 端口号
     * @param addr 设备地址（7位或10位地址）
     * @param freq I2C 时钟频率（Hz），默认 400kHz
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode InitDevice(uint8_t port, uint16_t addr, uint32_t freq = 400 * 1000);

    /**
     * @brief 去初始化 I2C 设备
     * @param port I2C 端口号
     * @param addr 设备地址
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode DeinitDevice(uint8_t port, uint16_t addr);

    /**
     * @brief 写入数据到 I2C 设备
     * @param port I2C 端口号
     * @param addr 设备地址
     * @param write_buffer 写入数据缓冲区
     * @param write_size 写入数据大小（字节）
     * @param timeout_ms 超时时间（毫秒）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode Write(uint8_t port, uint16_t addr,
                    const uint8_t *write_buffer, size_t write_size, uint16_t timeout_ms = 0xFFFF);

    /**
     * @brief 从 I2C 设备读取数据
     * @param port I2C 端口号
     * @param addr 设备地址
     * @param read_buffer 读取数据缓冲区
     * @param read_size 读取数据大小（字节）
     * @param timeout_ms 超时时间（毫秒）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode Read(uint8_t port, uint16_t addr,
                   uint8_t *read_buffer, size_t read_size, uint16_t timeout_ms = 0xFFFF);

    /**
     * @brief 先写后读操作（复合操作）
     * @param port I2C 端口号
     * @param addr 设备地址
     * @param write_buffer 写入数据缓冲区
     * @param write_size 写入数据大小（字节）
     * @param read_buffer 读取数据缓冲区
     * @param read_size 读取数据大小（字节）
     * @param timeout_ms 超时时间（毫秒）
     * @return 错误代码（ERROR_CODE::NONE 表示成功）
     */
    ErrorCode WriteRead(uint8_t port, uint16_t addr,
                        const uint8_t *write_buffer, size_t write_size,
                        uint8_t *read_buffer, size_t read_size, uint16_t timeout_ms = 0xFFFF);

}
