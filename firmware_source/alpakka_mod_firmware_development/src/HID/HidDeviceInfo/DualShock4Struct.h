#pragma once

#include "Library/cstd_lib.h"
#include "Library/common.h"

// https://eleccelerator.com/wiki/index.php/DualShock_4
// https://controllers.fandom.com/wiki/Sony_DualShock_4

/****** HID接口核心定义 ******/
/* USB和Dongle模式使用完整控制器状态输入报告 */
#define USB_FULL_STATE_REPORT 0x01 // 完整状态报告 (ReportID 0x01)

/* 蓝牙模式状态报告切换机制 */
#define BT_REDUCED_STATE_REPORT 0x01   // 简化状态报告 (默认使用)
#define BT_CALIBRATION_REPORT 0x05     // 校准特性报告 (触发后切换报告模式)
#define BT_FULL_STATE_RANGE_START 0x11 // 扩展状态报告起始
#define BT_FULL_STATE_RANGE_END 0x19   // 扩展状态报告结束

/****** 蓝牙数据包处理规范 ******/
/**
 * 蓝牙HID数据包头部结构
 * 适用于所有非简化状态报告(0x11-0x19)
 */
struct __PACKED bt_packet_header
{
    uint8_t enable_hid : 1;   // 位0：HID数据有效标志
    uint8_t enable_audio : 1; // 位1：音频数据有效标志
    uint8_t reserved : 6;     // 位2-7：保留位
};

/* 复合数据包规则：
 * - 当enable_hid && enable_audio时，数据排列为[状态数据][音频数据]
 * - 数据包最大尺寸由具体报告ID决定
 * - 必须校验CRC32 (多项式: 0xEDB88320)
 */

/****** 蓝牙HID报告类型宏 ******/
#define BT_HID_INPUT 0xA001       // DATA(0xA0) + INPUT(0x01)
#define BT_HID_OUTPUT 0xA002      // DATA(0xA0) + OUTPUT(0x02)
#define BT_HID_FEATURE_IN 0xA003  // DATA(0xA0) + FEATURE(0x03)
#define BT_HID_FEATURE_OUT 0x5003 // DATA(0x50) + FEATURE(0x03)

/****** 控制器电源控制命令 ******/
/* Dongle关机命令 */
const uint8_t POWEROFF_DONGLE[17] = {
    0xE2, 0x02,                               // 命令头
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 填充
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  // 校验位保留区
};

/* 蓝牙关机命令 (需CRC32校验) */
const uint8_t POWEROFF_BT[50] = {
    // 0x53, 0x08, 0x02,  // 命令头
    // [47..49] = 0xE0, 0xEF, 0xA2, 0x23  // CRC32校验码
};

/****** 调试命令集 ******/
/* 音频测试命令 */
#define AUDIO_TEST_SINEWAVE 0xA00101 // 全设备正弦波测试
/* 参数说明：
 * [1] 0x01 - 启用测试模式
 * [2] 0x00 - 保留参数
 */

/* 闪存操作命令组 */
#define FLASH_READ_4000 0x08FF01     // 闪存镜像读取
#define FLASH_MIRROR_ACTION 0xA00303 // 闪存镜像操作
/* 参数示例：
 * 0x08 0xFF 0x01 0x00  // 读取偏移0x0000
 * 0xA0 0x03 0x03 0x00  // 执行镜像操作
 */

/* 校准子系统命令 */
#define CALIBRATION_CTRL_BASE 0x0801 // 校准控制命令组
enum CalibrationOps
{
    CALIB_RESET = 0x10, // 校准复位
    CALIB_ADD = 0x11,   // 校准值添加
    CALIB_MIRROR = 0x12 // 校准镜像同步
};

/****** 未分类命令 (需进一步验证) ******/
/* 音频芯片直写命令 */
#define AUDIO_CHIP_WRITE 0xA00500 // 格式: [0xA0,0x05,addr,value]
/* 超时测试命令 */
#define TIMEOUT_TEST_CMD 0xA00401 // 可能触发看门狗
/* 音频设备测试命令 */
#define AUDIO_DEV_TEST_ALL 0x082001 // 全音频设备测试

//--------------------------------------------------------------------+
// Report Summaries
//--------------------------------------------------------------------+

