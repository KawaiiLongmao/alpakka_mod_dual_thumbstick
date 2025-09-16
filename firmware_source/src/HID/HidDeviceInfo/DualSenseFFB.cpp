
#include "Library/cstd_lib.h"

enum class TriggerEffectType : uint8_t
{
    Off = 0x05,
    Feedback = 0x21,
    Weapon = 0x25,
    Vibration = 0x26,
    Bow = 0x22,
    Galloping = 0x23,
    Machine = 0x27,
    Simple_Feedback = 0x01,
    Simple_Weapon = 0x02,
    Simple_Vibration = 0x06,
    Limited_Feedback = 0x11,
    Limited_Weapon = 0x12,
    DebugFC = 0xFC,
    DebugFD = 0xFD,
    DebugFE = 0xFE
};

namespace TriggerEffectGenerator
{

    bool Off(uint8_t *destinationArray, size_t destinationIndex)
    {
        destinationArray[destinationIndex + 0] = static_cast<uint8_t>(TriggerEffectType::Off);
        destinationArray[destinationIndex + 1] = 0x00;
        destinationArray[destinationIndex + 2] = 0x00;
        destinationArray[destinationIndex + 3] = 0x00;
        destinationArray[destinationIndex + 4] = 0x00;
        destinationArray[destinationIndex + 5] = 0x00;
        destinationArray[destinationIndex + 6] = 0x00;
        destinationArray[destinationIndex + 7] = 0x00;
        destinationArray[destinationIndex + 8] = 0x00;
        destinationArray[destinationIndex + 9] = 0x00;
        destinationArray[destinationIndex + 10] = 0x00;
        return true;
    }

    bool Feedback(uint8_t *destinationArray, size_t destinationIndex, uint8_t position, uint8_t strength)
    {
        if (position > 9 || strength > 8)
            return false;

        if (strength > 0)
        {
            uint8_t forceValue = (strength - 1) & 0x07;
            uint32_t forceZones = 0;
            uint16_t activeZones = 0;

            for (int i = position; i < 10; ++i)
            {
                forceZones |= static_cast<uint32_t>(forceValue << (3 * i));
                activeZones |= (1 << i);
            }

            destinationArray[destinationIndex + 0] = static_cast<uint8_t>(TriggerEffectType::Feedback);
            destinationArray[destinationIndex + 1] = static_cast<uint8_t>((activeZones >> 0) & 0xFF);
            destinationArray[destinationIndex + 2] = static_cast<uint8_t>((activeZones >> 8) & 0xFF);
            destinationArray[destinationIndex + 3] = static_cast<uint8_t>((forceZones >> 0) & 0xFF);
            destinationArray[destinationIndex + 4] = static_cast<uint8_t>((forceZones >> 8) & 0xFF);
            destinationArray[destinationIndex + 5] = static_cast<uint8_t>((forceZones >> 16) & 0xFF);
            destinationArray[destinationIndex + 6] = static_cast<uint8_t>((forceZones >> 24) & 0xFF);
            destinationArray[destinationIndex + 7] = 0x00;
            destinationArray[destinationIndex + 8] = 0x00;
            destinationArray[destinationIndex + 9] = 0x00;
            destinationArray[destinationIndex + 10] = 0x00;
            return true;
        }
        return Off(destinationArray, destinationIndex);
    }

    bool Weapon(uint8_t *destinationArray, size_t destinationIndex, uint8_t startPosition, uint8_t endPosition, uint8_t strength)
    {
        if (startPosition > 7 || startPosition < 2 || endPosition > 8 || endPosition <= startPosition || strength > 8)
            return false;

        if (strength > 0)
        {
            uint16_t startAndStopZones = (1 << startPosition) | (1 << endPosition);

            destinationArray[destinationIndex + 0] = static_cast<uint8_t>(TriggerEffectType::Weapon);
            destinationArray[destinationIndex + 1] = static_cast<uint8_t>((startAndStopZones >> 0) & 0xFF);
            destinationArray[destinationIndex + 2] = static_cast<uint8_t>((startAndStopZones >> 8) & 0xFF);
            destinationArray[destinationIndex + 3] = static_cast<uint8_t>(strength - 1);
            destinationArray[destinationIndex + 4] = 0x00;
            destinationArray[destinationIndex + 5] = 0x00;
            destinationArray[destinationIndex + 6] = 0x00;
            destinationArray[destinationIndex + 7] = 0x00;
            destinationArray[destinationIndex + 8] = 0x00;
            destinationArray[destinationIndex + 9] = 0x00;
            destinationArray[destinationIndex + 10] = 0x00;
            return true;
        }
        return Off(destinationArray, destinationIndex);
    }

