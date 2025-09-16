#pragma once

#include "Library/cstd_lib.h"
#include "Library/common.h"

#define KEYBRD_101_HID_REPORT_DESCRIPTOR(report_id)                            \
    0x05, 0x01,          /* USAGE_PAGE (Generic Desktop) */                    \
        0x09, 0x06,      /* USAGE (Keyboard) */                                \
        0xa1, 0x01,      /* COLLECTION (Application) */                        \
        0x85, report_id, /*   REPORT_ID (1) */                                 \
        0x05, 0x07,      /*   USAGE_PAGE (Keyboard) */                         \
        0x19, 0xe0,      /*   USAGE_MINIMUM (Keyboard LeftControl) */          \
        0x29, 0xe7,      /*   USAGE_MAXIMUM (Keyboard Right GUI) */            \
        0x15, 0x00,      /*   LOGICAL_MINIMUM (0) */                           \
        0x25, 0x01,      /*   LOGICAL_MAXIMUM (1) */                           \
        0x75, 0x01,      /*   REPORT_SIZE (1) */                               \
        0x95, 0x08,      /*   REPORT_COUNT (8) */                              \
        0x81, 0x02,      /*   INPUT (Data,Var,Abs) */                          \
        0x95, 0x01,      /*   REPORT_COUNT (1) */                              \
        0x75, 0x08,      /*   REPORT_SIZE (8) */                               \
        0x81, 0x03,      /*   INPUT (Cnst,Var,Abs) */                          \
        0x95, 0x05,      /*   REPORT_COUNT (5) */                              \
        0x75, 0x01,      /*   REPORT_SIZE (1) */                               \
        0x05, 0x08,      /*   USAGE_PAGE (LEDs) */                             \
        0x19, 0x01,      /*   USAGE_MINIMUM (Num Lock) */                      \
        0x29, 0x05,      /*   USAGE_MAXIMUM (Kana) */                          \
        0x91, 0x02,      /*   OUTPUT (Data,Var,Abs) */                         \
        0x95, 0x01,      /*   REPORT_COUNT (1) */                              \
        0x75, 0x03,      /*   REPORT_SIZE (3) */                               \
        0x91, 0x03,      /*   OUTPUT (Cnst,Var,Abs) */                         \
        0x95, 0x06,      /*   REPORT_COUNT (6) */                              \
        0x75, 0x08,      /*   REPORT_SIZE (8) */                               \
        0x15, 0x00,      /*   LOGICAL_MINIMUM (0) */                           \
        0x25, 0x65,      /*   LOGICAL_MAXIMUM (101) */                         \
        0x05, 0x07,      /*   USAGE_PAGE (Keyboard) */                         \
        0x19, 0x00,      /*   USAGE_MINIMUM (Reserved (no event indicated)) */ \
        0x29, 0x65,      /*   USAGE_MAXIMUM (Keyboard Application) */          \
        0x81, 0x00,      /*   INPUT (Data,Ary,Abs) */                          \
        0xc0             /* END_COLLECTION */

