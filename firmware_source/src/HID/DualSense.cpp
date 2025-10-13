#include "DualSense.h"

#include "HID/HidDeviceInfo/Templates.h"
#include "HID/HidDeviceInfo/PNP_ID.h"
#include "HID/HidDeviceInfo/DualSenseDescriptor.h"
#include "HID/HidDeviceInfo/DualSenseStruct.h"
#include "usb_config.h"
#include "core/usbd_core.h"
#include "hid.h"
#include "HAL/Time.h"
#include "Rumble.h"

namespace
{
    constexpr uint16_t VID = SONY_VID;
    constexpr uint16_t PID = DUAL_SENSE_PID;

    uint16_t TimestampConvert(uint32_t timestamp_us)
    {
        // timestamp_us / 5.33
        uint64_t scaled_timestamp = static_cast<uint64_t>(timestamp_us) * 3;
        scaled_timestamp = (scaled_timestamp + 8) >> 4;
        return static_cast<uint16_t>(scaled_timestamp);
    }
} // namespace

namespace
{
    constexpr uint16_t USB_HID_CFG_DESC_LEN = 0x00E3;

    constexpr uint8_t USB_AC_ITF_IDX = DUAL_SENSE_USB_AC_ITF_NUM;
    constexpr uint8_t USB_AS_OUT_ITF_IDX = DUAL_SENSE_USB_AS_OUT_ITF_NUM;
    constexpr uint8_t USB_AS_IN_ITF_IDX = DUAL_SENSE_USB_AS_IN_ITF_NUM;
    constexpr uint8_t USB_AUDIO_OUT_EP_ADDR = DUAL_SENSE_USB_AUDIO_OUT_EP_ADDR;
    constexpr uint8_t USB_AUDIO_IN_EP_ADDR = DUAL_SENSE_USB_AUDIO_IN_EP_ADDR;
    constexpr uint16_t USB_AUDIO_OUT_PACKET_SIZE = DUAL_SENSE_USB_AUDIO_OUT_PACKET_SIZE;
    constexpr uint16_t USB_AUDIO_IN_PACKET_SIZE = DUAL_SENSE_USB_AUDIO_IN_PACKET_SIZE;
    constexpr uint8_t USB_AUDIO_OUT_FU_ID = DUAL_SENSE_USB_AUDIO_OUT_FEATURE_UNIT_ID;
    constexpr uint8_t USB_AUDIO_IN_FU_ID = DUAL_SENSE_USB_AUDIO_IN_FEATURE_UNIT_ID;

    // constexpr uint8_t USB_HID_ITF_IDX = DUAL_SENSE_USB_HID_ITF_NUM;
    constexpr uint8_t USB_HID_ITF_IDX = 0;
    constexpr uint8_t USB_HID_IN_EP_ADDR = DUAL_SENSE_USB_HID_IN_EP_ADDR;
    constexpr uint8_t USB_HID_OUT_EP_ADDR = DUAL_SENSE_USB_HID_OUT_EP_ADDR;
    constexpr uint8_t USB_HID_EP_SIZE = DUAL_SENSE_USB_HID_EP_SIZE;

    const uint8_t s_usb_hid_report_descriptor[] = {
        DUAL_SENSE_USB_HID_REPORT_DESCRIPTOR,
    };

    const uint8_t s_usb_device_descriptor[] = {
        TEMPLATES_USB_DEVICE_DESCRIPTOR(VID, PID, DEFAULT_BCD_DEVICE, false)};

    const uint8_t s_usb_config_descriptor_hs[] = {
        // TEMPLATES_USB_CONFIGURATION_DESCRIPTOR(USB_HID_CFG_DESC_LEN, 4, 0x01, 0xC0, 0xFA),
        // DUAL_SENSE_USB_CFG0_ITF0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_AC_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_SPK_AC_INPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_SPK_AC_FEATURE_UNIT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_SPK_AC_OUTPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_MIC_AC_INPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_MIC_AC_FEATURE_UNIT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_MIC_AC_OUTPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_AS_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_AS_FORMAT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_AUDIO_OUT_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_AS_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_AS_FORMAT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_AUDIO_IN_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF3_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF3_HID_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF3_IN_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF3_OUT_ENDPOINT_DESCRIPTOR,
        // TEMPLATES_USB_HID_DESCRIPTOR_INOUT(USB_HID_ITF_IDX, 0, 0, sizeof(s_usb_hid_report_descriptor), USB_HID_IN_EP_ADDR, USB_HID_OUT_EP_ADDR),
        TEMPLATES_USB_CONFIGURATION_DESCRIPTOR(41, 1, 0x01, 0xC0, 0xFA),
        TEMPLATES_USB_HID_DESCRIPTOR_INOUT(USB_HID_ITF_IDX, 0, 0, sizeof(s_usb_hid_report_descriptor), USB_HID_IN_EP_ADDR, USB_HID_OUT_EP_ADDR),
    };

