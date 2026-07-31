#include <gtest/gtest.h>

#include "exercise01/sha256_first_byte.hpp"

TEST(Exercise01Test, Sha256FirstByteForAbc) {
    EXPECT_EQ(exercise01::sha256_first_byte("abc"), 0xba);
}
