// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2022, Input Labs Oy.

#include <tusb_config.h>
#include <tusb.h>
#include "config.h"
#include "logging.h"
#include "pnp_id.h"
#include "generic.h"
#include "keybrd.h"
#include "mouse.h"
#include "switch_pro.h"
#include "xbox1914.h"
#include "dual_shock_4.h"
#include "dual_sense.h"
#include "util.h"

/* ------------------------------ */
/* String Descriptor: */
/* ------------------------------ */

static const char *const descriptor_string_123[] = {
    (const char[]){0x09, 0x04}, // English.
    STRING_VENDOR,
    STRING_PRODUCT,
    STRING_DEVICE_VERSION,
    STRING_HID,
    STRING_WEBUSB,
    STRING_XINPUT,
};

static const char *const descriptor_string_switch_pro[] = {
    SWITCH_PRO_STRING_DESCRIPTOR,
    STRING_WEBUSB,
};

static const char *const descriptor_string_xbox1914[] = {
    XBOX_1914_STRING_DESCRIPTOR,
    STRING_HID,
    STRING_WEBUSB,
};

static const char *const descriptor_string_dual_shock_4[] = {
    DUAL_SHOCK_4_STRING_DESCRIPTOR,
    STRING_WEBUSB,
};

static const char *const descriptor_string_dual_sense[] = {
    DUAL_SENSE_STRING_DESCRIPTOR,
    STRING_WEBUSB,
};

/* ------------------------------ */
/* HID Report Descriptor: */
/* ------------------------------ */

uint8_t const descriptor_report_xusb[] = {
    KEYBRD_REPORT_MAP_COMPATIBLE,
    CUSTOM_MOUSE_REPORT_MAP,
};

uint8_t const descriptor_report_generic[] = {
    KEYBRD_REPORT_MAP_COMPATIBLE,
    CUSTOM_MOUSE_REPORT_MAP,
    GENERIC_REPORT_MAP,
};

uint8_t const descriptor_report_switch_pro[] = {
    // KEYBRD_REPORT_MAP_COMPATIBLE,
    // CUSTOM_MOUSE_REPORT_MAP,
    SWITCH_PRO_USB_REPORT_MAP,
};

uint8_t const descriptor_report_xbox1914[] = {
    KEYBRD_REPORT_MAP_COMPATIBLE,
    CUSTOM_MOUSE_REPORT_MAP,
    // XBOX_1914_BT_REPORT_MAP,
};

uint8_t const descriptor_report_dual_shock_4[] = {
    KEYBRD_REPORT_MAP_COMPATIBLE,
    CUSTOM_MOUSE_REPORT_MAP,
    DUAL_SHOCK_4_2X_USB_REPORT_MAP,
};

uint8_t const descriptor_report_dual_sense[] = {
    KEYBRD_REPORT_MAP_COMPATIBLE,
    CUSTOM_MOUSE_REPORT_MAP,
    DUAL_SENSE_USB_REPORT_MAP,
};

/* ------------------------------ */
/* Configuration Descriptor: */
/* ------------------------------ */

uint8_t descriptor_configuration_xusb[] = {
    DESCRIPTOR_CONFIGURATION(3),
    DESCRIPTOR_INTERFACE_HID(sizeof(descriptor_report_xusb)),
    DESCRIPTOR_INTERFACE_WEBUSB,
    DESCRIPTOR_INTERFACE_XUSB};

uint8_t descriptor_configuration_generic[] = {
    DESCRIPTOR_CONFIGURATION(2),
    DESCRIPTOR_INTERFACE_HID(sizeof(descriptor_report_generic)),
    DESCRIPTOR_INTERFACE_WEBUSB};