    const uint8_t s_usb_config_descriptor_fs[] = {
        // TEMPLATES_USB_CONFIGURATION_DESCRIPTOR(USB_HID_CFG_DESC_LEN, 4, 0x01, 0xC0, 0xFA),
        // DUAL_SENSE_USB_CFG1_ITF0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_AC_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_SPK_AC_INPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_SPK_AC_FEATURE_UNIT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_SPK_AC_OUTPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_MIC_AC_INPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_MIC_AC_FEATURE_UNIT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_MIC_AC_OUTPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_AS_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_AS_FORMAT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_AUDIO_OUT_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_AS_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_AS_FORMAT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_AUDIO_IN_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF3_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF3_HID_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF3_IN_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF3_OUT_ENDPOINT_DESCRIPTOR,
        // TEMPLATES_USB_HID_DESCRIPTOR_INOUT(USB_HID_ITF_IDX, 0, 0, sizeof(s_usb_hid_report_descriptor), USB_HID_IN_EP_ADDR, USB_HID_OUT_EP_ADDR),
        TEMPLATES_USB_CONFIGURATION_DESCRIPTOR(41, 1, 0x01, 0xC0, 0xFA),
        TEMPLATES_USB_HID_DESCRIPTOR_INOUT(USB_HID_ITF_IDX, 0, 0, sizeof(s_usb_hid_report_descriptor), USB_HID_IN_EP_ADDR, USB_HID_OUT_EP_ADDR),
    };

    const uint8_t s_usb_device_quality_descriptor[] = {
        TEMPLATES_USB_DEVICE_QUALIFIER_DESCRIPTOR(USB_2_0, 0x00, 0x00, 0x00, 0x01)};

    const uint8_t s_usb_other_speed_config_descriptor_hs[] = {
        // TEMPLATES_USB_OTHER_SPEED_CONFIG_DESCRIPTOR(USB_HID_CFG_DESC_LEN, 4, 0x01, 0xC0, 0xFA),
        // DUAL_SENSE_USB_CFG1_ITF0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_AC_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_SPK_AC_INPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_SPK_AC_FEATURE_UNIT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_SPK_AC_OUTPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_MIC_AC_INPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_MIC_AC_FEATURE_UNIT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF0_MIC_AC_OUTPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_AS_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_AS_FORMAT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_AUDIO_OUT_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF1_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_AS_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_AS_FORMAT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_AUDIO_IN_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF2_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF3_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF3_HID_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF3_IN_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG1_ITF3_OUT_ENDPOINT_DESCRIPTOR,
        // TEMPLATES_USB_HID_DESCRIPTOR_INOUT(USB_HID_ITF_IDX, 0, 0, sizeof(s_usb_hid_report_descriptor), USB_HID_IN_EP_ADDR, USB_HID_OUT_EP_ADDR),
        TEMPLATES_USB_OTHER_SPEED_CONFIG_DESCRIPTOR(41, 1, 0x01, 0xC0, 0xFA),
        TEMPLATES_USB_HID_DESCRIPTOR_INOUT(USB_HID_ITF_IDX, 0, 0, sizeof(s_usb_hid_report_descriptor), USB_HID_IN_EP_ADDR, USB_HID_OUT_EP_ADDR),
    };

