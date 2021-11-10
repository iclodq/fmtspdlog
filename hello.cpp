
#include <iostream>
#include <vector>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include "Log.h"

using namespace std;

#include <unordered_map>

int main(void)
{
    Logger::GlobalSet(Logger::Level::debug, "battle", "./logs/");
    fmt::print("hello {}\n", "world");
    spdlog::info("hello world");
    spdlog::info("ksdjf {}, {}", "ksdjkl", 1231);
    std::unordered_map<int, int> unmap;
    unmap[1] = 1;
    unmap[2] = 2;
    unmap[1] = 1;

    //LogDebug("ksklkd {} ", "hello world");
    LogDebug("ksklkd {} ", 23);

    Logger::Instance().Clear();
    return 0;
}
