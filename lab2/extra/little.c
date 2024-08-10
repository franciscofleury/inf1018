#include <stdio.h>

int is_little() {
	int var;
	var = 1;
	char first_content = *((char*)&var);
	return first_content;
}

int main(void) {
	printf("Essa máquiná é little endian? %d", is_little());
	return 0;
}