uint8_t descriptor_configuration_switch_pro[] = {
    // DESCRIPTOR_CONFIGURATION(1),
    // DESCRIPTOR_INTERFACE_HID(sizeof(descriptor_report_switch_pro)),
    // DESCRIPTOR_INTERFACE_WEBUSB
    SWITCH_PRO_CONFIGURATION_DESCRIPTOR,
    SWITCH_PRO_INTERFACE_DESCRIPTOR,
    SWITCH_PRO_HID_DESCRIPTOR(sizeof(descriptor_report_switch_pro)),
    SWITCH_PRO_ENDPOINT_DESCRIPTOR_IN1,
    SWITCH_PRO_ENDPOINT_DESCRIPTOR_OUT1,
};

uint8_t descriptor_configuration_xbox1914[] = {
    // DESCRIPTOR_CONFIGURATION(1),
    // DESCRIPTOR_INTERFACE_HID(sizeof(descriptor_report_xbox1914)),
    // DESCRIPTOR_INTERFACE_WEBUSB,
    XBOX_1914_CONFIGURATION_DESCRIPTOR,
    XBOX_1914_INTERFACE_DESCRIPTOR_0_0,
    XBOX_1914_ENDPOINT_DESCRIPTOR_0_0_OUT2,
    XBOX_1914_ENDPOINT_DESCRIPTOR_0_0_IN2,

    XBOX_1914_INTERFACE_DESCRIPTOR_0_1,
    XBOX_1914_ENDPOINT_DESCRIPTOR_0_1_OUT2,
    XBOX_1914_ENDPOINT_DESCRIPTOR_0_1_IN2,

    XBOX_1914_INTERFACE_DESCRIPTOR_1_0,
    XBOX_1914_INTERFACE_DESCRIPTOR_1_1,
    XBOX_1914_ENDPOINT_DESCRIPTOR_1_1_OUT3,
    XBOX_1914_ENDPOINT_DESCRIPTOR_1_1_IN3,

    XBOX_1914_INTERFACE_DESCRIPTOR_2_0,
    XBOX_1914_INTERFACE_DESCRIPTOR_2_1,
    XBOX_1914_ENDPOINT_DESCRIPTOR_2_1_OUT4,
    XBOX_1914_ENDPOINT_DESCRIPTOR_2_1_IN4,
};

uint8_t descriptor_configuration_dual_shock_4[] = {
    DESCRIPTOR_CONFIGURATION(1),
    DUAL_SHOCK_4_INTERFACE_DESCRIPTOR_3_0,
    DUAL_SHOCK_4_HID_DESCRIPTOR(sizeof(descriptor_report_dual_shock_4)),
    DUAL_SHOCK_4_ENDPOINT_DESCRIPTOR_IN4,
    DUAL_SHOCK_4_ENDPOINT_DESCRIPTOR_OUT3,
    // DESCRIPTOR_INTERFACE_WEBUSB,
};

uint8_t descriptor_configuration_dual_sense[] = {
    DESCRIPTOR_CONFIGURATION(1),
    DUAL_SENSE_INTERFACE_DESCRIPTOR_3_0,
    DUAL_SENSE_HID_DESCRIPTOR(sizeof(descriptor_report_dual_sense)),
    DUAL_SENSE_ENDPOINT_DESCRIPTOR_IN4,
    DUAL_SENSE_ENDPOINT_DESCRIPTOR_OUT3,
    // DESCRIPTOR_INTERFACE_WEBUSB,
};

