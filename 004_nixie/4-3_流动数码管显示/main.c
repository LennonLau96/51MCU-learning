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
	
	

void led(int id, int num)
{
	char nixie_show[17] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};
	
	switch (id)
	{
		case 1: P2_4 = 1; P2_3 = 1; P2_2 = 1; break;
		case 2: P2_4 = 1; P2_3 = 1; P2_2 = 0; break;
		case 3: P2_4 = 1; P2_3 = 0; P2_2 = 1; break;
		case 4: P2_4 = 1; P2_3 = 0; P2_2 = 0; break;
		case 5: P2_4 = 0; P2_3 = 1; P2_2 = 1; break;
		case 6: P2_4 = 0; P2_3 = 1; P2_2 = 0; break;
		case 7: P2_4 = 0; P2_3 = 0; P2_2 = 1; break;
		case 8: P2_4 = 0; P2_3 = 0; P2_2 = 0; break;
		default: break;
	}
	
	P0 = nixie_show[num];
		
}

void main()
{
	int num = 0;
	int id = 0;
	
	while (1)
	{
		
		for (num=0; num <= 15; num++)
		{
			id = (num % 8) + 1;
			led(id, num);
			delay(500);
			led(id, 16);
			delay(1);
		}
	}
}