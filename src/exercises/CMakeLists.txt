cmake_minimum_required(VERSION 3.30)
project(Exercises)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  benchmark
  URL https://github.com/google/benchmark/archive/refs/tags/v1.9.5.tar.gz
)
FetchContent_MakeAvailable(benchmark)