uint8_t const *tud_descriptor_device_cb()
{
    debug_uart("USB: tud_descriptor_device_cb\n");
    static tusb_desc_device_t descriptor_device = {DESCRIPTOR_DEVICE};
    if (config_get_protocol() == PROTOCOL_XUSB_WIN)
    {
        descriptor_device.idVendor = USB_WIN_VENDOR;
        descriptor_device.idProduct = USB_WIN_PRODUCT;
        return (uint8_t const *)&descriptor_device;
    }
    else if (config_get_protocol() == PROTOCOL_XUSB_UNIX)
    {
        descriptor_device.idVendor = MICROSOFT_VID;
        descriptor_device.idProduct = XBOX_360_PID;
        return (uint8_t const *)&descriptor_device;
    }
    else if (config_get_protocol() == PROTOCOL_GENERIC)
    {
        descriptor_device.idVendor = USB_GENERIC_VENDOR;
        descriptor_device.idProduct = USB_GENERIC_PRODUCT;
        return (uint8_t const *)&descriptor_device;
    }

    if (config_get_protocol() == PROTOCOL_SWITCH_PRO)
    {
        static tusb_desc_device_t device_descriptor_1 = {SWITCH_PRO_DEVICE_DESCRIPTOR};
        // device_descriptor_1.idVendor = NINTENDO_VID;
        // device_descriptor_1.idProduct = NS_PRO_PID;
        return (uint8_t const *)&device_descriptor_1;
    }
    else if (config_get_protocol() == PROTOCOL_XBOX_1914)
    {
        static tusb_desc_device_t device_descriptor_1 = {XBOX_1914_DEVICE_DESCRIPTOR};
        // device_descriptor_1.idVendor = MICROSOFT_VID;
        // device_descriptor_1.idProduct = XBOX_SERIES_X_PID;
        return (uint8_t const *)&device_descriptor_1;
    }
    else if (config_get_protocol() == PROTOCOL_DUAL_SHOCK_4)
    {
        static tusb_desc_device_t device_descriptor_1 = {DUAL_SHOCK_4_DEVICE_DESCRIPTOR};
        // device_descriptor_1.idVendor = SONY_VID;
        // device_descriptor_1.idProduct = DUAL_SHOCK_4_2x_PID;
        return (uint8_t const *)&device_descriptor_1;
    }
    else if (config_get_protocol() == PROTOCOL_DUAL_SENSE)
    {
        static tusb_desc_device_t device_descriptor_1 = {DUAL_SENSE_DEVICE_DESCRIPTOR};
        // device_descriptor_1.idVendor = SONY_VID;
        // device_descriptor_1.idProduct = DUAL_SENSE_PID;
        return (uint8_t const *)&device_descriptor_1;
    }
}

uint8_t const *tud_descriptor_configuration_cb(uint8_t index)
{
    debug_uart("USB: tud_descriptor_configuration_cb index=0x%x\n", index);
    if (config_get_protocol() == PROTOCOL_GENERIC)
    {
        descriptor_configuration_generic[2] = sizeof(descriptor_configuration_generic);
        return descriptor_configuration_generic;
    }
    else if (config_get_protocol() == PROTOCOL_SWITCH_PRO)
    {
        descriptor_configuration_switch_pro[2] = sizeof(descriptor_configuration_switch_pro);
        return descriptor_configuration_switch_pro;
    }
    else if (config_get_protocol() == PROTOCOL_XBOX_1914)
    {
        descriptor_configuration_xbox1914[2] = sizeof(descriptor_configuration_xbox1914);
        return descriptor_configuration_xbox1914;
    }
    else if (config_get_protocol() == PROTOCOL_DUAL_SHOCK_4)
    {
        descriptor_configuration_dual_shock_4[2] = sizeof(descriptor_configuration_dual_shock_4);
        return descriptor_configuration_dual_shock_4;
    }
    else if (config_get_protocol() == PROTOCOL_DUAL_SENSE)
    {
        descriptor_configuration_dual_sense[2] = sizeof(descriptor_configuration_dual_sense);
        return descriptor_configuration_dual_sense;
    }
    else
    {
        descriptor_configuration_xusb[2] = sizeof(descriptor_configuration_xusb);
        return descriptor_configuration_xusb;
    }
}

