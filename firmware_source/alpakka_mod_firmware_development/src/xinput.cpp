// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2022, Input Labs Oy.

#include <tusb.h>
#include <device/usbd_pvt.h>
#include "xinput.h"
#include "tusb_config.h"
#include "logging.h"

#include "HID/HidDeviceInfo/XusbStruct.h"
#include "Rumble.h"

const uint8_t ep_in[] = {DESCRIPTOR_ENDPOINT_XINPUT_IN};
const uint8_t ep_out[] = {DESCRIPTOR_ENDPOINT_XINPUT_OUT};

static void xinput_init(void) {}

static void xinput_reset(uint8_t rhport) {}

static uint16_t xinput_open(
    uint8_t rhport,
    tusb_desc_interface_t const *itf_desc,
    uint16_t max_len)
{
    debug_uart(
        "USB: xinput_open rhport=%i itf=0x%x max_len=%i\n",
        rhport,
        itf_desc->iInterface,
        max_len);
    if (itf_desc->iInterface == 0)
    {
        usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)ep_in);
        usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)ep_out);
        return (
            sizeof(tusb_desc_interface_t) +
            16 +
            (sizeof(tusb_desc_endpoint_t) * 2));
    }
    return 0;
}

static bool xinput_control_xfer_cb(
    uint8_t rhport,
    uint8_t stage,
    tusb_control_request_t const *request)
{
    // printf("xinput_control_xfer_cb\n");
    return true;
}

static bool xinput_xfer_cb(
    uint8_t rhport,
    uint8_t ep_addr,
    xfer_result_t result,
    uint32_t xferred_bytes)
{
    // printf("xinput_xfer_cb\n");
    return true;
}

static usbd_class_driver_t const xinput_driver = {
    .init = xinput_init,
    .reset = xinput_reset,
    .open = xinput_open,
    .control_xfer_cb = xinput_control_xfer_cb,
    .xfer_cb = xinput_xfer_cb,
    .sof = NULL};

usbd_class_driver_t const *usbd_app_driver_get_cb(uint8_t *driver_count)
{
    *driver_count = 1;
    return &xinput_driver;
}

bool xinput_send_report(XInputReport *report)
{
    bool result = false;
    if (!usbd_edpt_busy(0, ADDR_XINPUT_IN))
    {
        usbd_edpt_claim(0, ADDR_XINPUT_IN);
        result = usbd_edpt_xfer(0, ADDR_XINPUT_IN, (uint8_t *)report, XINPUT_REPORT_SIZE);
        usbd_edpt_release(0, ADDR_XINPUT_IN);
    }
    return result;
}

void Handle_Xusb_OutputReport(const void *report_buffer)
{
    auto &report = *static_cast<const XusbStruct::OutputReport *>(report_buffer);
    switch (report.report_id)
    {
    case XusbStruct::OutputReportID::RUMBLE:
    {
        const float l_duty = report.left_motor / 100.f;
        HAL_PWM::SetDutyCompareCount(PIN_L, l_duty * 255);
        const float r_duty = report.right_motor / 100.f;
        HAL_PWM::SetDutyCompareCount(PIN_R, r_duty * 255);
        break;
    }
    case XusbStruct::OutputReportID::LED:
        //     m_led_state = report.led_state;
        break;
    default:
        break;
    }
}

void xinput_receive_report()
{
    static uint8_t out_report[32] = {};
    static uint8_t buffer[32] = {};
    if (!usbd_edpt_busy(0, ADDR_XINPUT_OUT))
    {
        usbd_edpt_claim(0, ADDR_XINPUT_OUT);
        usbd_edpt_xfer(0, ADDR_XINPUT_OUT, (uint8_t *)buffer, 32);
        usbd_edpt_release(0, ADDR_XINPUT_OUT);
    }
    if (memcmp(out_report, buffer, sizeof(XusbStruct::OutputReport)) != 0)
    {
        memcpy(out_report, buffer, sizeof(XusbStruct::OutputReport));
        Handle_Xusb_OutputReport(out_report);
    }
}