/****** USB ******/
// ReportID	Size	Type	Note
// 0x01	1	63	Input	Get Controller State
// 0x05	5	31	Output	Set Controller State
// 0x02	2	36	Feature	Get Calibration
// 0x04	4	36	Feature	?Possible Set Calibration
// 0x08	8	3	Feature	Write Debug Command (unconfirmed, confirmed for BT)
// 0x10	16	4	Feature	UNKNOWN Read (2 shorts)
// 0x11	17	2	Feature	UNKNOWN Read (1 short) (from FLASH?)
// 0x12	18	15	Feature	Get Controller and Host MAC
// 0x13	19	22	Feature	Set Host MAC and Link Key
// 0x14	20	16	Feature	?
// 0x15	21	44	Feature	UNKNOWN Read EXT Device Data Buffer
// 0x80	128	6	Feature	Set Controller MAC (temporary)
// 0x81	129	6	Feature	Get Controller MAC
// 0x82	130	5	Feature	?
// 0x83	131	1	Feature	?
// 0x84	132	4	Feature	?
// 0x85	133	6	Feature	?
// 0x86	134	6	Feature	?
// 0x87	135	35	Feature	?
// 0x88	136	34	Feature	set?
// 0x89	137	2	Feature	?
// 0x90	144	5	Feature	?
// 0x91	145	3	Feature	?
// 0x92	146	3	Feature	?
// 0x93	147	12	Feature	?
// 0xA0	160	6	Feature	Write Debug Command
// 0xA1	161	1	Feature	?
// 0xA2	162	1	Feature	Writing 0x01 appears to switch to DFU mode
// 0xA3	163	48	Feature	Get Controller Version/Date
// 0xA4	164	13	Feature	?
// 0xA5	165	21	Feature	Write data to bank at offset, UNKNOWN purpose
// 0xA6	166	21	Feature	UNKNOWN Read, appears to read 2 data banks, last byte is not cleared from prior report
// 0xA7	247	1	Feature	Write 1 byte, purpose unknown
// 0xA8	250	1	Feature	UNKNOWN Read
// 0xA9	251	8	Feature	UNKNOWN Read
// 0xAA	252	1	Feature	?
// 0xAB	253	57	Feature	?
// 0xAC	254	57	Feature	UNKNOWN Read
// 0xAD	255	11	Feature	UNKNOWN Read
// 0xAE	256	1	Feature	Get AC_ON STATE
// 0xAF	175	2	Feature	Get Audio Chip Ident
// 0xB0	176	63	Feature	Debug Telemetry
// 0xF0	240	63	Feature	?
// 0xF1	241	63	Feature	?
// 0xF2	242	15	Feature	?

/****** Bluetooth ******/
// ReportID	Size	Type	Note
// 0x01	1	9	Input	Get Controller State Simple
// 0x11	17	77	Input	Get Controller State or Audio
// 0x12	18	141	Input	Get Controller State and/or Audio
// 0x13	19	205	Input	Get Controller State and/or Audio
// 0x14	20	269	Input	Get Controller State and/or Audio
// 0x15	21	333	Input	Get Controller State and/or Audio
// 0x16	22	397	Input	Get Controller State and/or Audio
// 0x17	23	461	Input	Get Controller State and/or Audio
// 0x18	24	525	Input	Get Controller State and/or Audio
// 0x19	25	546	Input	Get Controller State and/or Audio
// 0x11	17	77	Output	Set Controller State or Audio
// 0x12	18	141	Output	Set Controller State and/or Audio
// 0x13	19	205	Output	Set Controller State and/or Audio
// 0x14	20	269	Output	Set Controller State and/or Audio
// 0x15	21	333	Output	Set Controller State and/or Audio
// 0x16	22	397	Output	Set Controller State and/or Audio
// 0x17	23	461	Output	Set Controller State and/or Audio
// 0x18	24	525	Output	Set Controller State and/or Audio
// 0x19	25	546	Output	Set Controller State and/or Audio
// 0x02	2	36	Feature	?
// 0x03	3	38	Feature	UNKNOWN Write AUTH related?
// 0x04	4	46	Feature	?
// 0x05	5	40	Feature	Get Calibration
// 0x06	6	52	Feature	Get Controller Version/Date
// 0x07	7	48	Feature	UNKNOWN Read EXT Device Data Buffer (with CRC32)
// 0x08	8	47	Feature	Write Debug Command
// 0x09	9	19	Feature	Get Controller and Host MAC
// 0x82	130	63	Feature	?
// 0x83	131	63	Feature	?
// 0x84	132	63	Feature	?
// 0x90	144	63	Feature	?
// 0x91	145	63	Feature	?
// 0x92	146	63	Feature	?
// 0x93	147	63	Feature	?
// 0x94	148	63	Feature	?
// 0xA0	160	63	Feature	Write Debug Command
// 0xA3	163	48	Feature	Get Controller Version/Date (omits CRC check)
// 0xA4	164	63	Feature	?
// 0xA7	167	63	Feature	?
// 0xA8	168	63	Feature	UNKNOWN Read
// 0xA9	169	63	Feature	UNKNOWN Read
// 0xAA	170	63	Feature	?
// 0xAB	171	63	Feature	?
// 0xAC	172	63	Feature	UNKNOWN Read
// 0xAD	173	63	Feature	UNKNOWN Read
// 0xB3	179	63	Feature	?
// 0xB4	180	63	Feature	?
// 0xB5	181	63	Feature	?
// 0xD0	208	63	Feature	Set Test Command?
// 0xD4	212	63	Feature	?
// 0xF0	240	63	Feature	Send challenge data
// 0xF1	241	63	Feature	Read challenge response (after 0xF2)
// 0xF2	242	15	Feature	Read challenge input ready state (after 0xF0)

