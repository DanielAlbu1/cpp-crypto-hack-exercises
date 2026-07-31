set(EXERCISE_NAME exercise01)

add_library(${EXERCISE_NAME}_lib
    src/sha256_first_byte.cpp
)

target_include_directories(${EXERCISE_NAME}_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${EXERCISE_NAME}_lib
    PUBLIC
        common_headers
    PRIVATE
        OpenSSL::Crypto
)

add_executable(${EXERCISE_NAME}
    src/main.cpp
)

target_link_libraries(${EXERCISE_NAME}
    PRIVATE
        ${EXERCISE_NAME}_lib
)

add_executable(${EXERCISE_NAME}_tests
    tests/smoke_test.cpp
)

target_link_libraries(${EXERCISE_NAME}_tests
    PRIVATE
        ${EXERCISE_NAME}_lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${EXERCISE_NAME}_tests)
