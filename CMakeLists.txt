# Copyright(c) 2019 spdlog authors Distributed under the MIT License (http://opensource.org/licenses/MIT)

cmake_minimum_required(VERSION 3.10)



project(fmtspdlog LANGUAGES CXX)
message(STATUS "Build fmtspdlog: ${SPDLOG_VERSION}")

include(GNUInstallDirs)



# ---------------------------------------------------------------------------------------
# Set default build to release
# ---------------------------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()


# find_package(fmt REQUIRED PATHS ./deps/ NO_DEFAULT_PATH)
# find_package(spdlog REQUIRED PATHS ./deps/ NO_DEFAULT_PATH)

if ( fmt_FOUND)
    message( "fmt_FOUND")
endif ( fmt_FOUND)
# ---------------------------------------------------------------------------------------
# Compiler config
# ---------------------------------------------------------------------------------------
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# make sure __cplusplus is defined when using msvc and enable parallel build
if(MSVC)
    string(APPEND CMAKE_CXX_FLAGS " /Zc:__cplusplus /MP")
endif()

set(CMAKE_CXX_EXTENSIONS OFF)
#add_compile_definitions(SPDLOG_COMPILED_LIB)  

message("fmg include: ${fmt_INCLUDE_DIRS}  ${fmt_LIBRARIES} ")
MESSAGE("FMG INCLUDE: ${FMT_INCLUDE_DIRS}  ${FMT_LIBRARIES} ")
add_executable(${PROJECT_NAME} hello.cpp Log.cpp Log.h)
target_include_directories(${PROJECT_NAME} PUBLIC ./deps/include)
# target_link_libraries(${PROJECT_NAME} ${fmt_LIBRARIES} ${spdlog_LIBRARIES})
target_link_directories(${PROJECT_NAME} PUBLIC ./deps/lib)
target_link_libraries(${PROJECT_NAME} optimized spdlog optimized  fmt)
target_link_libraries(${PROJECT_NAME} debug spdlogd debug fmtd)

target_compile_definitions(${PROJECT_NAME} PUBLIC SPDLOG_FMT_EXTERNAL)