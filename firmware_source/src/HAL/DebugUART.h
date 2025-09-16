#pragma once

#include "Library/cstd_lib.h"

namespace DebugUART
{

    void Init();
    void Send(const uint8_t *tx_buf, size_t tx_len);
    void Send(const char *str);

}
