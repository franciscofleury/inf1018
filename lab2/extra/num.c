#include <stdio.h>

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

int main(void) {
	char buffer[100];
	char buffer2[100];
	num2string(buffer, 234, 10);
	printf("==> %s\n", buffer);
	num2string(buffer2, 300, 16);
	printf("==> %s\n", buffer2);
	return 0;
}
