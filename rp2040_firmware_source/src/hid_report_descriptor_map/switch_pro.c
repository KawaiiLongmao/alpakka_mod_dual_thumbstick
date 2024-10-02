#include <stdint.h>
#include <math.h>
#include <string.h>
#include "switch_pro.h"
#include "joystick.h"

// 0.0~1.0
float calcRumbleAmp(const rumble_data_t *rumble)
{
    if (rumble->freq_h == 0 && rumble->freq_h_amp == 0x01 && rumble->freq_l == 0x40 && rumble->freq_l_amp == 0x40)
        return 0;

    // ESP_LOGI(TAG, "Rumble %02x %02x %02x %02x", rumble->freq_h, rumble->freq_h_amp, rumble->freq_l, rumble->freq_l_amp);
    // 老外的逆向工程文档看不懂，直接用excel表拟合他提供是数据表格
    float a; // 0.0~1.0
    uint8_t ea = rumble->freq_h_amp >> 1;
    if (ea <= 1)
        a = 0.007843f * ea;
    else if (ea <= 14)
        a = 0.0084f * exp(0.1733f * ea);
    else if (ea <= 30)
        a = 0.0587f * exp(0.0433f * ea);
    else
        a = 0.115f * exp(0.0217f * ea);

    // 频率用不上直接注释掉
    // float f;
    // if (rumble->freq_h_amp & 0x01)
    // 	f = 320 * exp(0.0054f * rumble->freq_h);
    // else
    // 	f = 40 * exp(0.0217f * (rumble->freq_l & 0x7F));

    return a;
}

static uint8_t tick = 0;
static void fill_input_report(SwitchProUsb *self, struct ControllerData *controller_data)
{
    /*
    unsigned char rawData[12] = {
        0x83, 0x71, 0x00, 0x80, 0x00, 0xBA, 0x07, 0x6B, 0x47, 0xF7, 0x72, 0x0C};
        */
    uint8_t *switch_pro_gamepad_data = (uint8_t *)&self->gamepad_data;
    memcpy(controller_data, &switch_pro_gamepad_data[1], sizeof(struct ControllerData));

    controller_data->timestamp = tick;
    controller_data->battery_level = /*battery_level_charging | */ BATT_FULL;
    controller_data->connection_info = /* 0xe; */ 0x1;
    controller_data->vibrator_input_report = 0x07;

    tick += 3;
}

