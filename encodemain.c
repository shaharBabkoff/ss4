#include "compress.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s -c/-d filename\n", argv[0]);
        return 1;
    }

    // Check if the user wants to compress or decompress
    if (strcmp(argv[1], "-c") == 0) {
        compress(argv[2]); // Call compress function
    } else if (strcmp(argv[1], "-d") == 0) {
        decompress(argv[2]); // Call decompress function
    } else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
