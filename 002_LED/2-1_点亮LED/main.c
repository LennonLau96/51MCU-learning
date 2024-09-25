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

void Delayxms(int x)
{
	while (x > 0)
	{
		Delay1ms();
		x--;
	}
}



void main()
{
	int x = 125;
	while (1)
	{
		P2 = 0xFE;
		Delayxms(x);
		P2 = 0xFC;
		Delayxms(x);
		P2 = 0xF8;
		Delayxms(x);
		P2 = 0xF0;
		Delayxms(x);
		P2 = 0xE0;
		Delayxms(x);
		P2 = 0xC0;
		Delayxms(x);
		P2 = 0x80;
		Delayxms(x);
		P2 = 0x00;
		Delayxms(x);
	}
}