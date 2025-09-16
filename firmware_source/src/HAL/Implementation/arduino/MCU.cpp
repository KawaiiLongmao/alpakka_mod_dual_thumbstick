
#if defined(ARDUINO)
#include "HAL/MCU.h"

#include <Arduino.h>

namespace HAL_MCU
{

    void Reboot()
    {
        void (*resetFunc)(void) = 0;
        resetFunc();
    }

    void Shutdown()
    {
        // exit(1);
    }

}
#endif
