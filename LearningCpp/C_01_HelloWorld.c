#include <stdio.h>

void foo();

int main(void)
{
	int i = 1, j = 2;
	foo();

	printf("Hello World!.\n");
	return 0;
}

void foo() {
	int i, j;
	i = 10;
	j = 20;
	printf("Hello ShiShi.\n");
}