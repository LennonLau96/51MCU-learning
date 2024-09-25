#include <REGX52.H>

void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

void delay(int x)
{
	while (x > 0)
	{
		Delay1ms();
		x--;
	}
}

void main()
{
	while (1)
	{
		if (P3_1 == 0)
		{
			delay(20);
			while (P3_1 == 0);
			delay(20);
			P2_0 = ~P2_0;
		}
	}
}