#include "../utils/dump.h"
#include <stdio.h>

struct X {
  int a;
  short b;
  int c;
} x;

int main(void) {
  struct X teste;
  teste.a = 0xaaaaaaaa;
  teste.b = 0xbbbb;
  teste.c = 0xcccccccc;
  dump(&teste, sizeof(teste));
  printf("sizeof struct: %lu\n", sizeof(teste));
  return 0;
}