    bool Vibration(uint8_t *destinationArray, size_t destinationIndex, uint8_t position, uint8_t amplitude, uint8_t frequency)
    {
        if (position > 9 || amplitude > 8)
            return false;

        if (amplitude > 0 && frequency > 0)
        {
            uint8_t strengthValue = (amplitude - 1) & 0x07;
            uint32_t amplitudeZones = 0;
            uint16_t activeZones = 0;

            for (int i = position; i < 10; ++i)
            {
                amplitudeZones |= static_cast<uint32_t>(strengthValue << (3 * i));
                activeZones |= (1 << i);
            }

            destinationArray[destinationIndex + 0] = static_cast<uint8_t>(TriggerEffectType::Vibration);
            destinationArray[destinationIndex + 1] = static_cast<uint8_t>((activeZones >> 0) & 0xFF);
            destinationArray[destinationIndex + 2] = static_cast<uint8_t>((activeZones >> 8) & 0xFF);
            destinationArray[destinationIndex + 3] = static_cast<uint8_t>((amplitudeZones >> 0) & 0xFF);
            destinationArray[destinationIndex + 4] = static_cast<uint8_t>((amplitudeZones >> 8) & 0xFF);
            destinationArray[destinationIndex + 5] = static_cast<uint8_t>((amplitudeZones >> 16) & 0xFF);
            destinationArray[destinationIndex + 6] = static_cast<uint8_t>((amplitudeZones >> 24) & 0xFF);
            destinationArray[destinationIndex + 7] = 0x00;
            destinationArray[destinationIndex + 8] = 0x00;
            destinationArray[destinationIndex + 9] = frequency;
            destinationArray[destinationIndex + 10] = 0x00;
            return true;
        }
        return Off(destinationArray, destinationIndex);
    }

    bool MultiplePositionFeedback(uint8_t *destinationArray, size_t destinationIndex, const uint8_t strength[10])
    {
        bool hasEffect = false;
        for (int i = 0; i < 10; ++i)
        {
            if (strength[i] > 0)
            {
                hasEffect = true;
                break;
            }
        }

        if (hasEffect)
        {
            uint32_t forceZones = 0;
            uint16_t activeZones = 0;

            for (int i = 0; i < 10; ++i)
            {
                if (strength[i] > 0)
                {
                    uint8_t forceValue = (strength[i] - 1) & 0x07;
                    forceZones |= static_cast<uint32_t>(forceValue << (3 * i));
                    activeZones |= (1 << i);
                }
            }

            destinationArray[destinationIndex + 0] = static_cast<uint8_t>(TriggerEffectType::Feedback);
            destinationArray[destinationIndex + 1] = static_cast<uint8_t>((activeZones >> 0) & 0xFF);
            destinationArray[destinationIndex + 2] = static_cast<uint8_t>((activeZones >> 8) & 0xFF);
            destinationArray[destinationIndex + 3] = static_cast<uint8_t>((forceZones >> 0) & 0xFF);
            destinationArray[destinationIndex + 4] = static_cast<uint8_t>((forceZones >> 8) & 0xFF);
            destinationArray[destinationIndex + 5] = static_cast<uint8_t>((forceZones >> 16) & 0xFF);
            destinationArray[destinationIndex + 6] = static_cast<uint8_t>((forceZones >> 24) & 0xFF);
            destinationArray[destinationIndex + 7] = 0x00;
            destinationArray[destinationIndex + 8] = 0x00;
            destinationArray[destinationIndex + 9] = 0x00;
            destinationArray[destinationIndex + 10] = 0x00;
            return true;
        }
        return Off(destinationArray, destinationIndex);
    }

    namespace Apple
    {
        bool SetModeOff(uint8_t *destinationArray, size_t destinationIndex)
        {
            return Off(destinationArray, destinationIndex);
        }

        bool SetModeFeedbackWithStartPosition(uint8_t *destinationArray, size_t destinationIndex, float startPosition, float resistiveStrength)
        {
            uint8_t pos = static_cast<uint8_t>(std::round(startPosition * 9.0f));
            uint8_t strength = static_cast<uint8_t>(std::round(resistiveStrength * 8.0f));
            return Feedback(destinationArray, destinationIndex, pos, strength);
        }

        bool SetModeWeaponWithStartPosition(uint8_t *destinationArray, size_t destinationIndex, float startPos, float endPos, float strength)
        {
            uint8_t start = static_cast<uint8_t>(std::round(startPos * 9.0f));
            uint8_t end = static_cast<uint8_t>(std::round(endPos * 9.0f));
            uint8_t str = static_cast<uint8_t>(std::round(strength * 8.0f));
            return Weapon(destinationArray, destinationIndex, start, end, str);
        }
    }

    namespace ReWASD
    {
        bool FullPress(uint8_t *destinationArray, size_t destinationIndex)
        {
            destinationArray[destinationIndex + 0] = static_cast<uint8_t>(TriggerEffectType::Simple_Weapon);
            destinationArray[destinationIndex + 1] = 0x90;
            destinationArray[destinationIndex + 2] = 0xA0;
            destinationArray[destinationIndex + 3] = 0xFF;
            // 填充剩餘位元組...
            return true;
        }

        bool Rifle(uint8_t *destinationArray, size_t destinationIndex, uint8_t frequency)
        {
            if (frequency < 2 || frequency > 20)
                return false;

            destinationArray[destinationIndex + 0] = static_cast<uint8_t>(TriggerEffectType::Vibration);
            destinationArray[destinationIndex + 1] = 0x00;
            destinationArray[destinationIndex + 2] = 0x03;
            // 填充剩餘位元組...
            return true;
        }
    }

} // namespace TriggerEffectGenerator
