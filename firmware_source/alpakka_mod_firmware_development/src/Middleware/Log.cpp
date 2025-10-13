#include "Log.h"

#include "Library/cstd_lib.h"
// #include "HAL/DebugUART.h"
#include "logging.h"

namespace Log
{
    void Printf(Level level, const char *msg, ...)
    {
        // 定义日志级别前缀
        static const char *level_prefix[] = {
            "[INFO]  :", // INFO
            "[WARN]  :", // WARN
            "[ERROR] :", // ERROR
            "[DEBUG] :"  // DEBUG
        };

        // 安全缓冲区
        char buffer[256];
        va_list args;
        va_start(args, msg);

        // 拼接前缀和消息
        int prefix_len = snprintf(buffer, sizeof(buffer), "%s ", level_prefix[static_cast<uint8_t>(level)]);
        if (prefix_len < 0)
        {
            va_end(args);
            return; // 格式错误保护
        }
        // 安全格式化用户消息
        int content_len = vsnprintf(buffer + prefix_len,         // 写入位置
                                    sizeof(buffer) - prefix_len, // 剩余空间
                                    msg,
                                    args);

        va_end(args);

        // 处理截断警告（可选）
        if (content_len >= static_cast<int>(sizeof(buffer) - prefix_len))
        {
            const char *warn = "[TRUNCATED]";
            snprintf(buffer + sizeof(buffer) - strlen(warn) - 1,
                     strlen(warn) + 1, "%s", warn);
        }

        // 输出
        // DebugUART::Send(buffer);
        info(buffer);
    }
}
