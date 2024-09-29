#pragma once

#include "stdint.h"
#include "util.h"

#define VENDOR_BLUETOOTH_SOURCE 0x01
#define VENDOR_USB_SOURCE 0x02
#define DEFAULT_VENDOR_ID 0xCD26
#define DEFAULT_PRODUCT_ID 0x10A5
#define DEFAULT_BCD_DEVICE 0x0114
#define DEFAULT_SERIAL_NUM "000000000001"

// [Microsoft Corp.]
#define MICROSOFT_VID 0x045E

// [Microsoft Corp.] Xbox 360 Controller
#define XBOX_360_PID 0x028E

// [Microsoft Corp.] Xbox 360 Wireless Receiver for Windows
#define XBOX_360_W_PID 0x0291

// [Microsoft Corp.] Xbox One Wireless Controller
#define XBOX_ONE_W_PID 0x02E0

// [Microsoft Corp.] Xbox One S Controller (model 1708)
#define XBOX_ONE_S_PID 0x02EA

// [Microsoft Corp.] Xbox One S Controller [Bluetooth] (model 1708)
// Menu/select button replaces share button (supports linux kernel < 6.5)
#define XBOX_ONE_S_BT_PID 0x02FD
#define XBOX_ONE_S_BT_BCD_DEVICE 0x0408

// [Microsoft Corp.] Xbox Elite Series 2 Controller (model 1797)
#define XBOX_ELITE_SERIES_2_PID 0x0B00
#define XBOX_ELITE_SERIES_2_BCD_DEVICE 0x0409

// [Microsoft Corp.] Xbox Series X Controller (model 1914)
// Share button valid
#define XBOX_SERIES_X_PID 0x0B13
#define XBOX_SERIES_X_BCD_DEVICE 0x0509

// [Sony Corp.]
#define SONY_VID 0x054C
#define DS_MANUFACTURER "Sony Interactive Entertainment"
#define DS_PRODUCT "Wireless Controller"

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

// [Hori Co., Ltd] HORIPAD for Nintendo Switch
#define HORIPAD_NS_VID 0x0F0D
#define HORIPAD_NS_PID 0x00C1

// PS3/PC Gamepad
#define PS3_PC_GAMEPAD_VID 0x2563
#define PS3_PC_GAMEPAD_PID 0x0575

// Andriod Gamepad
#define ANDRIOD_GAMEPAD_VID 0x2563
#define ANDRIOD_GAMEPAD_PID 0x0526

#define HID_ITF_PROTOCOL_NONE 0
#define TUSB_DESC_INTERFACE 0x04
#define TUSB_CLASS_HID 0x03
#define HID_SUBCLASS_BOOT 0x01
#define HID_DESC_TYPE_HID 0x21
#define HID_DESC_TYPE_REPORT 0x22
#define TUSB_DESC_ENDPOINT 0x05
#define TUSB_XFER_INTERRUPT 0x03
#define TUSB_CLASS_VENDOR_SPECIFIC 0xFF
#define TUSB_XFER_BULK 0x02

//--------------------------------------------------------------------+
// HID Descriptor Templates
//--------------------------------------------------------------------+

// Length of template descriptor: 25 bytes
#define TUD_HID_DESC_LEN    (9 + 9 + 7)

// HID Input only descriptor
// Interface number, string index, protocol, report descriptor len, EP In address, size & polling interval
#define TUD_HID_DESCRIPTOR_T(_itfnum, _stridx, _boot_protocol, _report_desc_len, _epin, _epsize, _ep_interval) \
  /* Interface */\
  9, TUSB_DESC_INTERFACE, _itfnum, 0, 1, TUSB_CLASS_HID, (uint8_t)((_boot_protocol) ? (uint8_t)HID_SUBCLASS_BOOT : 0), _boot_protocol, _stridx,\
  /* HID descriptor */\
  9, HID_DESC_TYPE_HID, UINT16_TO_BYTE(0x0111), 0, 1, HID_DESC_TYPE_REPORT, UINT16_TO_BYTE(_report_desc_len),\
  /* Endpoint In */\
  7, TUSB_DESC_ENDPOINT, _epin, TUSB_XFER_INTERRUPT, UINT16_TO_BYTE(_epsize), _ep_interval

// Length of template descriptor: 32 bytes
#define TUD_HID_INOUT_DESC_LEN    (9 + 9 + 7 + 7)

// HID Input & Output descriptor
// Interface number, string index, protocol, report descriptor len, EP OUT & IN address, size & polling interval
#define TUD_HID_INOUT_DESCRIPTOR_T(_itfnum, _stridx, _boot_protocol, _report_desc_len, _epout, _epin, _epsize, _ep_interval) \
  /* Interface */\
  9, TUSB_DESC_INTERFACE, _itfnum, 0, 2, TUSB_CLASS_HID, (uint8_t)((_boot_protocol) ? (uint8_t)HID_SUBCLASS_BOOT : 0), _boot_protocol, _stridx,\
  /* HID descriptor */\
  9, HID_DESC_TYPE_HID, U16_TO_U8S_LE(0x0111), 0, 1, HID_DESC_TYPE_REPORT, U16_TO_U8S_LE(_report_desc_len),\
  /* Endpoint Out */\
  7, TUSB_DESC_ENDPOINT, _epout, TUSB_XFER_INTERRUPT, U16_TO_U8S_LE(_epsize), _ep_interval, \
  /* Endpoint In */\
  7, TUSB_DESC_ENDPOINT, _epin, TUSB_XFER_INTERRUPT, U16_TO_U8S_LE(_epsize), _ep_interval

// Interface number, string index, EP Out & IN address, EP size
#define TUD_VENDOR_DESCRIPTOR_T(_itfnum, _stridx, _epout, _epin, _epsize) \
  /* Interface */\
  9, TUSB_DESC_INTERFACE, _itfnum, 0, 2, TUSB_CLASS_VENDOR_SPECIFIC, 0x00, 0x00, _stridx,\
  /* Endpoint Out */\
  7, TUSB_DESC_ENDPOINT, _epout, TUSB_XFER_BULK, UINT16_TO_BYTE(_epsize), 0,\
  /* Endpoint In */\
  7, TUSB_DESC_ENDPOINT, _epin, TUSB_XFER_BULK, UINT16_TO_BYTE(_epsize), 0
