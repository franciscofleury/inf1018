#include <ctype.h>
#include <stdio.h>

int string2num (char *s, int base) {
  int a = 0;
  for (; *s; s++) {
    int numeric_value = (isdigit(*s))? (*s - '0') : (*s - 'a' + 10);
    a = a*base + numeric_value;
  }
  return a;
}

int main (void) {
  printf("==> %d\n", string2num("1234", 10));
  printf("==> %d\n", string2num("1234", 10) + 1);
  printf("==> %d\n", string2num("1234", 10) + string2num("1", 10));
  printf("==> %d\n", string2num("777", 8));
  printf("==> %d\n", string2num("777", 10));
  printf("==> %d\n", string2num("11001", 2));
  printf("==> %d\n", string2num("123bc", 16));
  return 0;
}