    const uint8_t s_usb_other_speed_config_descriptor_fs[] = {
        // TEMPLATES_USB_OTHER_SPEED_CONFIG_DESCRIPTOR(USB_HID_CFG_DESC_LEN, 4, 0x01, 0xC0, 0xFA),
        // DUAL_SENSE_USB_CFG0_ITF0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_AC_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_SPK_AC_INPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_SPK_AC_FEATURE_UNIT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_SPK_AC_OUTPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_MIC_AC_INPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_MIC_AC_FEATURE_UNIT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF0_MIC_AC_OUTPUT_TERMINAL_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_AS_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_AS_FORMAT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_AUDIO_OUT_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF1_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT0_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_AS_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_AS_FORMAT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_AUDIO_IN_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF2_ALT1_AS_ISOCHRONOUS_DATA_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF3_INTERFACE_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF3_HID_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF3_IN_ENDPOINT_DESCRIPTOR,
        // DUAL_SENSE_USB_CFG0_ITF3_OUT_ENDPOINT_DESCRIPTOR,
        // TEMPLATES_USB_HID_DESCRIPTOR_INOUT(USB_HID_ITF_IDX, 0, 0, sizeof(s_usb_hid_report_descriptor), USB_HID_IN_EP_ADDR, USB_HID_OUT_EP_ADDR),
        TEMPLATES_USB_OTHER_SPEED_CONFIG_DESCRIPTOR(41, 1, 0x01, 0xC0, 0xFA),
        TEMPLATES_USB_HID_DESCRIPTOR_INOUT(USB_HID_ITF_IDX, 0, 0, sizeof(s_usb_hid_report_descriptor), USB_HID_IN_EP_ADDR, USB_HID_OUT_EP_ADDR),
    };

    const char *const s_usb_string_descriptor[] = {
        (const char[]){0x09, 0x04},
        "qghz",
        "DS",
    };

    const uint8_t *device_descriptor_callback(uint8_t speed)
    {
        (void)speed;
        return s_usb_device_descriptor;
    }

    const uint8_t *config_descriptor_callback(uint8_t speed)
    {
        if (speed == USB_SPEED_HIGH)
            return s_usb_config_descriptor_hs;
        else if (speed == USB_SPEED_FULL)
            return s_usb_config_descriptor_fs;
        else
            return NULL;
    }

    const uint8_t *device_quality_descriptor_callback(uint8_t speed)
    {
        (void)speed;
        return s_usb_device_quality_descriptor;
    }

    const uint8_t *other_speed_config_descriptor_callback(uint8_t speed)
    {
        if (speed == USB_SPEED_HIGH)
            return s_usb_other_speed_config_descriptor_hs;
        else if (speed == USB_SPEED_FULL)
            return s_usb_other_speed_config_descriptor_fs;
        else
            return NULL;
    }

    const char *string_descriptor_callback(uint8_t speed, uint8_t index)
    {
        (void)speed;
        if (index >= (sizeof(s_usb_string_descriptor) / sizeof(char *)))
        {
            return NULL;
        }
        return s_usb_string_descriptor[index];
    }

    const struct usb_descriptor s_usb_descriptor = {
        .device_descriptor_callback = device_descriptor_callback,
        .config_descriptor_callback = config_descriptor_callback,
        .device_quality_descriptor_callback = device_quality_descriptor_callback,
        .other_speed_descriptor_callback = other_speed_config_descriptor_callback,
        .string_descriptor_callback = string_descriptor_callback,
        .msosv1_descriptor = NULL,
        .msosv2_descriptor = NULL,
        .webusb_url_descriptor = NULL,
        .bos_descriptor = NULL};

} // namespace

namespace
{
    const uint8_t s_usb_busid = 0;

    void usbd_event_handler(uint8_t busid, uint8_t event)
    {
        (void)busid;
        switch (event)
        {
        case USBD_EVENT_RESET:
            break;
        case USBD_EVENT_CONNECTED:
            break;
        case USBD_EVENT_DISCONNECTED:
            break;
        case USBD_EVENT_RESUME:
            break;
        case USBD_EVENT_SUSPEND:
            break;
        case USBD_EVENT_CONFIGURED:
            break;
        case USBD_EVENT_SET_REMOTE_WAKEUP:
            break;
        case USBD_EVENT_CLR_REMOTE_WAKEUP:
            break;

        default:
            break;
        }
    }
} // namespace

namespace
{
#include "class/hid/usbd_hid.h"

    USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t s_usbd_hid_in_buffer[USB_HID_EP_SIZE] = {};
    USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t s_usbd_hid_out_buffer[USB_HID_EP_SIZE] = {};

