#pragma once

#define VENDOR_BLUETOOTH_SOURCE 0x01
#define VENDOR_USB_SOURCE 0x02
#define DEFAULT_VENDOR_ID 0xCD26
#define DEFAULT_PRODUCT_ID 0x10A5
#define DEFAULT_BCD_DEVICE 0x0001
#define DEFAULT_SERIAL_NUM "000000000001"

// [Microsoft Corp.]
#define MICROSOFT_VID 0x045E

// [Microsoft Corp.] Xbox 360 Controller
#define XBOX_360_CONTROLLER_PID 0x028E

// [Microsoft Corp.] Xbox 360 Wireless Receiver for Windows
#define XBOX_360_W_CONTROLLER_PID 0x0291

// [Microsoft Corp.] Xbox One Wireless Controller
#define XBOX_ONE_W_CONTROLLER_PID 0x02E0

// [Microsoft Corp.] Xbox One S Controller (model 1708)
#define XBOX_ONE_S_CONTROLLER_PID 0x02EA

// [Microsoft Corp.] Xbox One S Controller [Bluetooth] (model 1708)
// Menu/select button replaces share button (supports linux kernel < 6.5)
#define XBOX_ONE_S_CONTROLLER_BT_PID 0x02FD
#define XBOX_ONE_S_CONTROLLER_BT_BCD_DEVICE 0x0408

// [Microsoft Corp.] Xbox Elite Series 2 Controller (model 1797)
#define XBOX_ELITE_SERIES_2_CONTROLLER_PID 0x0B00
#define XBOX_ELITE_SERIES_2_CONTROLLER_BCD_DEVICE 0x0409

// [Microsoft Corp.] Xbox Series X Controller (model 1914)
// Share button valid
#define XBOX_SERIES_X_CONTROLLER_PID_USB 0x0B12
#define XBOX_SERIES_X_CONTROLLER_PID_BT 0x0B13
#define XBOX_SERIES_X_CONTROLLER_BCD_DEVICE 0x0509

// [Sony Corp.]
#define SONY_VID 0x054C

// [Sony Corp.] DualShock 3 / PlayStation 3 Controller
#define DUAL_SHOCK_3_PID 0x0268

// [Sony Corp.] DualShock 4 [CUH-ZCT1x]
#define DUAL_SHOCK_4_PID 0x05C4

// [Sony Corp.] DualShock 4 [CUH-ZCT2x]
#define DUAL_SHOCK_4_2x_PID 0x09CC
#define DUAL_SHOCK_4_2x_BCD_DEVICE 0x0100

// [Sony Corp.] DualSense wireless controller (PS5)
#define DUAL_SENSE_PID 0x0CE6
#define DUAL_SENSE_BCD_DEVICE 0x0100

// [Sony Corp.] DualSense Edge wireless controller (PS5)
#define DUAL_SENSE_EDGE_PID 0x0df2

// [Nintendo Co., Ltd]
#define NINTENDO_VID 0x057E

// [Nintendo Co., Ltd] Switch Pro Controller
#define NS_PRO_PID 0x2009
#define NS_PRO_BCD_DEVICE 0x0210

// [Hori Co., Ltd]
#define HORI_VID 0x0F0D

// [Hori Co., Ltd] HORI Pokken Tournament DX Pro Pad
#define HORI_POKKEN_PID 0x0092

// [Hori Co., Ltd] HORIPAD for Nintendo Switch
#define HORIPAD_PID 0x00C1

// [Hori Co., Ltd] HORI Wireless Switch Pad
#define HORIPAD_W_PID 0x00f6

// PS3/PC Gamepad
#define PS3_PC_GAMEPAD_VID 0x2563
#define PS3_PC_GAMEPAD_PID 0x0575

// Andriod Gamepad
#define ANDRIOD_GAMEPAD_VID 0x2563
#define ANDRIOD_GAMEPAD_PID 0x0526
