#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum) {
  unsigned char setup_byte = word >> (bytenum * 8);
  printf("Setup_Byte: %02x\n", setup_byte);
  char mask = 0xff;
  return setup_byte & mask;
}

int main(void) {
  packed_t test_word = 0x87654321;
  printf("Test word: %x\nByte:%02x\n", test_word, xbyte(test_word, 1));
  return 0;
}

