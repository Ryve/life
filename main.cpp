#include <iostream>
#include "cell.h"

int main()
{

	cell f[FIELD_WIDTH][FIELD_HEIGHT];

	cell fPrev[FIELD_WIDTH][FIELD_HEIGHT];

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			f[x][y].isAlive = (bool)(rand() % 2);
		}
	}

	printFrame(f);

	do
	{		
		copyFrame(fPrev, f);
		newFrame(f);
		printFrame(f);

	} while (!isFrameTheSame(f, fPrev));

	return 0;
}