/****** Dongle ******/
// ReportID	Size	Type	Note
// Normal Mode (0x0BA0)
// 0x01	1	63	Input	Get Controller State
// 0x05	5	31	Output	Set Controller State
// 0x02	2	36	Feature	Get Calibration (Bluetooth Data Order)
// 0x12	18	15	Feature	Get Controller and Host MAC
// 0x15	21	45	Feature	?
// 0x80	128	6	Feature	?
// 0x81	129	6	Feature	Get Controller MAC
// 0x85	133	6	Feature	?
// 0x86	134	6	Feature	?
// 0x8A	138	22	Feature	?
// 0xA0	160	6	Feature	?
// 0xA1	161	1	Feature	?
// 0xA2	162	1	Feature	Set Enter DFU mode (change to PID 0x0BA1)
// 0xA3	163	48	Feature	?
// 0xA4	164	13	Feature	?
// 0xA5	165	21	Feature	?
// 0xA6	166	21	Feature	?
// 0xB0	176	63	Feature	?
// 0xE0	224	2	Feature	Set Audio Output
// 0xE1	225	48	Feature	Get Dongle Version/Date
// 0xE2	226	16	Feature	Shutdown (Unknown Other Uses)
// 0xE3	227	4	Feature	Get Controller VID and PID
// 0xE4	228	1	Feature	?
// 0xE5	229	6	Feature	Get Dongle Host MAC
// DFU Mode (0x0BA1)
// 0x02	2	63	Feature	?
// 0xF0	240	62	Feature	Set Exit DFU mode (change to PID 0x0BA0)

namespace DualShock4Struct
{
    enum Direction : uint8_t
    {
        North = 0,
        NorthEast,
        East,
        SouthEast,
        South,
        SouthWest,
        West,
        NorthWest,
        None = 8
    };

    //--------------------------------------------------------------------+
    // Common Structures
    //--------------------------------------------------------------------+

    template <int N>
    struct __PACKED BTCRC
    {
        uint8_t Buff[N - 4];
        uint32_t CRC;
    };

    template <int N>
    struct __PACKED BTAudio
    {
        uint16_t FrameNumber;
        uint8_t AudioTarget; // 0x02 speaker?, 0x24 headset?, 0x03 mic?
        uint8_t SBCData[N - 3];
    };

    //--------------------------------------------------------------------+
    // Input Reports
    //--------------------------------------------------------------------+

    struct __PACKED TouchFingerData
    {
        uint8_t Index : 7;
        uint8_t NotTouching : 1;
        uint16_t FingerX : 12;
        uint16_t FingerY : 12;
    };

    struct __PACKED TouchData
    {
        uint8_t Timestamp;
        TouchFingerData Finger[2];
    };

    struct __PACKED BasicGetStateData
    {
        /*0  */ uint8_t LeftStickX;
        /*1  */ uint8_t LeftStickY;
        /*2  */ uint8_t RightStickX;
        /*3  */ uint8_t RightStickY;
        /*4.0*/ Direction DPad : 4;
        /*4.4*/ uint8_t ButtonSquare : 1;
        /*4.5*/ uint8_t ButtonCross : 1;
        /*4.6*/ uint8_t ButtonCircle : 1;
        /*4.7*/ uint8_t ButtonTriangle : 1;
        /*5.0*/ uint8_t ButtonL1 : 1;
        /*5.1*/ uint8_t ButtonR1 : 1;
        /*5.2*/ uint8_t ButtonL2 : 1;
        /*5.3*/ uint8_t ButtonR2 : 1;
        /*5.4*/ uint8_t ButtonShare : 1;
        /*5.5*/ uint8_t ButtonOptions : 1;
        /*5.6*/ uint8_t ButtonL3 : 1;
        /*5.7*/ uint8_t ButtonR3 : 1;
        /*6.0*/ uint8_t ButtonHome : 1;
        /*6.1*/ uint8_t ButtonPad : 1;
        /*6.2*/ uint8_t Counter : 6; // always 0 on USB, counts up with some skips on BT
        /*7  */ uint8_t TriggerLeft;
        /*8  */ uint8_t TriggerRight;
    };
    static_assert(sizeof(BasicGetStateData) == 9, "Expected size error");

    struct __PACKED GetStateData : BasicGetStateData
    {
        /* 9  */ uint16_t Timestamp; // in 5.33us units?
        /*11  */ uint8_t Temperture;
        /*12  */ int16_t AngularVelocityX;
        /*14  */ int16_t AngularVelocityZ;
        /*16  */ int16_t AngularVelocityY;
        /*18  */ int16_t AccelerometerX;
        /*20  */ int16_t AccelerometerY;
        /*22  */ int16_t AccelerometerZ;
        /*24  */ uint8_t ExtData[5];       // range can be set by EXT device
        /*29  */ uint8_t PowerPercent : 4; // 0x00-0x0A or 0x01-0x0B if plugged int
        /*29.4*/ uint8_t PluggedPowerCable : 1;
        /*29.5*/ uint8_t PluggedHeadphones : 1;
        /*29.6*/ uint8_t PluggedMic : 1;
        /*29,7*/ uint8_t PluggedExt : 1;
        /*30.0*/ uint8_t UnkExt1 : 1;      // ExtCapableOfExtraData?
        /*30.1*/ uint8_t UnkExt2 : 1;      // ExtHasExtraData?
        /*30.2*/ uint8_t NotConnected : 1; // Used by dongle to indicate no controller
        /*30.3*/ uint8_t Unk1 : 5;
        /*31  */ uint8_t Unk2; // unused?
        /*32  */ uint8_t TouchCount;
    };

