cmake_minimum_required(VERSION 3.20)

project(cpp_crypto_hack_exercises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

find_package(OpenSSL REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Boost REQUIRED)
pkg_check_modules(SODIUM REQUIRED libsodium)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(challenge src/main.cpp)
target_link_libraries(challenge PRIVATE OpenSSL::Crypto Boost::boost ${SODIUM_LIBRARIES})
target_include_directories(challenge PRIVATE ${SODIUM_INCLUDE_DIRS})
target_compile_options(challenge PRIVATE ${SODIUM_CFLAGS_OTHER})

add_executable(crypto_tests tests/smoke_test.cpp)
target_link_libraries(crypto_tests PRIVATE GTest::gtest_main OpenSSL::Crypto Boost::boost ${SODIUM_LIBRARIES})
target_include_directories(crypto_tests PRIVATE ${SODIUM_INCLUDE_DIRS})
target_compile_options(crypto_tests PRIVATE ${SODIUM_CFLAGS_OTHER})

include(GoogleTest)
gtest_discover_tests(crypto_tests)