    volatile bool s_usbd_hid_in_ep_busy_flag = false;
    volatile bool s_usbd_hid_out_ep_busy_flag = false;

    void usbd_hid_get_report(uint8_t busid, uint8_t intf, uint8_t report_id, uint8_t report_type, uint8_t **data, uint32_t *len)
    {
        (void)busid;
        (void)intf;
        (void)report_id;
        (void)report_type;
        (*data[0]) = 0;
        *len = 1;
    }

    uint8_t usbd_hid_get_idle(uint8_t busid, uint8_t intf, uint8_t report_id)
    {
        (void)busid;
        (void)intf;
        (void)report_id;
        return 0;
    }

    uint8_t usbd_hid_get_protocol(uint8_t busid, uint8_t intf)
    {
        (void)busid;
        (void)intf;
        return 0;
    }

    void usbd_hid_set_report(uint8_t busid, uint8_t intf, uint8_t report_id, uint8_t report_type, uint8_t *report, uint32_t report_len)
    {
        (void)busid;
        (void)intf;
        (void)report_id;
        (void)report_type;
        (void)report;
        (void)report_len;
    }

    void usbd_hid_set_idle(uint8_t busid, uint8_t intf, uint8_t report_id, uint8_t duration)
    {
        (void)busid;
        (void)intf;
        (void)report_id;
        (void)duration;
    }

    void usbd_hid_set_protocol(uint8_t busid, uint8_t intf, uint8_t protocol)
    {
        (void)busid;
        (void)intf;
        (void)protocol;
    }

    struct usbd_hid_request_callback s_usbd_hid_request_callback = {
        .usbd_hid_get_report = usbd_hid_get_report,
        .usbd_hid_get_idle = usbd_hid_get_idle,
        .usbd_hid_get_protocol = usbd_hid_get_protocol,
        .usbd_hid_set_report = usbd_hid_set_report,
        .usbd_hid_set_idle = usbd_hid_set_idle,
        .usbd_hid_set_protocol = usbd_hid_set_protocol,
    };

    struct usbd_interface s_usbd_hid_intf = {};

    void usbd_hid_in_ep_callback(uint8_t busid, uint8_t ep, uint32_t nbytes)
    {
        (void)busid;
        (void)ep;
        (void)nbytes;
        s_usbd_hid_in_ep_busy_flag = false;
    }

    void usbd_hid_out_ep_callback(uint8_t busid, uint8_t ep, uint32_t nbytes)
    {
        (void)busid;
        (void)ep;
        (void)nbytes;
        s_usbd_hid_out_ep_busy_flag = false;
    }

    struct usbd_endpoint s_usbd_hid_in_ep = {
        .ep_addr = USB_HID_IN_EP_ADDR,
        .ep_cb = usbd_hid_in_ep_callback};

    struct usbd_endpoint s_usbd_hid_out_ep = {
        .ep_addr = USB_HID_OUT_EP_ADDR,
        .ep_cb = usbd_hid_out_ep_callback};

} // namespace

namespace
{
#include "class/audio/usbd_audio.h"

    USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t s_usbd_audio_in_buffer[USB_AUDIO_IN_PACKET_SIZE] = {};
    USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t s_usbd_audio_out_buffer[USB_AUDIO_OUT_PACKET_SIZE] = {};
    // USB_NOCACHE_RAM_SECTION USB_MEM_ALIGNX uint8_t s_usbd_audio_feedback_buffer[4];

    volatile bool s_usbd_audio_in_ep_busy_flag = false;

    volatile bool s_usbd_audio_tx_enable = false;
    volatile bool s_usbd_audio_rx_enable = false;

    volatile uint32_t s_usbd_audio_tx_sample_rate;
    volatile uint32_t s_usbd_audio_rx_sample_rate;

    void usbd_audio_open(uint8_t busid, uint8_t intf)
    {
        (void)busid;

        switch (intf)
        {
        case USB_AS_IN_ITF_IDX:
            s_usbd_audio_tx_enable = true;
            s_usbd_audio_in_ep_busy_flag = false;
            break;
        case USB_AS_OUT_ITF_IDX:
            s_usbd_audio_rx_enable = true;
            usbd_ep_start_read(busid, USB_AUDIO_OUT_EP_ADDR, s_usbd_audio_out_buffer, USB_AUDIO_OUT_PACKET_SIZE);
            break;

        default:
            break;
        }
    }

