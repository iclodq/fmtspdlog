
#include "Log.h"

//#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/async.h>

//std::unique_ptr<Logger> Logger::g_logger;
static std::shared_ptr<spdlog::logger> MakeLogger(Logger::Level level, const char* mod, const char* logDir)
{
    char        fileName[255]{ 0 };
    const char* levelStr = spdlog::level::to_string_view((spdlog::level::level_enum) level).data();
    fmt::format_to(fileName, "{}{}_{}.log", logDir, mod, levelStr);
    return spdlog::daily_logger_mt<spdlog::async_factory>(levelStr, fileName, 23, 58);
}

void Logger::GlobalSet(Level level, const char* mod, const char* dir)
{
    if (level < Level::off && Instance()._loggers[level])
    {
        return;
    }
    spdlog::set_level(spdlog::level::trace);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e][%P:%t] %v [%@:%!]");
    //spdlog::set_level(spdlog::level::level_enum(level));
#define CraeteLogger(LV) Instance()._loggers[LV] = MakeLogger(LV, mod, dir)

    std::string filename(dir);
    switch (level)
    {
    case Logger::Level::trace:
        CraeteLogger(Level::trace);
        //break;
    case Logger::Level::debug:
        CraeteLogger(Level::debug);
        //break;
    case Logger::Level::info:
        CraeteLogger(Level::info);
        //break;
    case Logger::Level::warn:
        CraeteLogger(Level::warn);
        //break;
    case Logger::Level::err:
        CraeteLogger(Level::err);
        //break;
    //case Logger::Level::critical:
    //    CraeteLogger(Level::critical);
        //break;
    case Logger::Level::off:
        break;
    case Logger::Level::n_levels:
        break;
    default:
        break;
    }

#undef CreateLogger
}

Logger::~Logger()
{
    //spdlog::drop_all();
}

Logger::Logger()
{
    //if (_loggers.empty())
    //{
    //    GlobalSet(Level::debug, "./logs/");
    //}
}
