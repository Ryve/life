#pragma once
#define FIELD_WIDTH 10
#define FIELD_HEIGHT 10




struct cell
{
	unsigned int isAlive : 1;
};

struct border
{
	int startX;
	int startY;
	int endX;
	int endY;
};


border get_cell_border(int cellX, int cellY);
int get_num_of_alive(cell p[][FIELD_HEIGHT], int cellX, int cellY);
void newFrame(cell f[][FIELD_WIDTH]);
void printFrame(cell f[][FIELD_WIDTH]);
bool isFrameTheSame(cell f1[][FIELD_WIDTH], cell f2[][FIELD_WIDTH]);
void copyFrame(cell f1[][FIELD_WIDTH], cell f2[][FIELD_WIDTH]);