#define NKRO_KEYBRD_104_HID_REPORT_DESCRIPTOR(report_id)              \
    0x05, 0x01,          /* USAGE_PAGE (Generic Desktop)  */          \
        0x09, 0x06,      /* USAGE (Keyboard) */                       \
        0xa1, 0x01,      /* COLLECTION (Application) */               \
        0x85, report_id, /*   REPORT_ID (1) */                        \
        0x05, 0x07,      /*   USAGE_PAGE (Keyboard) */                \
        0x19, 0xe0,      /*   USAGE_MINIMUM (Keyboard LeftControl) */ \
        0x29, 0xe7,      /*   USAGE_MAXIMUM (Keyboard Right GUI) */   \
        0x15, 0x00,      /*   LOGICAL_MINIMUM (0) */                  \
        0x25, 0x01,      /*   LOGICAL_MAXIMUM (1) */                  \
        0x75, 0x01,      /*   REPORT_SIZE (1) */                      \
        0x95, 0x08,      /*   REPORT_COUNT (8) */                     \
        0x81, 0x02,      /*   INPUT (Data,Var,Abs) */                 \
        0x75, 0x08,      /*   REPORT_SIZE (8) */                      \
        0x95, 0x01,      /*   REPORT_COUNT (1) */                     \
        0x81, 0x03,      /*   INPUT (Cnst,Var,Abs) */                 \
        0x05, 0x08,      /*   USAGE_PAGE (LEDs) */                    \
        0x19, 0x01,      /*   USAGE_MINIMUM (Num Lock) */             \
        0x29, 0x05,      /*   USAGE_MAXIMUM (Kana) */                 \
        0x75, 0x01,      /*   REPORT_SIZE (1) */                      \
        0x95, 0x05,      /*   REPORT_COUNT (5) */                     \
        0x91, 0x02,      /*   OUTPUT (Data,Var,Abs) */                \
        0x75, 0x03,      /*   REPORT_SIZE (3) */                      \
        0x95, 0x01,      /*   REPORT_COUNT (1) */                     \
        0x91, 0x03,      /*   OUTPUT (Cnst,Var,Abs) */                \
        0x05, 0x07,      /*   USAGE_PAGE (Keyboard) */                \
        0x19, 0x04,      /*   USAGE_MINIMUM (Keyboard a and A) */     \
        0x29, 0x6b,      /*   USAGE_MAXIMUM (Keyboard F16) */         \
        0x15, 0x00,      /*   LOGICAL_MINIMUM (0) */                  \
        0x25, 0x01,      /*   LOGICAL_MAXIMUM (1) */                  \
        0x75, 0x01,      /*   REPORT_SIZE (1) */                      \
        0x95, 0x68,      /*   REPORT_COUNT (104) */                   \
        0x81, 0x02,      /*   INPUT (Data,Var,Abs) */                 \
        0xc0             /* END_COLLECTION */

#define CUSTOM_KEYBRD_HID_REPORT_DESCRIPTOR(report_id, app_id)                                                        \
    0x05, 0x01,           /* Usage Page (Generic Desktop Ctrls) */                                                    \
        0x09, 0x06,       /* Usage (Keyboard) */                                                                      \
        0xA1, 0x01,       /* Collection (Application) */                                                              \
        0x85, report_id,  /*   Report ID (1) */                                                                       \
        0x05, 0x07,       /*   Usage Page (Kbrd/Keypad) */                                                            \
        0x19, 0xE0,       /*   Usage Minimum (0xE0) */                                                                \
        0x29, 0xE7,       /*   Usage Maximum (0xE7) */                                                                \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x01,       /*   Logical Maximum (1) */                                                                 \
        0x75, 0x01,       /*   Report Size (1) */                                                                     \
        0x95, 0x08,       /*   Report Count (8) */                                                                    \
        0x81, 0x02,       /*   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */                \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x81, 0x03,       /*   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position) */               \
        0x95, 0x05,       /*   Report Count (5) */                                                                    \
        0x75, 0x01,       /*   Report Size (1) */                                                                     \
        0x05, 0x08,       /*   Usage Page (LEDs) */                                                                   \
        0x19, 0x01,       /*   Usage Minimum (Num Lock) */                                                            \
        0x29, 0x05,       /*   Usage Maximum (Kana) */                                                                \
        0x91, 0x02,       /*   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */  \
        0x95, 0x01,       /*   Report Count (1) */                                                                    \
        0x75, 0x03,       /*   Report Size (3) */                                                                     \
        0x91, 0x03,       /*   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0x95, 0x06,       /*   Report Count (6) */                                                                    \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x15, 0x00,       /*   Logical Minimum (0) */                                                                 \
        0x25, 0x65,       /*   Logical Maximum (101) */                                                               \
        0x05, 0x07,       /*   Usage Page (Kbrd/Keypad) */                                                            \
        0x19, 0x00,       /*   Usage Minimum (0x00) */                                                                \
        0x29, 0x65,       /*   Usage Maximum (0x65) */                                                                \
        0x81, 0x00,       /*   Input (Data,Array,Abs,No Wrap,Linear,Preferred State,No Null Position) */              \
        0x06, 0x00, 0xFF, /*   Usage Page (Vendor Defined 0xFF00) */                                                  \
        0x85, app_id,     /*   Report ID (5) */                                                                       \
        0x09, 0x01,       /*   Usage (0x01) */                                                                        \
        0x75, 0x08,       /*   Report Size (8) */                                                                     \
        0x95, 0x3F,       /*   Report Count (63) */                                                                   \
        0xB1, 0x02,       /*   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile) */ \
        0xC0              /* End Collection */

