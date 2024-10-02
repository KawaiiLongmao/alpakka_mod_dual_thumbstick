// SPDX-License-Identifier: GPL-2.0-only
// Copyright (C) 2022, Input Labs Oy.

#include <tusb.h>
#include <device/usbd_pvt.h>
#include "xinput.h"
#include "tusb_config.h"
#include "logging.h"
#include "config.h"
#include "xbox1914.h"

const uint8_t ep_in[] = {DESCRIPTOR_ENDPOINT_XINPUT_IN};
const uint8_t ep_out[] = {DESCRIPTOR_ENDPOINT_XINPUT_OUT};

const uint8_t xbox1914_ep_in2[] = {XBOX_1914_ENDPOINT_DESCRIPTOR_0_1_IN2};
const uint8_t xbox1914_ep_out2[] = {XBOX_1914_ENDPOINT_DESCRIPTOR_0_1_OUT2};
const uint8_t xbox1914_ep_in3[] = {XBOX_1914_ENDPOINT_DESCRIPTOR_1_1_IN3};
const uint8_t xbox1914_ep_out3[] = {XBOX_1914_ENDPOINT_DESCRIPTOR_1_1_OUT3};
const uint8_t xbox1914_ep_in4[] = {XBOX_1914_ENDPOINT_DESCRIPTOR_2_1_IN4};
const uint8_t xbox1914_ep_out4[] = {XBOX_1914_ENDPOINT_DESCRIPTOR_2_1_OUT4};
const uint8_t xbox1914_addr_in2 = 0x82;

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
    if (config_get_protocol() == PROTOCOL_XUSB_WIN || config_get_protocol() == PROTOCOL_XUSB_UNIX)
    {
        if (itf_desc->iInterface == 0)
        {
            usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)ep_in);
            usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)ep_out);
            return (
                sizeof(tusb_desc_interface_t) +
                16 +
                (sizeof(tusb_desc_endpoint_t) * 2));
        }
    }
    else if (config_get_protocol() == PROTOCOL_XBOX_1914)
    {
        if (itf_desc->bInterfaceNumber == XBOX_1914_ITF_0)
        {
            usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)xbox1914_ep_in2);
            usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)xbox1914_ep_out2);
            return (
                sizeof(tusb_desc_interface_t) +
                // 16 +
                (sizeof(tusb_desc_endpoint_t) * 2));
        }
        if (itf_desc->bInterfaceNumber == XBOX_1914_ITF_1)
        {
            if (itf_desc->bAlternateSetting == 0)
                return sizeof(tusb_desc_interface_t);
            if (itf_desc->bAlternateSetting == 1)
            {
                usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)xbox1914_ep_in3);
                usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)xbox1914_ep_out3);
                return (
                    sizeof(tusb_desc_interface_t) +
                    // 16 +
                    (sizeof(tusb_desc_endpoint_t) * 2));
            }
        }
        if (itf_desc->bInterfaceNumber == XBOX_1914_ITF_2)
        {
            if (itf_desc->bAlternateSetting == 0)
                return sizeof(tusb_desc_interface_t);
            if (itf_desc->bAlternateSetting == 1)
            {
                usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)xbox1914_ep_in4);
                usbd_edpt_open(rhport, (tusb_desc_endpoint_t const *)xbox1914_ep_out4);
                return (
                    sizeof(tusb_desc_interface_t) +
                    // 16 +
                    (sizeof(tusb_desc_endpoint_t) * 2));
            }
        }
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

void xinput_send_report(xinput_report *report)
{
    if (config_get_protocol() == PROTOCOL_XUSB_WIN || config_get_protocol() == PROTOCOL_XUSB_UNIX)
    {
        if (!usbd_edpt_busy(0, ADDR_XINPUT_IN))
        {
            usbd_edpt_claim(0, ADDR_XINPUT_IN);
            usbd_edpt_xfer(0, ADDR_XINPUT_IN, (uint8_t *)report, XINPUT_REPORT_SIZE);
            usbd_edpt_release(0, ADDR_XINPUT_IN);
        }
    }
    else if (config_get_protocol() == PROTOCOL_XBOX_1914)
    {
        if (!usbd_edpt_busy(0, xbox1914_addr_in2))
        {
            usbd_edpt_claim(0, xbox1914_addr_in2);
            usbd_edpt_xfer(0, xbox1914_addr_in2, (uint8_t *)report, XINPUT_REPORT_SIZE);
            usbd_edpt_release(0, xbox1914_addr_in2);
        }
    }
}

// void xinput_receive_report() {
//     uint8_t addr = ((tusb_desc_endpoint_t *)ep_out)->bEndpointAddress;
//     uint8_t buffer[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//     usbd_edpt_claim(0, addr);
//     usbd_edpt_xfer(0, addr, buffer, 8);
//     usbd_edpt_release(0, addr);
//     printf(
//         "BUF %i %i %i %i %i %i %i %i\n",
//         buffer[0],
//         buffer[1],
//         buffer[2],
//         buffer[3],
//         buffer[4],
//         buffer[5],
//         buffer[6],
//         buffer[7]
//     );
// }
