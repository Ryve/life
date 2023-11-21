#include <iostream>
#include "cell.h"


// Получает граничные координаты, в которых надо искать соседей клетки. 
// Обрабатывает ситуацию, когда клетка находится на границе

border get_cell_border(int cellX, int cellY)
{
	border p;

	if (cellX == 0)
	{
		p.startX = 0;
		p.endX = 2;
	}
	else if (cellX == FIELD_WIDTH - 1)
	{
		p.startX = cellX - 1;
		p.endX = FIELD_WIDTH - 1;
	}
	else
	{
		p.startX = cellX - 1;
		p.endX = cellX + 2;
	}

	if (cellY == 0)
	{
		p.startY = 0;
		p.endY = 2;
	}
	else if (cellY == FIELD_HEIGHT - 1)
	{
		p.startY = cellY - 1;
		p.endY = FIELD_HEIGHT - 1;
	}
	else
	{
		p.startY = cellY - 1;
		p.endY = cellY + 2;
	}

	return p;
}

// Подсчитывает число живых соседей клетки

int get_num_of_alive(cell p[][FIELD_HEIGHT], int cellX, int cellY)
{
	int aliveNum = 0;
	border cellBorder = get_cell_border(cellX, cellY);

	for (int x = cellBorder.startX; x < cellBorder.endX; x++)
	{
		for (int y = cellBorder.startY; y < cellBorder.endY; y++)
		{
			if ((p[x][y].isAlive == 1) && (x != cellX) && (y != cellY))
			{
				aliveNum += 1;
			}
		}
	}

	return aliveNum;
}


// Обновляет кадр
void newFrame(cell f[][FIELD_WIDTH])
{
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if ((get_num_of_alive(f, x, y) == 2) || (get_num_of_alive(f, x, y) == 3))
				f[x][y].isAlive = 1;
			else
				f[x][y].isAlive = 0;
		}
	}
}


// Выводит кадр на экран
void printFrame(cell f[][FIELD_WIDTH])
{
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (f[x][y].isAlive == 1)
				std::cout << "* ";
			else
				std::cout << "- ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
}

bool isFrameTheSame(cell f1[][FIELD_WIDTH], cell f2[][FIELD_WIDTH])
{
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (f1[x][y].isAlive != f1[x][y].isAlive)
				return false;				
		}
	}

	return true;
}

void copyFrame(cell f1[][FIELD_WIDTH], cell f2[][FIELD_WIDTH])
{
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			f1[x][y].isAlive = f1[x][y].isAlive;
	
		}
	}
}

