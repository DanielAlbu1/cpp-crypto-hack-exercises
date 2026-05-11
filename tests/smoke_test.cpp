#include <gtest/gtest.h>
#include <openssl/sha.h>

TEST(CryptoEnvironmentTest, Sha256ProducesDigest) {
    constexpr char message[] = "abc";
    unsigned char digest[SHA256_DIGEST_LENGTH] = {};

    SHA256(reinterpret_cast<const unsigned char*>(message), sizeof(message) - 1, digest);

    EXPECT_EQ(digest[0], 0xba);
    EXPECT_EQ(digest[1], 0x78);
}