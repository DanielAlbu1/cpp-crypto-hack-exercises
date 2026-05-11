#include <iostream>
#include <openssl/sha.h>

int main() {
    constexpr char message[] = "CryptoHack C++ environment ready";
    unsigned char digest[SHA256_DIGEST_LENGTH] = {};

    SHA256(reinterpret_cast<const unsigned char*>(message), sizeof(message) - 1, digest);

    std::cout << "Ready. SHA-256 first byte: " << static_cast<int>(digest[0]) << '\n';
    return 0;
}