static void output_report_0x01_bt_pairing(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    const uint8_t data_01[] = {
        0x21, 0xf6, 0x81, 0x00, 0x80, 0x00, 0x8f, 0xf8, 0x7a, 0x54, 0x58, 0x78, 0x00, 0x81, 0x01, 0x01, /* !.......zTXx.... */
        0xc1, 0xc9, 0x3e, 0xe9, 0xb6, 0x98, 0x00, 0x25, 0x08, 0x50, 0x72, 0x6f, 0x20, 0x43, 0x6f, 0x6e, /* ..>....%.Pro Con */
        0x74, 0x72, 0x6f, 0x6c, 0x6c, 0x65, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, /* troller......h.. */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ................ */
    };

    const uint8_t data_02[] = {
        0x21, 0xfd, 0x81, 0x00, 0x80, 0x00, 0x90, 0xe8, 0x7a, 0x53, 0x58, 0x78, 0x00, 0x81, 0x01, 0x02, /* !.......zSXx.... */
        0xe5, 0xc8, 0xe4, 0x92, 0x05, 0xff, 0xc9, 0x8a, 0x7d, 0xea, 0x15, 0xf6, 0x19, 0xba, 0x82, 0x13, /* ........}....... */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ................ */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    const uint8_t data_03[] = {
        0x21,
        0x05,
        0x81,
        0x00,
        0x80,
        0x00,
        0x90,
        0xc8,
        0x7a,
        0x53,
        0x58,
        0x78,
        0x00,
        0x81,
        0x01,
        0x03, /* !.......zSXx.... */
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00, /* ................ */
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00, /* ................ */
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
    };

    uint8_t pairing_type = hid_rx_buffer[11] /* data->pairing.type */;
    char dbg[0x40] = {};
    // sprintf(dbg, "pairing_type 0x%02x", pairing_type);
    // usart_send_str(dbg);

    uint8_t *data = (uint8_t *)data_01;
    switch (pairing_type)
    {
    case 1:
        data = (uint8_t *)data_01;
        break;
    case 2:
        data = (uint8_t *)data_02;
        break;
    default:
    case 3:
        data = (uint8_t *)data_03;
        break;
    }
    memcpy(self->hid_report_buffer, data, 0x40);
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

// Subcommand 0x02: Request device info
static void output_report_0x01_get_device_info(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    unsigned char rawData[64] = {
        0x21, 0xf8, 0x81, 0x00, 0x80, 0x00, 0x8f, 0xf8, 0x7a, 0x53, 0x78, 0x78, 0x00, 0x82, 0x02, 0x03, /* !.......zSxx.... */
        0x48, 0x03, 0x02, 0x98, 0xb6, 0xe9, 0x3e, 0xc9, 0xc1, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, /* H.....>......... */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ................ */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ................ */
    };

    memcpy(self->hid_report_buffer, rawData, 0x40);
    // struct Report81Response *resp = (struct Report81Response *)&usb_out_buf[0x01];
    // fill_input_report(&resp->controller_data);

    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

// Subcommand 0x03: Set input report mode
/* todo */
static void output_report_0x01_set_report_mode(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    struct Report81Response *resp = (struct Report81Response *)&self->hid_report_buffer[0x01];
    // report ID
    self->hid_report_buffer[0x00] = SWITCH_PRO_USB_INPUT_ID_SUBCOMMAND_REPLY;

    // acknowledge
    resp->subcommand_ack = 0x80;
    resp->subcommand = 0x03;

    fill_input_report(self, &resp->controller_data);

    self->joyStickMode = hid_rx_buffer[11];

    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

// Subcommand 0x04: Trigger buttons elapsed time
/* todo */
static void output_report_0x01_trigger_elapsed(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    struct Report81Response *resp = (struct Report81Response *)&self->hid_report_buffer[0x01];
    // report ID
    self->hid_report_buffer[0x00] = SWITCH_PRO_USB_INPUT_ID_SUBCOMMAND_REPLY;

    // acknowledge
    resp->subcommand_ack = 0x83;
    resp->subcommand = 0x04;

    fill_input_report(self, &resp->controller_data);
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);

    // ba
    const uint8_t resp_[] = {
        0x21, 0x0A, 0x8E, 0x84, 0x00, 0x12, 0x01, 0x18, 0x80, 0x01, 0x18, 0x80, 0x80,
        0x83, 0x04, 0x00, 0xCC, 0x00, 0xEE, 0x00, 0xFF, 0x00, 0x00, 0x00};

    memcpy(self->hid_report_buffer, resp_, sizeof(resp_));
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, sizeof(resp_));
    self->hid_report_open = true;
}

// Subcommand 0x08: Set shipment low power state
static void output_report_0x01_0x08_lowpower_state(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    unsigned char rawData[64] = {
        0x21,
        0x06,
        0x8E,
        0x84,
        0x00,
        0x12,
        0x01,
        0x18,
        0x80,
        0x01,
        0x18,
        0x80,
        0x80,
        0x80,
        0x08,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
    };
    static int iii = 0;
    rawData[0x01] = iii++;
    memcpy(self->hid_report_buffer, rawData, sizeof(rawData));
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

/* todo */
static void output_report_0x01_readspi(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);

    struct SpiReadReport *resp = (struct SpiReadReport *)&self->hid_report_buffer[0x01];
    uint16_t addr = *(uint16_t *)(&hid_rx_buffer[kSubCommandDataOffset]);
    uint8_t len = hid_rx_buffer[kSubCommandDataOffset + 4];

    memset(self->hid_report_buffer, 0x00, 0x40);
    self->hid_report_buffer[0x00] = SWITCH_PRO_USB_INPUT_ID_SUBCOMMAND_REPLY;

    fill_input_report(self, &resp->controller_data);

    resp->subcommand_ack = 0x90;
    resp->subcommand = 0x10;
    resp->addr = addr;

    // spi_read(addr, len, resp->spi_data);

    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

/* todo */
static void output_report_0x01_writespi(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    struct ResponseX81 *resp = (struct ResponseX81 *)&self->hid_report_buffer[0x01];
    uint16_t addr = *(uint16_t *)(&hid_rx_buffer[kSubCommandDataOffset]);
    uint8_t len = hid_rx_buffer[kSubCommandDataOffset + 4];

    // report ID
    self->hid_report_buffer[0x00] = kReportIdInput21;
    fill_input_report(self, &resp->controller_data);

    // spi_write(addr, len, &buf[kSubCommandDataOffset + 5]);

    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

/* todo */
static void output_report_0x01_erasespi(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    struct ResponseX81 *resp = (struct ResponseX81 *)&self->hid_report_buffer[0x01];
    uint16_t addr = *(uint16_t *)(&hid_rx_buffer[kSubCommandDataOffset]);
    uint8_t len = hid_rx_buffer[kSubCommandDataOffset + 4];

    // report ID
    self->hid_report_buffer[0x00] = kReportIdInput21;
    fill_input_report(self, &resp->controller_data);
    // spi_erase(addr, len);
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

/* todo */
static void output_report_0x01_set_lights(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    struct ResponseX81 *resp = (struct ResponseX81 *)&self->hid_report_buffer[0x01];
    // report ID
    self->hid_report_buffer[0x00] = kReportIdInput21;
    fill_input_report(self, &resp->controller_data);
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

/* todo */
static void output_report_0x01_set_homelight(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    struct ResponseX81 *resp = (struct ResponseX81 *)&self->hid_report_buffer[0x01];
    // report ID
    self->hid_report_buffer[0x00] = kReportIdInput21;
    fill_input_report(self, &resp->controller_data);
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

/* todo */
static void output_report_0x01_set_immu(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    struct ResponseX81 *resp = (struct ResponseX81 *)&self->hid_report_buffer[0x01];
    // report ID
    self->hid_report_buffer[0x00] = kReportIdInput21;
    fill_input_report(self, &resp->controller_data);
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

/* todo */
static void output_report_0x01_set_immu_sensitivity(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    struct ResponseX81 *resp = (struct ResponseX81 *)&self->hid_report_buffer[0x01];
    // report ID
    self->hid_report_buffer[0x00] = kReportIdInput21;
    fill_input_report(self, &resp->controller_data);
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

/* todo */
static void output_report_0x01_set_vibration(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    struct ResponseX81 *resp = (struct ResponseX81 *)&self->hid_report_buffer[0x01];
    // report ID
    self->hid_report_buffer[0x00] = kReportIdInput21;

    resp->subcommand_ack = 0x80;
    resp->subcommand = 0x48;

    fill_input_report(self, &resp->controller_data);
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

static void output_report_0x01_unknown_subcmd(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str("output_report_0x01_unknown_subcmd");
    // char dbg[0x40] = {};
    // sprintf(dbg, "output_report_0x01_unknown_subcmd 0x%02x", buf[10]);
    // usart_send_str(dbg);

    struct Report81Response *resp = (struct Report81Response *)&self->hid_report_buffer[0x01];
    // report ID
    self->hid_report_buffer[0x00] = kReportIdInput21;
    fill_input_report(self, &resp->controller_data);
    resp->subcommand_ack = 0x80;
    resp->subcommand = hid_rx_buffer[10];
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

// Sub command !
static void output_report_0x01(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    uint8_t subCmd = hid_rx_buffer[10];

    switch (subCmd)
    {
    case 0x01:
        output_report_0x01_bt_pairing(self, hid_rx_buffer);
        break;
        // get device info
    case 0x02:
        output_report_0x01_get_device_info(self, hid_rx_buffer);
        break;
        // Set input report mode
    case 0x03:
        output_report_0x01_set_report_mode(self, hid_rx_buffer);
        break;
        // unknown ?
    case 0x04:
        output_report_0x01_trigger_elapsed(self, hid_rx_buffer);
        break;
        // unknown ?
    case 0x08:
        output_report_0x01_0x08_lowpower_state(self, hid_rx_buffer);
        break;
    // Read Spi
    case 0x10:
        output_report_0x01_readspi(self, hid_rx_buffer);
        break;
    case 0x11:
        output_report_0x01_writespi(self, hid_rx_buffer);
        break;
    case 0x12:
        output_report_0x01_erasespi(self, hid_rx_buffer);
        break;
    // Set Lights
    case 0x30:
        output_report_0x01_set_lights(self, hid_rx_buffer);
        break;
    // Set Home Light
    case 0x38:
        output_report_0x01_set_homelight(self, hid_rx_buffer);
        break;
    // Set Immu
    case 0x40:
        output_report_0x01_set_immu(self, hid_rx_buffer);
        break;
    // Set Immu Sensitivity
    case 0x41:
        output_report_0x01_set_immu_sensitivity(self, hid_rx_buffer);
        break;
    // Set Vibration
    case 0x48:
        output_report_0x01_set_vibration(self, hid_rx_buffer);
        break;

    case 0x00:
    case 0x33:
    default:
        output_report_0x01_unknown_subcmd(self, hid_rx_buffer);
        break;
    }
}

static void output_report_0x10(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    /** nothing **/
    // Joy-con does not reply when Output Report is 0x10
    // usart_send_str(__func__);

    // output_report_0x01_unknown_subcmd(self, hid_rx_buffer);
}

// 80 01
static void output_mac_addr(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    /*
    // Verified
    // hard coded response !!!
    const uint8_t response_h[] = {
        kUsbReportIdInput81, kSubTypeRequestMac, 0x00, kUsbDeviceTypeProController,
        mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]};
    memcpy(usb_out_buf, response_h, sizeof(response_h));
    usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    */
    const uint8_t response_h[] = {
        0x81, 0x01, 0x00, 0x03, 0xc1, 0xc9, 0x3e, 0xe9, 0xb6, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ......>......... */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ................ */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ................ */
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ................ */
    };
    memcpy(self->hid_report_buffer, response_h, sizeof(response_h));
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

// passthrough
// Verified
static void output_handshake(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    memset(self->hid_report_buffer, 0, 0x40);
    self->hid_report_buffer[0] = 0x81;
    self->hid_report_buffer[1] = kSubTypeHandshake;
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

// baudrate
// Verified
static void output_baudrate(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    memset(self->hid_report_buffer, 0, 0x40);
    self->hid_report_buffer[0] = 0x81;
    self->hid_report_buffer[1] = 0x03;
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

// baudrate
// Verified
static void output_enable_usb_timeout(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    memset(self->hid_report_buffer, 0, 0x40);
    self->hid_report_buffer[0] = 0x81;
    self->hid_report_buffer[1] = kSubTypeDisableUsbTimeout;
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

// baudrate
// Verified
static void output_disable_usb_timeout(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    memset(self->hid_report_buffer, 0, 0x40);
    self->hid_report_buffer[0] = 0x81;
    self->hid_report_buffer[1] = kSubTypeEnableUsbTimeout;
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

// passthrough
static void output_passthrough(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // char dbg[0x40] = {};
    // sprintf(dbg, "output_passthrough 0x%02x", hid_rx_buffer[1]);
    // usart_send_str(dbg);

    const uint8_t response_h[] = {0x81, hid_rx_buffer[1], 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    memcpy(self->hid_report_buffer, response_h, sizeof(response_h));
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;
}

static void output_report_0x80(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    switch (hid_rx_buffer[1])
    {
    case 0x01: // mac addr
        // hw_led_toggle();
        output_mac_addr(self, hid_rx_buffer);
        break;
        // handshake//baudrate
    case 0x02:
        output_handshake(self, hid_rx_buffer);
        break;
    case 0x03:
        output_baudrate(self, hid_rx_buffer);
        break;
    // usb timeout
    case 0x04:
        output_enable_usb_timeout(self, hid_rx_buffer);
        break;
    case 0x05:
        output_disable_usb_timeout(self, hid_rx_buffer);
        break;
    case 0x91:
    case 0x92:
        output_passthrough(self, hid_rx_buffer);
        break;
    default:
        output_passthrough(self, hid_rx_buffer);
        break;
    }
}

// Standard full mode - input reports with IMU data instead of subcommand replies. Pushes current state @60Hz, or @120Hz if Pro Controller.
static void input_report_0x30(SwitchProUsb *self, uint8_t *hid_rx_buffer)
{
    // usart_send_str(__func__);
    //  report ID
    self->hid_report_buffer[0x00] = kReportIdInput30;
    /*
    uint8_t p[] = {
        0x21, 0x09, 0x8E, 0x84, 0x00, 0x12, 0x01, 0x18, 0x80, 0x01, 0x18, 0x80, 0x80,
0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    memcpy(usb_out_buf, p, sizeof(p));
    */

    fill_input_report(self, (struct ControllerData *)&self->hid_report_buffer[0x01]);
    // usb_write_packet(ENDPOINT_HID_IN, usb_out_buf, 0x40);
    self->hid_report_open = true;

    // hw_led_toggle();
}

void SwitchProUsb__do_work(SwitchProUsb *self, uint8_t *hid_rx_buffer, uint8_t len)
{
    uint8_t cmd = hid_rx_buffer[0];
    memset(self->hid_report_buffer, 0, 0x40);
    self->hid_report_open = false;

    switch (cmd)
    {
    case SWITCH_PRO_USB_OUTPUT_ID_RUMBLE_AND_SUBCOMMAND:
        output_report_0x01(self, hid_rx_buffer);
        break;
    case SWITCH_PRO_USB_OUTPUT_ID_RUMBLE:
        output_report_0x10(self, hid_rx_buffer);
        break;

    case SWITCH_PRO_USB_OUTPUT_ID_PROPRIETARY:
        output_report_0x80(self, hid_rx_buffer);
        break;

    case SWITCH_PRO_USB_INPUT_ID_FULL_CONTROLLER_STATE:
        // default:
        input_report_0x30(self, hid_rx_buffer);
        break;
    }
}

static void SwitchProUsb__handle_input_0x30(SwitchProUsb *self)
{
    uint8_t usb_out_buf[0x40];
    if (self->joyStickMode == 0x30)
    {
        input_report_0x30(self, NULL);
    }
}

SwitchProUsb SwitchProUsb_()
{
    SwitchProUsb switchProUsb = {
        .do_work = SwitchProUsb__do_work,
        .handle_input_0x30 = SwitchProUsb__handle_input_0x30,
    };
    return switchProUsb;
}
