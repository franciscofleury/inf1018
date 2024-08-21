#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int string2num (char *s, int base) {
  int a = 0;
  for (; *s; s++) {
    int numeric_value = (isdigit(*s))? (*s - '0') : (*s - 'a' + 10);
    a = a*base + numeric_value;
  }
  return a;
}
