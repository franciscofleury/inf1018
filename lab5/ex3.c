#include "../utils/dump.h"
#include <stdio.h>

struct X1 {
  char c1;
  int i;
  char c2;
};

struct X2 {
  long l;
  char c;
};

struct X3 {
  int i;
  char c1;
  char c2;
};

struct X4 {
  struct X2 x;
  char c;
};

struct X5 {
  char c1;
  char c2;
  char c3;
};

struct X6 {
  short s1;
  int i;
  char c[3];
  short s2;
};

union U1 {
  int i;
  char c[5];
};

union U2 {
  short s;
  char c[5];
};

int main(void) {
  // ---- STRUCT X1 ----
  struct X1 x1_test;
  x1_test.c1 = 0xff;
  x1_test.i = 0x99999999;
  x1_test.c2 = 0xee;
  printf("---- STRUCT X1 ----\n");
  dump(&x1_test, sizeof(x1_test));
  printf("Tamanho: %lu\n\n", sizeof(x1_test));

  // ---- STRUCT X2 ----
  struct X2 x2_test;
  x2_test.l = 0x9999999999999999;
  x2_test.c = 0xff;
  printf("---- STRUCT X2 ----\n");
  dump(&x2_test, sizeof(x2_test));
  printf("Tamanho: %lu\n\n", sizeof(x2_test));

  // ---- STRUCT X3 ----
  struct X3 x3_test;
  x3_test.i = 0x99999999;
  x3_test.c1 = 0xff;
  x3_test.c2 = 0xee;
  printf("---- STRUCT X3 ----\n");
  dump(&x3_test, sizeof(x3_test));
  printf("Tamanho: %lu\n\n", sizeof(x3_test));
 
  // ---- STRUCT X4 ----
  struct X4 x4_test;
  x4_test.x = x2_test;
  x4_test.c = 0xee;
  printf("---- STRUCT X4 ----\n");
  dump(&x3_test, sizeof(x4_test));
  printf("Tamanho: %lu\n\n", sizeof(x4_test));

  // ---- STRUCT X5 ----
  struct X5 x5_test;
  x5_test.c1 = 0xff;
  x5_test.c2 = 0xee;
  printf("---- STRUCT X5 ----\n");
  dump(&x5_test, sizeof(x5_test));
  printf("Tamanho: %lu\n\n", sizeof(x5_test));

  // ---- STRUCT X6 ----
  struct X6 x6_test;
  x6_test.s1 = 0x9999;
  x6_test.i = 0x88888888;
  x6_test.c[0] = 0xff;
  x6_test.c[1] = 0xee;
  x6_test.c[2] = 0xdd;
  x6_test.s2 = 0x7777;
  printf("---- STRUCT X6 ----\n");
  dump(&x6_test, sizeof(x6_test));
  printf("Tamanho: %lu\n\n", sizeof(x6_test));

  // ---- UNION U1 ----
  union U1 u1_test;
  u1_test.i = 0x99999999;
  u1_test.c[4] = 0xbb;
  printf("---- UNION U1 ----\n");
  dump(&u1_test, sizeof(u1_test));
  printf("Tamanho: %lu\n\n", sizeof(u1_test));

  // ---- UNION U2 ----
  union U2 u2_test;
  u2_test.s = 0x9999;
  u2_test.c[2] = 0xff;
  u2_test.c[3] = 0xee;
  u2_test.c[4] = 0xdd; 
  printf("---- UNION U2 ----\n");
  dump(&u2_test, sizeof(u2_test));
  printf("Tamanho: %lu\n\n", sizeof(u2_test));

  return 0;
}
 