uint8_t const *tud_hid_descriptor_report_cb(uint8_t instance)
{
    debug_uart("USB: tud_hid_descriptor_report_cb\n");
    if (config_get_protocol() == PROTOCOL_GENERIC)
        return descriptor_report_generic;
    else if (config_get_protocol() == PROTOCOL_SWITCH_PRO)
        return descriptor_report_switch_pro;
    else if (config_get_protocol() == PROTOCOL_XBOX_1914)
        return descriptor_report_xbox1914;
    else if (config_get_protocol() == PROTOCOL_DUAL_SHOCK_4)
        return descriptor_report_dual_shock_4;
    else if (config_get_protocol() == PROTOCOL_DUAL_SENSE)
        return descriptor_report_dual_sense;
    else
        return descriptor_report_xusb;
}

const uint16_t *tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    debug_uart("USB: tud_descriptor_string_cb index=0x%x\n", index);
    if (index == 0xEE)
    {
        if (config_get_protocol() == PROTOCOL_XUSB_WIN || config_get_protocol() == PROTOCOL_GENERIC)
        {
            static uint8_t msos[] = {MS_OS_DESCRIPTOR};
            return (uint16_t *)msos;
        }
        if (config_get_protocol() == PROTOCOL_XBOX_1914)
        {
            static uint8_t msos[] = {XBOX_1914_OS_DESCRIPTOR};
            return (uint16_t *)msos;
        }
    }
    static uint16_t response[64];
    const char *string;
    if (config_get_protocol() == PROTOCOL_XUSB_WIN || config_get_protocol() == PROTOCOL_XUSB_UNIX || config_get_protocol() == PROTOCOL_GENERIC)
    {
        if (index >= sizeof(descriptor_string_123) / sizeof(descriptor_string_123[0]))
        {
            return NULL;
        }
        string = descriptor_string_123[index];
    }
    else if (config_get_protocol() == PROTOCOL_SWITCH_PRO)
    {
        if (index >= sizeof(descriptor_string_switch_pro) / sizeof(descriptor_string_switch_pro[0]))
        {
            return NULL;
        }
        string = descriptor_string_switch_pro[index];
    }
    else if (config_get_protocol() == PROTOCOL_XBOX_1914)
    {
        if (index >= sizeof(descriptor_string_xbox1914) / sizeof(descriptor_string_xbox1914[0]))
        {
            return NULL;
        }
        string = descriptor_string_xbox1914[index];
    }
    else if (config_get_protocol() == PROTOCOL_DUAL_SHOCK_4)
    {
        if (index >= sizeof(descriptor_string_dual_shock_4) / sizeof(descriptor_string_dual_shock_4[0]))
        {
            return NULL;
        }
        string = descriptor_string_dual_shock_4[index];
    }
    else if (config_get_protocol() == PROTOCOL_DUAL_SENSE)
    {
        if (index >= sizeof(descriptor_string_dual_sense) / sizeof(descriptor_string_dual_sense[0]))
        {
            return NULL;
        }
        string = descriptor_string_dual_sense[index];
    }
    uint8_t i = 0;
    for (i; string[i]; i++)
    {
        response[i + 1] = string[i];
    }
    response[0] = TUSB_DESC_STRING << 8; // String type.
    response[0] |= (i * 2) + 2;          // Total length.
    return response;
}