    struct __PACKED USBGetStateData : GetStateData
    {
        struct TouchData TouchData[3];
        uint8_t Pad[3];
    };

    struct __PACKED BTGetStateData : GetStateData
    {
        struct TouchData TouchData[4];
        uint8_t Pad[6];
    };

    template <int N>
    struct __PACKED BTGetStateDataAndAudio
    {
        BTGetStateData State;
        BTAudio<N - 75> Audio;
    };

    // HID Report 0x01 Input USB/Dongle
    struct __PACKED ReportIn01USB
    {
        uint8_t ReportID; // 0x01
        USBGetStateData State;
    };

    // HID Report 0x01 Input BT
    struct __PACKED ReportIn01BT
    {
        uint8_t ReportID; // 0x01
        BasicGetStateData State;
    };

    // HID Report 0x11 Input BT
    struct __PACKED ReportIn11
    {
        union
        {
            BTCRC<78> CRC;
            struct
            {
                uint8_t ReportID; // 0x11
                uint8_t Unk1 : 6;
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t Unk2 : 7;
                uint8_t EnableAudio : 1;
                union
                {
                    BTGetStateData State;
                    BTAudio<75> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x12 Input BT
    struct __PACKED ReportIn12
    {
        union
        {
            BTCRC<142> CRC;
            struct
            {
                uint8_t ReportID; // 0x12
                uint8_t Unk1 : 6;
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t Unk2 : 7;
                uint8_t EnableAudio : 1;
                union
                {
                    BTGetStateDataAndAudio<139> State;
                    BTAudio<139> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x13 Input BT
    struct __PACKED ReportIn13
    {
        union
        {
            BTCRC<206> CRC;
            struct
            {
                uint8_t ReportID; // 0x13
                uint8_t Unk1 : 6;
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t Unk2 : 7;
                uint8_t EnableAudio : 1;
                union
                {
                    BTGetStateDataAndAudio<203> State;
                    BTAudio<203> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x14 Input BT
    struct __PACKED ReportIn14
    {
        union
        {
            BTCRC<270> CRC;
            struct
            {
                uint8_t ReportID; // 0x14
                uint8_t Unk1 : 6;
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t Unk2 : 7;
                uint8_t EnableAudio : 1;
                union
                {
                    BTGetStateDataAndAudio<267> State;
                    BTAudio<267> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x15 Input BT
    struct __PACKED ReportIn15
    {
        union
        {
            BTCRC<334> CRC;
            struct
            {
                uint8_t ReportID; // 0x15
                uint8_t Unk1 : 6;
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t Unk2 : 7;
                uint8_t EnableAudio : 1;
                union
                {
                    BTGetStateDataAndAudio<331> State;
                    BTAudio<331> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x16 Input BT
    struct __PACKED ReportIn16
    {
        union
        {
            BTCRC<398> CRC;
            struct
            {
                uint8_t ReportID; // 0x16
                uint8_t Unk1 : 6;
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t Unk2 : 7;
                uint8_t EnableAudio : 1;
                union
                {
                    BTGetStateDataAndAudio<395> State;
                    BTAudio<395> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x17 Input BT
    struct __PACKED ReportIn17
    {
        union
        {
            BTCRC<462> CRC;
            struct
            {
                uint8_t ReportID; // 0x17
                uint8_t Unk1 : 6;
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t Unk2 : 7;
                uint8_t EnableAudio : 1;
                union
                {
                    BTGetStateDataAndAudio<459> State;
                    BTAudio<459> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x18 Input BT
    struct __PACKED ReportIn18
    {
        union
        {
            BTCRC<526> CRC;
            struct
            {
                uint8_t ReportID; // 0x18
                uint8_t Unk1 : 6;
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t Unk2 : 7;
                uint8_t EnableAudio : 1;
                union
                {
                    BTGetStateDataAndAudio<523> State;
                    BTAudio<523> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x19 Input BT
    struct __PACKED ReportIn19
    {
        union
        {
            BTCRC<547> CRC;
            struct
            {
                uint8_t ReportID; // 0x19
                uint8_t Unk1 : 6;
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t Unk2 : 7;
                uint8_t EnableAudio : 1;
                union
                {
                    BTGetStateDataAndAudio<544> State;
                    BTAudio<544> Audio;
                };
            } Data;
        };
    };

    //--------------------------------------------------------------------+
    // Output Reports
    //--------------------------------------------------------------------+