    void usbd_audio_close(uint8_t busid, uint8_t intf)
    {
        (void)busid;

        switch (intf)
        {
        case USB_AS_IN_ITF_IDX:
            s_usbd_audio_tx_enable = false;
            s_usbd_audio_in_ep_busy_flag = false;
            break;
        case USB_AS_OUT_ITF_IDX:
            s_usbd_audio_rx_enable = false;
            break;

        default:
            break;
        }
    }

    void usbd_audio_set_sampling_freq(uint8_t busid, uint8_t ep, uint32_t sampling_freq)
    {
        (void)busid;

        switch (ep)
        {
        case USB_AUDIO_IN_EP_ADDR:
            s_usbd_audio_tx_sample_rate = sampling_freq;
            break;
        case USB_AUDIO_OUT_EP_ADDR:
            s_usbd_audio_rx_sample_rate = sampling_freq;
            break;

        default:
            break;
        }
    }

    uint32_t usbd_audio_get_sampling_freq(uint8_t busid, uint8_t ep)
    {
        (void)busid;

        uint32_t freq = 0;
        switch (ep)
        {
        case USB_AUDIO_IN_EP_ADDR:
            freq = s_usbd_audio_tx_sample_rate;
            break;
        case USB_AUDIO_OUT_EP_ADDR:
            freq = s_usbd_audio_rx_sample_rate;
            break;

        default:
            break;
        }
        return freq;
    }

    struct usbd_audio_request_callback s_usbd_audio_request_callback = {
        .usbd_audio_open = usbd_audio_open,
        .usbd_audio_close = usbd_audio_close,
        .usbd_audio_set_volume = NULL,
        .usbd_audio_get_volume = NULL,
        .usbd_audio_set_mute = NULL,
        .usbd_audio_get_mute = NULL,
        .usbd_audio_set_sampling_freq = usbd_audio_set_sampling_freq,
        .usbd_audio_get_sampling_freq = usbd_audio_get_sampling_freq,
        .usbd_audio_get_sampling_freq_table = NULL,
    };

    struct usbd_interface s_usbd_audio_intf0 = {};
    struct usbd_interface s_usbd_audio_intf1 = {};
    struct usbd_interface s_usbd_audio_intf2 = {};

    void usbd_audio_in_ep_callback(uint8_t busid, uint8_t ep, uint32_t nbytes)
    {
        (void)busid;
        (void)ep;
        (void)nbytes;
        s_usbd_audio_in_ep_busy_flag = false;
    }

    void usbd_audio_out_ep_callback(uint8_t busid, uint8_t ep, uint32_t nbytes)
    {
        (void)busid;
        (void)ep;
        (void)nbytes;
        usbd_ep_start_read(busid, USB_AUDIO_OUT_EP_ADDR, s_usbd_audio_out_buffer, USB_AUDIO_OUT_PACKET_SIZE);
    }

    struct usbd_endpoint s_usbd_audio_in_ep = {
        .ep_addr = USB_AUDIO_IN_EP_ADDR,
        .ep_cb = usbd_audio_in_ep_callback};

    struct usbd_endpoint s_usbd_audio_out_ep = {
        .ep_addr = USB_AUDIO_OUT_EP_ADDR,
        .ep_cb = usbd_audio_out_ep_callback};

    struct audio_entity_info s_usbd_audio_entity_table[] = {
        {.bDescriptorSubtype = AUDIO_CONTROL_FEATURE_UNIT,
         .bEntityId = USB_AUDIO_OUT_FU_ID,
         .ep = USB_AUDIO_OUT_EP_ADDR},
        {.bDescriptorSubtype = AUDIO_CONTROL_FEATURE_UNIT,
         .bEntityId = USB_AUDIO_IN_FU_ID,
         .ep = USB_AUDIO_IN_EP_ADDR},
    };

} // namespace