const bool tud_vendor_control_xfer_cb(
    uint8_t rhport,
    uint8_t stage,
    tusb_control_request_t const *request)
{
    debug_uart(
        "USB: tud_vendor_control_xfer_cb stage=%i wIndex=0x%x\n",
        stage,
        request->wIndex);
    if (stage != CONTROL_STAGE_SETUP)
        return true;
    // Compatibility IDs.
    if (request->wIndex == 0x0004)
    {
        if (request->bRequest == MS_OS_VENDOR)
        {
            if (config_get_protocol() == PROTOCOL_XUSB_WIN)
            {
                static uint8_t response[] = {MS_OS_COMPATIDS_ALL};
                return tud_control_xfer(rhport, request, response, sizeof(response));
            }
            if (config_get_protocol() == PROTOCOL_GENERIC)
            {
                static uint8_t response[] = {MS_OS_COMPATIDS_GENERIC};
                return tud_control_xfer(rhport, request, response, sizeof(response));
            }
        }
        // if (request->bRequest == XBOX_1914_OS_VENDOR)
        // {
        //     if (config_get_protocol() == PROTOCOL_XBOX_1914)
        //     {
        //         static uint8_t response[] = {
        //             MS_OS_COMPATIDS(40, 1),
        //             MS_OS_COMPATIDS_XUSB(XBOX_1914_ITF_0),
        //             // MS_OS_COMPATIDS_XUSB(XBOX_1914_ITF_1),
        //             // MS_OS_COMPATIDS_XUSB(XBOX_1914_ITF_2),
        //         };
        //         return tud_control_xfer(rhport, request, response, sizeof(response));
        //     }
        // }
    }
    // Extended properties.
    if (
        request->wIndex == 0x0005 &&
        request->bRequest == MS_OS_VENDOR /* &&
        config_get_protocol() != PROTOCOL_XUSB_UNIX */
    )
    {
        if (config_get_protocol() == PROTOCOL_XUSB_WIN || config_get_protocol() == PROTOCOL_GENERIC)
        {
            static uint8_t response[] = {MS_OS_PROPERTIES};
            return tud_control_xfer(rhport, request, response, sizeof(response));
        }
    }
    // Return false if there is no control data to transfer.
    return false;
}

uint16_t tud_hid_get_report_cb(
    uint8_t instance,
    uint8_t report_id,
    hid_report_type_t report_type,
    uint8_t *buffer,
    uint16_t reqlen)
{
    // if (config_get_protocol() == PROTOCOL_SWITCH_PRO)
    // {
    //     output_report_t *output_report = (output_report_t *)buffer;
    //     output_report.subcmdReply = 0x80;
    //     output_report.subcmdReplyID = subcmdPacket->subcmd;
    //     output_report.data[0] = 0x03;
    // }
    if (config_get_protocol() == PROTOCOL_DUAL_SENSE)
    {
        if (report_id == DUAL_SENSE_USB_REPORT_FEATURE_ID05)
        {
            struct DualSense_ReportFeatureInCalibrateBT report = {0};
            return memory_copy(buffer, &report, sizeof(report));
            // return sizeof(report);
        }
        if (report_id == DUAL_SENSE_USB_REPORT_FEATURE_ID09)
        {
            struct DualSense_ReportFeatureInMacAll report = {0};
            return memory_copy(buffer, &report, sizeof(report));
        }
        if (report_id == DUAL_SENSE_USB_REPORT_FEATURE_ID20)
        {
            struct DualSense_ReportFeatureInVersion report = {0};
            report.HardwareInfo = 0x0000FF00;
            report.UpdateVersion = 0x0458;
            return memory_copy(buffer, &report, sizeof(report));
        }
    }
    return 0;
}

void tud_hid_set_report_cb(
    uint8_t instance,
    uint8_t report_id,
    hid_report_type_t report_type,
    uint8_t const *buffer,
    uint16_t bufsize)
{
    if (config_get_protocol() == PROTOCOL_SWITCH_PRO)
    {
        uint8_t hid_rx_buffer[64] = {0};
        hid_rx_buffer[0] = report_id;
        memcpy(&hid_rx_buffer[1], buffer, bufsize);
        hid_switch_pro_report(hid_rx_buffer, bufsize);
    }
}

void tud_mount_cb(void)
{
    debug_uart("USB: tud_mount_cb\n");
}

void tud_umount_cb(void)
{
    debug_uart("USB: tud_umount_cb\n");
}

void tud_suspend_cb(bool remote_wakeup_en)
{
    debug_uart("USB: tud_suspend_cb\n");
}

void tud_resume_cb(void)
{
    debug_uart("USB: tud_resume_cb\n");
}

void wait_for_usb_init()
{
    while (true)
    {
        tud_task();
        if (tud_ready())
            break;
        else
            sleep_ms(1);
    }
    debug_uart("USB: Ready\n");
}