enum class KeybrdKey : uint8_t
{
    // -- 保留值和错误状态 (0x00-0x03) --
    NO_EVENT = 0x00,        // 表示没有按键被按下 无事件指示
    ERROR_ROLLOVER = 0x01,  // 表示按键过多（按键冲突）
    POST_FAIL = 0x02,       // 表示POST失败
    ERROR_UNDEFINED = 0x03, // 表示未定义的错误

    // -- 字母键 (0x04-0x1D) --
    A = 0x04,
    B = 0x05,
    C = 0x06,
    D = 0x07,
    E = 0x08,
    F = 0x09,
    G = 0x0A,
    H = 0x0B,
    I = 0x0C,
    J = 0x0D,
    K = 0x0E,
    L = 0x0F,
    M = 0x10,
    N = 0x11,
    O = 0x12,
    P = 0x13,
    Q = 0x14,
    R = 0x15,
    S = 0x16,
    T = 0x17,
    U = 0x18,
    V = 0x19,
    W = 0x1A,
    X = 0x1B,
    Y = 0x1C,
    Z = 0x1D,

    // -- 数字和符号键 (0x1E-0x27) --
    NUM_1 = 0x1E,
    NUM_2 = 0x1F,
    NUM_3 = 0x20,
    NUM_4 = 0x21,
    NUM_5 = 0x22,
    NUM_6 = 0x23,
    NUM_7 = 0x24,
    NUM_8 = 0x25,
    NUM_9 = 0x26,
    NUM_0 = 0x27,

    // -- 控制键和功能键 (0x28-0x3B) --
    ENTER = 0x28,     // 回车(主键盘)
    ESCAPE = 0x29,    // Esc
    BACKSPACE = 0x2A, // Backspace/退格
    TAB = 0x2B,       // Tab
    SPACE = 0x2C,     // 空格键
    MINUS = 0x2D,
    EQUAL = 0x2E,
    LEFT_BRACKET = 0x2F,
    RIGHT_BRACKET = 0x30,
    BACKSLASH = 0x31,
    KB_NON_US_HASH = 0x32, // 非美式键盘的 "#~"
    SEMICOLON = 0x33,
    QUOTE = 0x34,
    GRAVE = 0x35,
    COMMA = 0x36,
    PERIOD = 0x37,
    SLASH = 0x38,
    CAPS_LOCK = 0x39,

    // -- 功能键 F1-F12 (0x3A-0x45) --
    F1 = 0x3A,
    F2 = 0x3B,
    F3 = 0x3C,
    F4 = 0x3D,
    F5 = 0x3E,
    F6 = 0x3F,
    F7 = 0x40,
    F8 = 0x41,
    F9 = 0x42,
    F10 = 0x43,
    F11 = 0x44,
    F12 = 0x45,

    // -- 系统控制键 (0x46-0x49) --
    PRINT_SCREEN = 0x46,
    SCROLL_LOCK = 0x47,
    PAUSE = 0x48,

    // 导航键
    INSERT = 0x49,
    HOME = 0x4A,
    PAGE_UP = 0x4B,
    DELETE = 0x4C, // Delete
    END = 0x4D,
    PAGE_DOWN = 0x4E,

    // -- 方向键 (0x4F-0x52) --
    RIGHT_ARROW = 0x4F,
    LEFT_ARROW = 0x50,
    DOWN_ARROW = 0x51,
    UP_ARROW = 0x52,

