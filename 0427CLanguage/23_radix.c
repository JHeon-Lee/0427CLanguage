#include <stdio.h>

/*
	���(radix)
	10����(Decimal)
	2����(binary)
	- 0b
	8����(Octal)
	- 0
	16����(Hexa_Decimal)
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

	int i = 100'000'000; // '�� ��¿� ������
	printf("%d", i);

	return 0;
}