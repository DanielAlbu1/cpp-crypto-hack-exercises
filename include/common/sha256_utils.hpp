#pragma once

#include <array>
#include <cstddef>
#include <openssl/sha.h>
#include <string_view>

namespace common {

using Sha256Digest = std::array<unsigned char, SHA256_DIGEST_LENGTH>;

inline Sha256Digest sha256(std::string_view message) {
    Sha256Digest digest{};
    SHA256(
        reinterpret_cast<const unsigned char*>(message.data()),
        static_cast<unsigned long>(message.size()),
        digest.data());
    return digest;
}

}  // namespace common