    // -- 数字小键盘 (0x53-0x63) --
    NUM_LOCK = 0x53,
    KEYPAD_SLASH = 0x54,    // /
    KEYPAD_ASTERISK = 0x55, // *
    KEYPAD_MINUS = 0x56,    // -
    KEYPAD_PLUS = 0x57,     // +
    KEYPAD_ENTER = 0x58,    // 小键盘回车
    KEYPAD_1 = 0x59,        // End
    KEYPAD_2 = 0x5A,        // ↓
    KEYPAD_3 = 0x5B,        // PageDn
    KEYPAD_4 = 0x5C,        // ←
    KEYPAD_5 = 0x5D,        // (无功能)
    KEYPAD_6 = 0x5E,        // →
    KEYPAD_7 = 0x5F,        // Home
    KEYPAD_8 = 0x60,        // ↑
    KEYPAD_9 = 0x61,        // PageUp
    KEYPAD_0 = 0x62,        // Insert
    KEYPAD_DOT = 0x63,      // Delete

    // -- 国际键和特殊符号 (0x64-0x65) --
    NON_US_BACKSLASH = 0x64, // 非美式键盘的 "\|"
    APPLICATION = 0x65,      // 应用键（右键菜单）
    POWER = 0x66,            // 系统电源
    KEYPAD_EQUAL = 0x67,     // = (ISO-only)

    // 多媒体键
    F13 = 0x68,
    F14 = 0x69,
    F15 = 0x6A,
    F16 = 0x6B,
    F17 = 0x6C,
    F18 = 0x6D,
    F19 = 0x6E,
    F20 = 0x6F,
    F21 = 0x70,
    F22 = 0x71,
    F23 = 0x72,
    F24 = 0x73,

    // 特殊键
    EXECUTE = 0x74, // 执行
    HELP = 0x75,    // 帮助
    MENU = 0x76,    // 菜单
    SELECT = 0x77,  // 选择
    STOP = 0x78,    // 停止
    AGAIN = 0x79,   // 重做
    UNDO = 0x7A,    // 撤销
    CUT = 0x7B,     // 剪切
    COPY = 0x7C,    // 复制
    PASTE = 0x7D,   // 粘贴
    FIND = 0x7E,    // 查找

    // 多媒体键
    MUTE = 0x7F,
    VOLUME_UP = 0x80,
    VOLUME_DOWN = 0x81,

    // 锁定键
    LOCKING_CAPS_LOCK = 0x82,
    LOCKING_NUM_LOCK = 0x83,
    LOCKING_SCROLL_LOCK = 0x84,

    KEYPAD_COMMA = 0x85,
    KEYPAD_EQUAL_SIGN = 0x86,

    // 国际键
    INTERNATIONAL1 = 0x87, // 日语半角/全角
    INTERNATIONAL2 = 0x88, // 韩语Hanja
    INTERNATIONAL3 = 0x89, // 日语Katakana
    INTERNATIONAL4 = 0x8A, // 日语Hiragana
    INTERNATIONAL5 = 0x8B, // 日语Zenkaku/Hankaku
    INTERNATIONAL6 = 0x8C,
    INTERNATIONAL7 = 0x8D,
    INTERNATIONAL8 = 0x8E,
    INTERNATIONAL9 = 0x8F,

    // 语言键
    LANG1 = 0x90,
    LANG2 = 0x91,
    LANG3 = 0x92,
    LANG4 = 0x93,
    LANG5 = 0x94,
    LANG6 = 0x95,
    LANG7 = 0x96,
    LANG8 = 0x97,
    LANG9 = 0x98,

    // --------------------------------------------------
    // 保留值 (Reserved)
    // --------------------------------------------------
    /* 0x7F-0xDF 为USB保留区域，不可使用 */
    /* 0xE8-0xFFFF 为厂商自定义区域 */

