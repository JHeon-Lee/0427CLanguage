#include <stdio.h>

/*
	기수(radix)
	10진수(Decimal)
	2진수(binary)
	- 0b
	8진수(Octal)
	- 0
	16진수(Hexa_Decimal)
	- 0x
*/

int main()
{
	int d = 100;
	int b = 0b100;
	int o = 0100;
	int hd = 0x100;

	printf("%d\n", d);
	printf("%d\n", b);
	printf("%d\n", o);
	printf("%d\n", hd);

	int i = 100'000'000; // '는 출력에 생략됨
	printf("%d", i);

	return 0;
}