namespace
{
    void handleReportIn01USB(DualSenseStruct::ReportIn01USB &report)
    {
        // Adjust range from [-1,1] to [0,255].
        const uint8_t lx_report = (hid_axis(gamepad_axis[LX], GAMEPAD_AXIS_LX, GAMEPAD_AXIS_LX_NEG) + 1) * UINT_7_MAX;
        const uint8_t ly_report = (hid_axis(gamepad_axis[LY], GAMEPAD_AXIS_LY, GAMEPAD_AXIS_LY_NEG) + 1) * UINT_7_MAX;
        const uint8_t rx_report = (hid_axis(gamepad_axis[RX], GAMEPAD_AXIS_RX, GAMEPAD_AXIS_RX_NEG) + 1) * UINT_7_MAX;
        const uint8_t ry_report = (hid_axis(gamepad_axis[RY], GAMEPAD_AXIS_RY, GAMEPAD_AXIS_RY_NEG) + 1) * UINT_7_MAX;
        // Adjust range from [0,1] to [0,255].
        const uint8_t lz_report = hid_axis(gamepad_axis[LZ], GAMEPAD_AXIS_LZ, 0) * UINT_8_MAX;
        const uint8_t rz_report = hid_axis(gamepad_axis[RZ], GAMEPAD_AXIS_RZ, 0) * UINT_8_MAX;

        report.ReportID = DUAL_SENSE_USB_HID_INPUT_ID01;
        report.State.LeftStickX = lx_report;
        report.State.LeftStickY = ly_report;
        report.State.RightStickX = rx_report;
        report.State.RightStickY = ry_report;
        report.State.TriggerLeft = lz_report;
        report.State.TriggerRight = rz_report;
        report.State.DPad = static_cast<DualSenseStruct::Direction>(dpad_button_to_hat_switch_none8(
            state_matrix[GAMEPAD_UP],
            state_matrix[GAMEPAD_DOWN],
            state_matrix[GAMEPAD_LEFT],
            state_matrix[GAMEPAD_RIGHT]));
        report.State.ButtonSquare = state_matrix[GAMEPAD_Y];
        report.State.ButtonCross = state_matrix[GAMEPAD_B];
        report.State.ButtonCircle = state_matrix[GAMEPAD_A];
        report.State.ButtonTriangle = state_matrix[GAMEPAD_X];
        report.State.ButtonL1 = state_matrix[GAMEPAD_L1];
        report.State.ButtonR1 = state_matrix[GAMEPAD_R1];
        report.State.ButtonL2 = lz_report > 0;
        report.State.ButtonR2 = rz_report > 0;
        report.State.ButtonCreate = state_matrix[GAMEPAD_SELECT];
        report.State.ButtonOptions = state_matrix[GAMEPAD_START];
        report.State.ButtonL3 = state_matrix[GAMEPAD_L3];
        report.State.ButtonR3 = state_matrix[GAMEPAD_R3];
        report.State.ButtonHome = state_matrix[GAMEPAD_HOME];

        const auto ts_us = HAL_Time::GetTime_us_32bit();

        // 转为摆正的原生输出
        const Vector a_accel = {
            .x = -g_gamepad_accel.x,
            .y = -g_gamepad_accel.y,
            .z = g_gamepad_accel.z,
        };
        const Vector a_gyro = {
            .x = -g_gamepad_gyro.y,
            .y = -g_gamepad_gyro.z,
            .z = -g_gamepad_gyro.x,
        };

        // 转为航空航天标准
        const Vector b_accel = {
            .x = -a_accel.y,
            .y = -a_accel.x,
            .z = a_accel.z,
        };
        const Vector b_gyro = {
            .x = a_gyro.y,
            .y = a_gyro.x,
            .z = a_gyro.z,
        };

        // 对齐量程(4G 2000DPS)
        const double accel_x = b_accel.x / 2;
        const double accel_y = b_accel.y / 2;
        const double accel_z = b_accel.z / 2;
        const double gyro_x = b_gyro.x / 4;
        const double gyro_y = b_gyro.y / 4;
        const double gyro_z = b_gyro.z / 4;

        report.State.AccelerometerX = -(accel_y);
        report.State.AccelerometerY = -(accel_x);
        report.State.AccelerometerZ = accel_z;
        report.State.AngularVelocityX = gyro_y;
        report.State.AngularVelocityZ = gyro_z;
        report.State.AngularVelocityY = -(gyro_x);
        report.State.SensorTimestamp = TimestampConvert(ts_us);
    }

