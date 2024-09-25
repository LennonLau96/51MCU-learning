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

void Delay(int xms)
{
	while (xms > 0)
	{
		Delay1ms();
		xms--;
	}
}