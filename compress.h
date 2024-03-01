#ifndef COMPRESS_H
#define COMPRESS_H

// Define constants for binary representations
const char *BINARY_REPRESENTATIONS[] = {
    "1111", // 0
    "1110", // 1
    "1101", // 2
    "1100", // 3
    "1011", // 4
    "1010", // 5
    "1001", // 6
    "1000", // 7
    "0111", // 8
    "0110"  // 9
};

void compress(const char *filename);
void decompress(const char *filename);

#endif
