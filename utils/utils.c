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

void num2string(char *s, int num, int base) {
  int used = num;
  for (;used>0;) {
    int unity = used;
    int base_acc = 1;
    while (unity > base) {
      unity = unity / base;
      base_acc = base_acc * base;
    }
    used = used % base_acc;
    if (unity >= 10) {
      *s = unity -10 + 'a';
    } else {
      *s = unity + '0';
    }
    s++;
  }
  *s = '\0';
}
