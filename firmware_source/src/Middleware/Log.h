#pragma once

#ifdef __cplusplus

#define CFG_LOG_DEBUG 0

#if CFG_LOG_DEBUG
#define LOG_DEBUG(fmt, ...) Log::Printf(Log::DEBUG, fmt, ##__VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...)
#endif

// 日志级别全局开关（按需配置）
#define CFG_LOG_LEVEL_INFO 1
#define CFG_LOG_LEVEL_WARNING 1
#define CFG_LOG_LEVEL_ERROR 1
#define CFG_LOG_LEVEL_DEBUG 0

// 核心宏定义 - 完美兼容原始调用
#define LOG_PRINTF(level, fmt, ...) \
    LOG_DISPATCH(level, fmt, ##__VA_ARGS__)

// 分发宏 - 根据级别选择实现
#define LOG_DISPATCH(level, fmt, ...)               \
    do                                              \
    {                                               \
        if constexpr (LOG_IS_ENABLED(level))        \
        {                                           \
            Log::Printf(level, fmt, ##__VA_ARGS__); \
        }                                           \
    } while (0)

// 编译期级别检查（C++17 constexpr if）
#define LOG_IS_ENABLED(level) \
    ([]() constexpr -> bool { \
        switch (level) { \
            case Log::INFO:   return CFG_LOG_LEVEL_INFO; \
            case Log::WARNING: return CFG_LOG_LEVEL_WARNING; \
            case Log::ERROR:  return CFG_LOG_LEVEL_ERROR; \
            case Log::DEBUG:  return CFG_LOG_LEVEL_DEBUG; \
            default:          return true; \
        } }())

namespace Log
{
    enum Level
    {
        INFO,
        WARNING,
        ERROR,
        DEBUG,
        WARN = WARNING,
    };
    void Printf(Level level, const char *msg, ...);
}

#endif
