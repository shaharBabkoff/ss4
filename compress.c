#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void compress(const char *filename) {
    // Open the input file
    FILE *inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Create the output file
    char outputFilename[256];
    snprintf(outputFilename, sizeof(outputFilename), "%s.bin", filename);
    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error creating output file\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Read each character from the input file
    int c;
    int digitCount=0;
    while ((c = fgetc(inputFile)) != EOF) {
        // Check if the character is a digit
        if ('0' <= c && c <= '9') {
            // Get the binary representation index
            int index = c - '0';

            // Write the binary representation to the output file
            size_t binaryLen = strlen(BINARY_REPRESENTATIONS[index]);
            fwrite(BINARY_REPRESENTATIONS[index], sizeof(char), binaryLen, outputFile);
            digitCount++;
        }

    }
     //  if the number of digits is odd
    if (digitCount % 2 != 0) {
        const char *padding = "0000";
        fwrite(padding, sizeof(char), strlen(padding), outputFile);
    }


    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Compression successful. Output saved to %s\n", outputFilename);
}

void decompress(const char *filename) {
    // Open the input file
    FILE *inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Create the output file
    char outputFilename[256];
   snprintf(outputFilename, sizeof(outputFilename), "%s.txt", filename);
  
    FILE *outputFile = fopen(outputFilename, "wb");

    if (outputFile == NULL) {
        fprintf(stderr, "Error creating output file\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Read binary representations and convert to digits
    char binaryBuffer[5]; // Buffer to read 4-character binary representations
    while (fread(binaryBuffer, sizeof(char), 4, inputFile) == 4) {
        binaryBuffer[4] = '\0'; // Null-terminate the buffer

        // Find the index of the binary representation in the array
        int index;
        for (index = 0; index < 10; ++index) {
            if (strcmp(binaryBuffer, BINARY_REPRESENTATIONS[index]) == 0) {
                break;
            }
        }

        // Write the corresponding digit to the output file
        fprintf(outputFile, "%d", index);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Decompression successful. Output saved to %s\n", outputFilename);
}