    struct __PACKED USBSetStateData
    {
        uint8_t EnableRumbleUpdate : 1;
        uint8_t EnableLedUpdate : 1;
        uint8_t EnableLedBlink : 1;
        uint8_t EnableExtWrite : 1;
        uint8_t EnableVolumeLeftUpdate : 1;
        uint8_t EnableVolumeRightUpdate : 1;
        uint8_t EnableVolumeMicUpdate : 1;
        uint8_t EnableVolumeSpeakerUpdate : 1;
        uint8_t UNK_RESET1 : 1; // unknown reset, both set high by Remote Play
        uint8_t UNK_RESET2 : 1; // unknown reset, both set high by Remote Play
        uint8_t UNK1 : 1;
        uint8_t UNK2 : 1;
        uint8_t UNK3 : 1;
        uint8_t UNKPad : 3;
        uint8_t Empty1;
        uint8_t RumbleRight; // weak
        uint8_t RumbleLeft;  // strong
        uint8_t LedRed;
        uint8_t LedGreen;
        uint8_t LedBlue;
        uint8_t LedFlashOnPeriod;
        uint8_t LedFlashOffPeriod;
        uint8_t ExtDataSend[8]; // sent to I2C EXT port, stored in 8x8 byte block
        uint8_t VolumeLeft;     // 0x00 - 0x4F inclusive
        uint8_t VolumeRight;    // 0x00 - 0x4F inclusive
        uint8_t VolumeMic;      // 0x00, 0x01 - 0x40 inclusive (0x00 is special behavior)
        uint8_t VolumeSpeaker;  // 0x00 - 0x4F
        uint8_t UNK_AUDIO1 : 7; // clamped to 1-64 inclusive, appears to be set to 5 for audio
        uint8_t UNK_AUDIO2 : 1; // unknown, appears to be set to 1 for audio
        uint8_t Pad[8];
    };

    struct __PACKED BTSetStateData
    {
        uint8_t EnableRumbleUpdate : 1;
        uint8_t EnableLedUpdate : 1;
        uint8_t EnableLedBlink : 1;
        uint8_t EnableExtWrite : 1;
        uint8_t EnableVolumeLeftUpdate : 1;
        uint8_t EnableVolumeRightUpdate : 1;
        uint8_t EnableVolumeMicUpdate : 1;
        uint8_t EnableVolumeSpeakerUpdate : 1;
        uint8_t UNK_RESET1 : 1; // unknown reset, both set high by Remote Play
        uint8_t UNK_RESET2 : 1; // unknown reset, both set high by Remote Play
        uint8_t UNK1 : 1;
        uint8_t UNK2 : 1;
        uint8_t UNK3 : 1;
        uint8_t UNKPad : 3;
        uint8_t Empty1;
        uint8_t RumbleRight; // weak
        uint8_t RumbleLeft;  // strong
        uint8_t LedRed;
        uint8_t LedGreen;
        uint8_t LedBlue;
        uint8_t LedFlashOnPeriod;
        uint8_t LedFlashOffPeriod;
        uint8_t ExtDataSend[8]; // sent to I2C EXT port, stored in 8x8 byte block
        uint8_t VolumeLeft;     // 0x00 - 0x4F inclusive
        uint8_t VolumeRight;    // 0x00 - 0x4F inclusive
        uint8_t VolumeMic;      // 0x00, 0x01 - 0x40 inclusive (0x00 is special behavior)
        uint8_t VolumeSpeaker;  // 0x00 - 0x4F
        uint8_t UNK_AUDIO1 : 7; // clamped to 1-64 inclusive, appears to be set to 5 for audio
        uint8_t UNK_AUDIO2 : 1; // unknown, appears to be set to 1 for audio
        uint8_t Pad[52];
    };

    template <int N>
    struct __PACKED BTSetStateDataAndAudio
    {
        BTSetStateData State;
        BTAudio<N - 75> Audio;
    };

    // HID Report 0x05 Output USB/Dongle
    struct __PACKED ReportIn05
    {
        uint8_t ReportID; // 0x05
        USBSetStateData State;
    };

