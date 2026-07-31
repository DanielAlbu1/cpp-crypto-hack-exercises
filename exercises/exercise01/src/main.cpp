#include <iostream>

#include "exercise01/sha256_first_byte.hpp"

int main() {
    constexpr char message[] = "CryptoHack C++ environment ready";
    const unsigned char first_byte = exercise01::sha256_first_byte(message);

    std::cout << "Exercise 01 ready. SHA-256 first byte: " << static_cast<int>(first_byte) << '\n';
    return 0;
}
