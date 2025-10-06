#include "hash.h"

inline int rotl32(int x, int r) {
    return (x << r) | ((unsigned int)x >> (32 - r));
}

int murmurhash3_32_int(const std::string& s, int seed = 0) {
    const unsigned char* data = reinterpret_cast<const unsigned char*>(s.data());
    int len = static_cast<int>(s.size());
    int nblocks = len / 4;

    int h1 = seed;
    const int c1 = 0xcc9e2d51;
    const int c2 = 0x1b873593;

    // --- phần chính ---
    for (int i = 0; i < nblocks; i++) {
        int k1 = (data[i * 4 + 0])
               | (data[i * 4 + 1] << 8)
               | (data[i * 4 + 2] << 16)
               | (data[i * 4 + 3] << 24);

        k1 *= c1;
        k1 = rotl32(k1, 15);
        k1 *= c2;

        h1 ^= k1;
        h1 = rotl32(h1, 13);
        h1 = h1 * 5 + 0xe6546b64;
    }

    // --- phần dư ---
    int k1 = 0;
    int rem = len & 3;
    if (rem > 0) {
        for (int i = 0; i < rem; i++)
            k1 ^= data[nblocks * 4 + i] << (8 * i);
        k1 *= c1;
        k1 = rotl32(k1, 15);
        k1 *= c2;
        h1 ^= k1;
    }

    // --- trộn cuối ---
    h1 ^= len;
    h1 ^= (unsigned int)h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= (unsigned int)h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= (unsigned int)h1 >> 16;

    return h1;
}

std::vector<int> hashFunction::simpleHash (double value) {
    std::string s = std::to_string(value);
    std::vector<int> bits(64);

    for (int i = 0; i < 64; ++i) {
        int h = murmurhash3_32_int(s, seed + i);
        bits[i] = (h & 1);  
    }

    return bits;
}