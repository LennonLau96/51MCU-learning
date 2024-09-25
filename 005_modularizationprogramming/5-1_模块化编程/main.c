#include <REGX52.H>
#include "nixie.h"

void main()
{
	int id = 1;
	while (1)
	{
		for (id=1; id <= 8; id++)
		{
			led(id, id);
		}
	}
}