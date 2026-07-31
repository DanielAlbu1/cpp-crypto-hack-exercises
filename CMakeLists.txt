cmake_minimum_required(VERSION 3.20)

project(cpp_crypto_hack_exercises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

find_package(OpenSSL REQUIRED)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(common_headers INTERFACE)
target_include_directories(common_headers INTERFACE ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(exercises)
