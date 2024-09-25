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
	int led_num = 1;
	P2 = 0xFE;
	
	while (1)
	{
		if (P3_1 == 0)
		{
			delay(20);
			while (P3_1 == 0);
			delay(20);
			
			led_num++;
			
			if (led_num > 8)
			{
				led_num = 1;
			}
			
			P2 = ~(0x01 << (led_num-1));
		}
		
		if (P3_0 == 0)
		{
			delay(20);
			while (P3_0 == 0);
			delay(20);
			
			led_num--;
			
			if (led_num < 1)
			{
				led_num = 8;
			}
			
			P2 = ~(0x01 << (led_num-1));
		}
	}
}