    // HID Report 0x11 Output BT
    struct __PACKED ReportOut11
    {
        union
        {
            BTCRC<78> CRC;
            struct
            {
                uint8_t ReportID;        // 0x11
                uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
                uint8_t UnkA4 : 1;
                uint8_t UnkB1 : 1;
                uint8_t UnkB2 : 1; // seems to always be 1
                uint8_t UnkB3 : 1;
                uint8_t EnableAudio : 1;
                union
                {
                    BTSetStateData State;
                    BTAudio<75> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x12 Output BT
    struct __PACKED ReportOut12
    {
        union
        {
            BTCRC<142> CRC;
            struct
            {
                uint8_t ReportID;        // 0x12
                uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
                uint8_t UnkA4 : 1;
                uint8_t UnkB1 : 1;
                uint8_t UnkB2 : 1; // seems to always be 1
                uint8_t UnkB3 : 1;
                uint8_t EnableAudio : 1;
                union
                {
                    BTSetStateDataAndAudio<139> State;
                    BTAudio<139> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x13 Output BT
    struct __PACKED ReportOut13
    {
        union
        {
            BTCRC<206> CRC;
            struct
            {
                uint8_t ReportID;        // 0x13
                uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
                uint8_t UnkA4 : 1;
                uint8_t UnkB1 : 1;
                uint8_t UnkB2 : 1; // seems to always be 1
                uint8_t UnkB3 : 1;
                uint8_t EnableAudio : 1;
                union
                {
                    BTSetStateDataAndAudio<203> State;
                    BTAudio<203> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x14 Output BT
    struct __PACKED ReportOut14
    {
        union
        {
            BTCRC<270> CRC;
            struct
            {
                uint8_t ReportID;        // 0x14
                uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
                uint8_t UnkA4 : 1;
                uint8_t UnkB1 : 1;
                uint8_t UnkB2 : 1; // seems to always be 1
                uint8_t UnkB3 : 1;
                uint8_t EnableAudio : 1;
                union
                {
                    BTSetStateDataAndAudio<267> State;
                    BTAudio<267> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x15 Output BT
    struct __PACKED ReportOut15
    {
        union
        {
            BTCRC<334> CRC;
            struct
            {
                uint8_t ReportID;        // 0x15
                uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
                uint8_t UnkA4 : 1;
                uint8_t UnkB1 : 1;
                uint8_t UnkB2 : 1; // seems to always be 1
                uint8_t UnkB3 : 1;
                uint8_t EnableAudio : 1;
                union
                {
                    BTSetStateDataAndAudio<331> State;
                    BTAudio<331> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x16 Output BT
    struct __PACKED ReportOut16
    {
        union
        {
            BTCRC<398> CRC;
            struct
            {
                uint8_t ReportID;        // 0x16
                uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
                uint8_t UnkA4 : 1;
                uint8_t UnkB1 : 1;
                uint8_t UnkB2 : 1; // seems to always be 1
                uint8_t UnkB3 : 1;
                uint8_t EnableAudio : 1;
                union
                {
                    BTSetStateDataAndAudio<395> State;
                    BTAudio<395> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x17 Output BT
    struct __PACKED ReportOut17
    {
        union
        {
            BTCRC<462> CRC;
            struct
            {
                uint8_t ReportID;        // 0x17
                uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
                uint8_t UnkA4 : 1;
                uint8_t UnkB1 : 1;
                uint8_t UnkB2 : 1; // seems to always be 1
                uint8_t UnkB3 : 1;
                uint8_t EnableAudio : 1;
                union
                {
                    BTSetStateDataAndAudio<459> State;
                    BTAudio<459> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x18 Output BT
    struct __PACKED ReportOut18
    {
        union
        {
            BTCRC<526> CRC;
            struct
            {
                uint8_t ReportID;        // 0x18
                uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
                uint8_t UnkA4 : 1;
                uint8_t UnkB1 : 1;
                uint8_t UnkB2 : 1; // seems to always be 1
                uint8_t UnkB3 : 1;
                uint8_t EnableAudio : 1;
                union
                {
                    BTSetStateDataAndAudio<523> State;
                    BTAudio<523> Audio;
                };
            } Data;
        };
    };

    // HID Report 0x19 Output BT
    struct __PACKED ReportOut19
    {
        union
        {
            BTCRC<547> CRC;
            struct
            {
                uint8_t ReportID;        // 0x19
                uint8_t PollingRate : 6; // note 0 appears to be clamped to 1
                uint8_t EnableCRC : 1;
                uint8_t EnableHID : 1;
                uint8_t EnableMic : 3; // somehow enables mic, appears to be 3 bit flags
                uint8_t UnkA4 : 1;
                uint8_t UnkB1 : 1;
                uint8_t UnkB2 : 1; // seems to always be 1
                uint8_t UnkB3 : 1;
                uint8_t EnableAudio : 1;
                union
                {
                    BTSetStateDataAndAudio<544> State;
                    BTAudio<544> Audio;
                };
            } Data;
        };
    };

    //--------------------------------------------------------------------+
    // Feature Reports
    //--------------------------------------------------------------------+

    //--------------------------------------------------------------------+
    //     Calibration
    // Reading calibration is required to switch input reports from the truncated 0x01 report to the expanded 0x11-0x19 reports.

    // Linux hid-sony.c

    // /* Set gyroscope calibration and normalization parameters.
    // * Data values will be normalized to 1/DS4_GYRO_RES_PER_DEG_S degree/s.
    // */
    // speed_2x = (gyro_speed_plus + gyro_speed_minus);
    // sc->ds4_calib_data[0].abs_code = ABS_RX;
    // sc->ds4_calib_data[0].bias = gyro_pitch_bias;
    // sc->ds4_calib_data[0].sens_numer = speed_2x*DS4_GYRO_RES_PER_DEG_S;
    // sc->ds4_calib_data[0].sens_denom = gyro_pitch_plus - gyro_pitch_minus;

