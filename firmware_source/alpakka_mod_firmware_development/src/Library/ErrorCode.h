#pragma once

#ifdef __cplusplus
using ErrorCode = int;

namespace ERROR_CODE
{
    // 成功/无错误
    inline constexpr ErrorCode NONE = 0;

    // 通用错误
    inline constexpr ErrorCode GENERAL = -1;
}
#endif
