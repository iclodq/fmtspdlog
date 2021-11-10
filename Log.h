#pragma once
#include <spdlog/spdlog.h>

#include <unordered_map>
class Logger
{
public:
    // 与spdlog中一致
    enum class Level : int
    {
        trace = SPDLOG_LEVEL_TRACE,
        debug = SPDLOG_LEVEL_DEBUG,
        info = SPDLOG_LEVEL_INFO,
        warn = SPDLOG_LEVEL_WARN,
        err = SPDLOG_LEVEL_ERROR,
        critical = SPDLOG_LEVEL_CRITICAL,
        off = SPDLOG_LEVEL_OFF,
        n_levels
    };

public:
    // 全局设置日志等级 目录等 默认是 debug  ./logs/
    static void GlobalSet(Level level, const char* mod, const char* dir);

    //static std::unique_ptr<Logger> g_logger;
    static Logger& Instance()
        //{
        //    return *g_logger;
        //}
    {
        static Logger logger;
        return logger;
    }

    void Clear() {
        spdlog::shutdown();
    }
    //{
    //    static Logger logger;
    //    return logger;
    //}

    /// @brief 日记记录
    template<typename... Args>
    void Log(Level lv, char const* fmt, Args&&... args)
    {
        Log(lv, nullptr, 0, nullptr, fmt, std::forward<Args>(args)...);
    }

    /// @brief 日志记录  指定 记录文件名、行号、函数名
    template<typename... Args>
    void Log(Level lv, const char* fileName, int lineNo, const char* funcName, char const* fmt, Args&&... args)
    {
        if (auto logger = _loggers[lv])
        {
            logger->log(spdlog::source_loc{ fileName, lineNo, funcName },
                        spdlog::level::level_enum(lv), fmt, std::forward<Args>(args)...);
        }
    }

private:
    Logger();
    ~Logger();
    Logger(const Logger& other) = delete;
    Logger& operator=(const Logger& other) = delete;

private:
    std::unordered_map<Level, std::shared_ptr<spdlog::logger> > _loggers;
};

#define LogBase(lv, msg, ...) Logger::Instance().Log(lv, __FILE__, __LINE__, __FUNCTION__, msg, __VA_ARGS__)
#define LogBaseNoFunc(lv, msg, ...) Logger::Instance().Log(lv, FILE_BASENAME, __LINE__, nullptr, msg, __VA_ARGS__)
//#define LogTrace(msg, ...) Logger::Instance().Log(Logger::Level::trace, FILE_BASENAME, __LINE__, __FUNCTION__, msg, __VA_ARGS__)
//#define LogDebug(msg, ...) Logger::Instance().Log(Logger::Level::debug, FILE_BASENAME, __LINE__, __FUNCTION__, msg, __VA_ARGS__)
//#define LogWarn(msg, ...) Logger::Instance().Log(Logger::Level::warn, FILE_BASENAME, __LINE__, __FUNCTION__, msg, __VA_ARGS__)
//#define LogErr(msg, ...) Logger::Instance().Log(Logger::Level::err, FILE_BASENAME, __LINE__, __FUNCTION__, msg, __VA_ARGS__)
//#define LogCritical(msg, ...) Logger::Instance().Log(Logger::Level::critical, FILE_BASENAME, __LINE__, __FUNCTION__, msg, __VA_ARGS__)

#define LogTrace(msg, ...) LogBase(Logger::Level::trace, msg, __VA_ARGS__)
#define LogDebug(msg, ...) LogBase(Logger::Level::debug, msg, __VA_ARGS__)
#define LogWarn(msg, ...) LogBase(Logger::Level::warn, msg, __VA_ARGS__)
#define LogErr(msg, ...) LogBase(Logger::Level::err, msg, __VA_ARGS__)
#define LogCritical(msg, ...) LogBase(Logger::Level::critical, msg, __VA_ARGS__)

