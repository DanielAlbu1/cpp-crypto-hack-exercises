#include "exercise01/sha256_first_byte.hpp"

#include "common/sha256_utils.hpp"

namespace exercise01 {

unsigned char sha256_first_byte(std::string_view message) {
    return common::sha256(message)[0];
}

}  // namespace exercise01
