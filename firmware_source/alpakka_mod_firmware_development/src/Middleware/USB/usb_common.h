#pragma once

/* 计算每采样点字节数 (位深度/8) */
#define USB_AUDIO_BYTES_PER_SAMPLE(resolution) ((resolution) / 8)

/*
 * 计算每毫秒数据量 (包大小)
 *
 * 公式:
 *   包大小 = (采样率 × 每采样点字节数 × 通道数) / 1000
 *
 * 解释:
 *   1. 采样率 (Hz): 每秒采样点数
 *   2. 每采样点字节数: 每个采样点的数据大小
 *   3. 通道数: 音频通道数量 (单声道=1, 立体声=2)
 *   4. 除以 1000: 将每秒数据量转换为每毫秒数据量
 *
 * 注意: USB 全速设备以 1ms 为帧间隔，此计算得到每帧需要传输的数据量
 */
#define USB_AUDIO_CALC_PACKET_SIZE(freq, resolution, channels) \
    ((uint32_t)((freq) * USB_AUDIO_BYTES_PER_SAMPLE(resolution) * (channels) / 1000))