    ALTERNATE_ERASE = 0x99,
    SYSREQ = 0x9A,
    CANCEL = 0x9B,
    CLEAR = 0x9C,
    PRIOR = 0x9D,
    RETURN = 0x9E,
    SEPARATOR = 0x9F,
    OUT = 0xA0,
    OPER = 0xA1,
    CLEAR_AGAIN = 0xA2,
    CRSEL = 0xA3,
    EXSEL = 0xA4,

    KEYPAD_00 = 0xB0,
    KEYPAD_000 = 0xB1,
    THOUSANDS_SEPARATOR = 0xB2,
    DECIMAL_SEPARATOR = 0xB3,
    CURRENCY_UNIT = 0xB4,
    CURRENCY_SUB_UNIT = 0xB5,
    KEYPAD_LEFT_PAREN = 0xB6,
    KEYPAD_RIGHT_PAREN = 0xB7,
    KEYPAD_LEFT_BRACE = 0xB8,
    KEYPAD_RIGHT_BRACE = 0xB9,
    KEYPAD_TAB = 0xBA,
    KEYPAD_BACKSPACE = 0xBB,
    KEYPAD_A = 0xBC,
    KEYPAD_B = 0xBD,
    KEYPAD_C = 0xBE,
    KEYPAD_D = 0xBF,
    KEYPAD_E = 0xC0,
    KEYPAD_F = 0xC1,
    KEYPAD_XOR = 0xC2,
    KEYPAD_CARET = 0xC3,
    KEYPAD_PERCENT = 0xC4,
    KEYPAD_LESS_THAN = 0xC5,
    KEYPAD_GREATER_THAN = 0xC6,
    KEYPAD_AMPERSAND = 0xC7,
    KEYPAD_DOUBLE_AMPERSAND = 0xC8,
    KEYPAD_VERTICAL_BAR = 0xC9,
    KEYPAD_DOUBLE_VERTICAL_BAR = 0xCA,
    KEYPAD_COLON = 0xCB,
    KEYPAD_HASH = 0xCC,
    KEYPAD_SPACE = 0xCD,
    KEYPAD_AT = 0xCE,
    KEYPAD_EXCLAMATION = 0xCF,
    KEYPAD_MEMORY_STORE = 0xD0,
    KEYPAD_MEMORY_RECALL = 0xD1,
    KEYPAD_MEMORY_CLEAR = 0xD2,
    KEYPAD_MEMORY_ADD = 0xD3,
    KEYPAD_MEMORY_SUBTRACT = 0xD4,
    KEYPAD_MEMORY_MULTIPLY = 0xD5,
    KEYPAD_MEMORY_DIVIDE = 0xD6,
    KEYPAD_PLUS_MINUS = 0xD7,
    KEYPAD_CLEAR = 0xD8,
    KEYPAD_CLEAR_ENTRY = 0xD9,
    KEYPAD_BINARY = 0xDA,
    KEYPAD_OCTAL = 0xDB,
    KEYPAD_DECIMAL = 0xDC,
    KEYPAD_HEXADECIMAL = 0xDD,

    // -- 修饰键 (0xE0-0xE7) --
    LEFT_CTRL = 0xE0,
    LEFT_SHIFT = 0xE1,
    LEFT_ALT = 0xE2,
    LEFT_GUI = 0xE3,
    RIGHT_CTRL = 0xE4,
    RIGHT_SHIFT = 0xE5,
    RIGHT_ALT = 0xE6,
    RIGHT_GUI = 0xE7,

    // 保留键
    RESERVED_END = 0xFF,
};

namespace KeybrdStruct
{
    struct __PACKED InputReport
    {
        uint8_t report_id;
        uint8_t modifier_keys;
        uint8_t reserved;
        KeybrdKey keycode[6];
    };
    static_assert(sizeof(InputReport) == 9, "Expected size error");
}

namespace NKRO104KeybrdStruct
{
    struct __PACKED InputReport
    {
        uint8_t report_id;
        uint8_t modifier_keys;
        uint8_t reserved;
        uint8_t keys[13];
    };
    static_assert(sizeof(InputReport) == 16, "Expected size error");
}
