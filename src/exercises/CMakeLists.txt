cmake_minimum_required(VERSION 3.30)
project(Exercises)



find_package(benchmark 1.9 QUIET)
if (NOT benchmark_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark
    GIT_TAG main)
  option(BENCHMARK_ENABLE_TESTING "" OFF)
  option(BENCHMARK_ENABLE_GTEST_TESTS "" OFF)
  option(BENCHMARK_ENABLE_LIBPFM "" ON) # for performance counters
  FetchContent_MakeAvailable(benchmark)
endif()

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE benchmark::benchmark)

add_subdirectory(histograms)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
