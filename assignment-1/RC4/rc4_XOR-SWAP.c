/*
    robin verton, dec 2015
    implementation of the RC4 algo
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS 255 // (2^8)-1, bitmask for a byte
#define BYTE_LIMIT 256

// Function prototypes
void swap_values(unsigned char *a, unsigned char *b);
void RC4(char *key, char *plaintext, unsigned char *ciphertext);
void PRGA(unsigned char *S, char *plaintext, unsigned char *ciphertext);
void KSA(char *key, unsigned char *S);

void swap_values(unsigned char *a, unsigned char *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void KSA(char *key, unsigned char *S) {

  uint32_t len = strlen(key);
  int j = 0;

  for (int i = 0; i < BYTE_LIMIT; i++) {
    S[i] = i;
  }

  for (int i = 0; i < BYTE_LIMIT; i++) {
    j = (j + S[i] + key[i % len]) & BITS;

    swap_values(&S[i], &S[j]);
  }
}

void PRGA(unsigned char *S, char *plaintext, unsigned char *ciphertext) {

  int i = 0;
  int j = 0;

  for (size_t n = 0, len = strlen(plaintext); n < len; n++) {
    i = (i + 1) & BITS;
    j = (j + S[i]) & BITS;

    swap_values(&S[i], &S[j]);
    uint32_t rnd = S[(S[i] + S[j]) & BITS];

    ciphertext[n] = rnd ^ plaintext[n];
  }
}

void RC4(char *key, char *plaintext, unsigned char *ciphertext) {

  unsigned char S[BYTE_LIMIT];
  KSA(key, S);

  PRGA(S, plaintext, ciphertext);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <key> <plaintext>", argv[0]);
    return EXIT_FAILURE;
  }

  unsigned char *ciphertext =
      (unsigned char *)malloc(sizeof(int) * strlen(argv[2]));
  if (ciphertext == NULL) {
    fprintf(stderr, "[-] Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  RC4(argv[1], argv[2], ciphertext);

  for (size_t i = 0, len = strlen(argv[2]); i < len; i++) {
    printf("\\x%02hhx ", ciphertext[i]);
  }

  free(ciphertext);
  return EXIT_SUCCESS;
}
