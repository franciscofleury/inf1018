#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n) {
  int rotate = n % 8;
  unsigned char copy = x;
  copy = copy >> (8 - rotate);
  x = x << rotate;
  unsigned char result = x | copy;
  return result;
}

int main(void) {
  printf("==> %02x\n", rotate_left(0xab, 4));
  return 0;
}  
