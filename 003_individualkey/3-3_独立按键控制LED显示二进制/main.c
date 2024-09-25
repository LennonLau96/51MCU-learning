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

void delay(unsigned int x)
{
	while (x > 0)
	{
		Delay1ms();
		x--;
	}
}

//void main()
//{
//	unsigned char led_bin = 0xFF;
//	while (1)
//	{
//		if (P3_1 == 0)
//		{
//			delay(20);
//			while (P3_1 == 0);
//			delay(20);
//			
//			if (led_bin > 0x00)
//			{
//				led_bin = led_bin - 0x01;
//			}
//			else
//			{
//				led_bin = 0xFF;
//			}
//			
//			P2 = led_bin;
//		}
//	}
//}

void main()
{
	P2 = 0x07;
	while (1)
	{
		if (P3_1 == 0)
		{
			delay(20);
			while (P3_1 == 0);
			delay(20);
			
			if (P2 > 0x00)
			{
				P2 = P2 - 1;
			}
			else
			{
				P2 = 0xFF;
			}
		}
	}
}