    // sc->ds4_calib_data[1].abs_code = ABS_RY;
    // sc->ds4_calib_data[1].bias = gyro_yaw_bias;
    // sc->ds4_calib_data[1].sens_numer = speed_2x*DS4_GYRO_RES_PER_DEG_S;
    // sc->ds4_calib_data[1].sens_denom = gyro_yaw_plus - gyro_yaw_minus;

    // sc->ds4_calib_data[2].abs_code = ABS_RZ;
    // sc->ds4_calib_data[2].bias = gyro_roll_bias;
    // sc->ds4_calib_data[2].sens_numer = speed_2x*DS4_GYRO_RES_PER_DEG_S;
    // sc->ds4_calib_data[2].sens_denom = gyro_roll_plus - gyro_roll_minus;

    // /* Set accelerometer calibration and normalization parameters.
    // * Data values will be normalized to 1/DS4_ACC_RES_PER_G G.
    // */
    // range_2g = acc_x_plus - acc_x_minus;
    // sc->ds4_calib_data[3].abs_code = ABS_X;
    // sc->ds4_calib_data[3].bias = acc_x_plus - range_2g / 2;
    // sc->ds4_calib_data[3].sens_numer = 2*DS4_ACC_RES_PER_G;
    // sc->ds4_calib_data[3].sens_denom = range_2g;

    // range_2g = acc_y_plus - acc_y_minus;
    // sc->ds4_calib_data[4].abs_code = ABS_Y;
    // sc->ds4_calib_data[4].bias = acc_y_plus - range_2g / 2;
    // sc->ds4_calib_data[4].sens_numer = 2*DS4_ACC_RES_PER_G;
    // sc->ds4_calib_data[4].sens_denom = range_2g;

    // range_2g = acc_z_plus - acc_z_minus;
    // sc->ds4_calib_data[5].abs_code = ABS_Z;
    // sc->ds4_calib_data[5].bias = acc_z_plus - range_2g / 2;
    // sc->ds4_calib_data[5].sens_numer = 2*DS4_ACC_RES_PER_G;
    // sc->ds4_calib_data[5].sens_denom = range_2g;
    // In Remote Play, version 17 controllers lock GyroSpeedPlus and GyroSpeedMinus to 540

    // In Remote Play, a version of 18 or lower sets MotionDataTimestampUnits to 7.0999999

    // In Remote Play, a version over 18 sets MotionDataTimestampUnits to 5.3299999

    // What this value is used for is unclear.

    // Version comes from the device's revision number and is bashed from hex to decimal. (0x1F93 -> 1993)
    //--------------------------------------------------------------------+

    // USB 0x02
    struct __PACKED ReportFeatureInCalibrateUSB
    {
        uint8_t ReportID; // 0x02
        int16_t GyroPitchBias;
        int16_t GyroYawBias;
        int16_t GyroRollBias;
        int16_t GyroPitchPlus;
        int16_t GyroPitchMinus;
        int16_t GyroYawPlus;
        int16_t GyroYawMinus;
        int16_t GyroRollPlus;
        int16_t GyroRollMinus;
        int16_t GyroSpeedPlus;
        int16_t GyroSpeedMinus;
        int16_t AccelXPlus;
        int16_t AccelXMinus;
        int16_t AccelYPlus;
        int16_t AccelYMinus;
        int16_t AccelZPlus;
        int16_t AccelZMinus;
        int16_t Unknown;
    };

    // USB 0x05
    struct __PACKED ReportFeatureInCalibrateBT
    {
        union
        {
            BTCRC<41> CRC;
            struct
            {
                uint8_t ReportID; // 0x05
                int16_t GyroPitchBias;
                int16_t GyroYawBias;
                int16_t GyroRollBias;
                int16_t GyroPitchPlus;
                int16_t GyroYawPlus;
                int16_t GyroRollPlus;
                int16_t GyroPitchMinus;
                int16_t GyroYawMinus;
                int16_t GyroRollMinus;
                int16_t GyroSpeedPlus;
                int16_t GyroSpeedMinus;
                int16_t AccelXPlus;
                int16_t AccelXMinus;
                int16_t AccelYPlus;
                int16_t AccelYMinus;
                int16_t AccelZPlus;
                int16_t AccelZMinus;
                int16_t Unknown;
            } Data;
        };
    };

    // Dongle 0x02
    struct __PACKED ReportFeatureInCalibrateDongle
    {
        uint8_t ReportID; // 0x02
        int16_t GyroPitchBias;
        int16_t GyroYawBias;
        int16_t GyroRollBias;
        int16_t GyroPitchPlus;
        int16_t GyroYawPlus;
        int16_t GyroRollPlus;
        int16_t GyroPitchMinus;
        int16_t GyroYawMinus;
        int16_t GyroRollMinus;
        int16_t GyroSpeedPlus;
        int16_t GyroSpeedMinus;
        int16_t AccelXPlus;
        int16_t AccelXMinus;
        int16_t AccelYPlus;
        int16_t AccelYMinus;
        int16_t AccelZPlus;
        int16_t AccelZMinus;
        int16_t Unknown;
    };