    void handleReportOut02(const DualSenseStruct::ReportOut02 &report)
    {
#if (CFG_USE_RUMBLE)
        // hostTimeStamp = report.State.HostTimestamp;
        if (report.State.EnableImprovedRumbleEmulation)
        {
            const float l_duty = report.State.RumbleEmulationLeft / 255.f;
            HAL_PWM::SetDutyCompareCount(PIN_L, l_duty * 255);
            const float r_duty = report.State.RumbleEmulationRight / 255.f;
            HAL_PWM::SetDutyCompareCount(PIN_R, r_duty * 255);
        }
        else
        {
            const float l_duty = report.State.RumbleEmulationLeft / 127.f;
            HAL_PWM::SetDutyCompareCount(PIN_L, l_duty * 255);
            const float r_duty = report.State.RumbleEmulationRight / 127.f;
            HAL_PWM::SetDutyCompareCount(PIN_R, r_duty * 255);
        }
#endif
    }

} // namespace

void DualSense::USB_Init()
{
    usbd_desc_register(s_usb_busid, &s_usb_descriptor);

    /*!< uac */
    // usbd_add_interface(s_usb_busid, usbd_audio_init_intf(s_usb_busid, &s_usbd_audio_intf0, 0x0100, s_usbd_audio_entity_table, 2, s_usbd_audio_request_callback));
    // usbd_add_interface(s_usb_busid, usbd_audio_init_intf(s_usb_busid, &s_usbd_audio_intf1, 0x0100, s_usbd_audio_entity_table, 2, s_usbd_audio_request_callback));
    // usbd_add_interface(s_usb_busid, usbd_audio_init_intf(s_usb_busid, &s_usbd_audio_intf2, 0x0100, s_usbd_audio_entity_table, 2, s_usbd_audio_request_callback));
    // usbd_add_endpoint(s_usb_busid, &s_usbd_audio_out_ep);
    // usbd_add_endpoint(s_usb_busid, &s_usbd_audio_in_ep);

    /*!< hid */
    usbd_add_interface(s_usb_busid, usbd_hid_init_intf(s_usb_busid, &s_usbd_hid_intf, s_usb_hid_report_descriptor, sizeof(s_usb_hid_report_descriptor), s_usbd_hid_request_callback));
    usbd_add_endpoint(s_usb_busid, &s_usbd_hid_in_ep);
    usbd_add_endpoint(s_usb_busid, &s_usbd_hid_out_ep);

    usbd_initialize(s_usb_busid, (uintptr_t)CFG_USBD_BASE, usbd_event_handler);
}

void DualSense::USB_Process()
{
    if (usb_device_is_configured(s_usb_busid) == false)
    {
        LOG_PRINTF(Log::WARNING, "usb_device_is_configured(s_usb_busid) == false\n");
        return;
    }

    // if (s_usbd_audio_tx_enable && !s_usbd_audio_in_ep_busy_flag)
    // {
    //     memset(s_usbd_audio_in_buffer, 'a', USB_AUDIO_IN_PACKET_SIZE);
    //     s_usbd_audio_in_ep_busy_flag = true;
    //     usbd_ep_start_write(s_usb_busid, USB_AUDIO_IN_EP_ADDR, s_usbd_audio_in_buffer, USB_AUDIO_IN_PACKET_SIZE);
    // }

    if (!s_usbd_hid_in_ep_busy_flag)
    {
        size_t report_len;

        handleReportIn01USB((DualSenseStruct::ReportIn01USB &)s_usbd_hid_in_buffer);
        report_len = sizeof(DualSenseStruct::ReportIn01USB);

        usbd_ep_start_write(s_usb_busid, USB_HID_IN_EP_ADDR, s_usbd_hid_in_buffer, report_len);
        s_usbd_hid_in_ep_busy_flag = true;
    }
    hid_reset_gamepad_axis();

    if (!s_usbd_hid_out_ep_busy_flag)
    {
        switch (s_usbd_hid_out_buffer[0])
        {
        case 0x02:
            handleReportOut02((DualSenseStruct::ReportOut02 &)s_usbd_hid_out_buffer);
            break;

        default:
            break;
        }

        usbd_ep_start_read(s_usb_busid, USB_HID_OUT_EP_ADDR, s_usbd_hid_out_buffer, USB_HID_EP_SIZE);
        s_usbd_hid_out_ep_busy_flag = true;
    }
}
