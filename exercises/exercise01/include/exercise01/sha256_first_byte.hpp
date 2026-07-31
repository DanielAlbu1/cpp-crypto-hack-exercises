#pragma once

#include <cstddef>
#include <string_view>

namespace exercise01 {

unsigned char sha256_first_byte(std::string_view message);

}  // namespace exercise01