    //--------------------------------------------------------------------+
    // Date and Version
    //--------------------------------------------------------------------+

    // Controller Date/Version Dongle/USB 0xA3
    struct __PACKED ReportFeatureInControllerVersion
    {
        uint8_t ReportID;              // 0xA3 (0x06 for BT)
        char Date[16];                 // string
        char Time[16];                 // string
        uint16_t HardwareVersionMajor; // %04x.%04x AKA DevRel
        uint16_t HardwareVersionMinor; // Must be >= 0x3100u for Remote Play
                                       // might be bitwise anded with 0xFFC0
        uint32_t SoftwareVersionMajor; // firmware ignores this for debug terminal output a hardcode of 3
        uint16_t SoftwareVersionMinor; // written %08x.%04x, 3, sw_ver_minor
        uint16_t SoftwareSeries;       // %04x
        uint32_t CodeSize;
    };

    // Controller Date/Version Bluetooth 0x06
    struct __PACKED ReportFeatureInControllerVersionBT
    {
        union
        {
            BTCRC<53> CRC;
            ReportFeatureInControllerVersion Data; // with ReportID 0x06
        };
    };

    // Dongle Date/Version Dongle 0xE1
    struct __PACKED ReportFeatureInDongleVersion
    {
        uint8_t ReportID; // 0xE1
        char Date[16];    // string
        char Time[16];    // string
        uint16_t HardwareVersionMajor;
        uint16_t HardwareVersionMinor;
        uint32_t SoftwareVersionMajor;
        uint16_t SoftwareVersionMinor;
        uint16_t SoftwareSeries;
        uint32_t CodeSize;
    };

    //--------------------------------------------------------------------+
    // MAC
    // Need to confirm these on BT
    //--------------------------------------------------------------------+

    // Get All MAC USB/Dongle 0x12
    struct __PACKED ReportFeatureInMacAll
    {
        uint8_t ReportID;     // 0x12 (0x09 for BT)
        uint8_t ClientMac[6]; // Right to Left
        uint8_t Hard08;
        uint8_t Hard25;
        uint8_t Hard00;
        uint8_t HostMac[6]; // Right to Left
    };

    // Get All MAC BT 0x09
    struct __PACKED ReportFeatureInMacAllBT
    {
        union
        {
            BTCRC<53> CRC;
            ReportFeatureInControllerVersion Data; // with ReportID 0x09
        };
    };

    // Get Client MAC USB/Dongle 0x81
    struct __PACKED ReportFeatureInMacClient
    {
        uint8_t ReportID;     // 0x81
        uint8_t ClientMac[6]; // Right to Left
    };

    // Get Host Dongle 0xE5
    struct __PACKED ReportFeatureInMacHost
    {
        uint8_t ReportID;   // 0xE5
        uint8_t HostMac[6]; // Right to Left
    };

    // Set Host MAC and Linkkey USB 0x13
    struct __PACKED ReportFeatureOutMacHost
    {
        uint8_t ReportID;     // 0x13
        uint8_t ClientMac[6]; // Right to Left
        uint8_t Linkkey[16];
    };

    // Set Client MAC USB 0x80
    struct __PACKED ReportFeatureOutMacClient
    {
        uint8_t ReportID;     // 0x80
        uint8_t ClientMac[6]; // Right to Left
    };

    //--------------------------------------------------------------------+
    // Other
    //--------------------------------------------------------------------+

    // Controller VID/PID Dongle 0xE3
    // Access controller's VID/PID to determine what controller is connected to dongle. Note: Dongle's revision number is used.
    struct __PACKED ReportFeatureInControllerVidPidDongle
    {
        uint8_t ReportID; // 0xE3
        uint16_t VID;     // Ex: 0x054C
        uint16_t PID;     // Ex: 0x09CC
    };

    // Get Audio Chip Ident 0xAF
    // Confirm if this is USB only
    struct __PACKED USBReportFeatureInMacClient
    {
        uint8_t ReportID; // 0xAF
        uint16_t Ident;   // 0x1801 for WM1801
    };

    // Get AC_ON_STATE 0xAE
    // Confirm if this is USB only, this is of unknown purpose
    struct __PACKED BTReportFeatureInMacClient
    {
        uint8_t ReportID; // 0xAE
        uint8_t Value;    // 0x00 - L, 0x01 - H
    };

    // Dongle Set Audio Output Dongle 0xE0
    // Note that the headset output does not downmix, so mono only comes from the left
    enum AudioOutput : uint8_t
    {
        HeadsetStereo = 0,  // Left and Right to headphones
        HeadsetMono,        // Left to headphones
        HeadsetMonoSpeaker, // Left to headphones, Right to speaker
        Speaker,            // Right to speaker
        Disabled = 4
    };
    struct __PACKED ReportFeatureInDongleSetAudio
    {
        uint8_t ReportID; // 0xE0
        uint8_t Unknown;  // 0x00
        AudioOutput Output;
    };
}
