#include <stdio.h>

unsigned char switch_byte(unsigned char x) {
  unsigned char little_half = x & 0x0f;
  unsigned char big_half = x & 0xf0;
  printf("little: %02x\n", little_half);
  printf("big: %02x\n", big_half);
  little_half = little_half << 4;
  big_half = big_half >> 4;
  printf("little: %02x\n", little_half);
  printf("big: %02x\n", big_half);
  unsigned char result = little_half | big_half;
  return result;
}

int main(void) {
  printf("==> %02x\n", switch_byte(0xab));
}  
