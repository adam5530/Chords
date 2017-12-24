#include "Common.h"

Common::Common()
	: console(GetStdHandle(STD_OUTPUT_HANDLE))
{
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = 22;
	rect.Right = 100;
	SetConsoleWindowInfo(console, true, &rect);
}


Common::~Common()
{
}

void Common::gotoXY(int x, int y)
{
	cursorPos.X = x;
	cursorPos.Y = y;
	SetConsoleCursorPosition(console, cursorPos);
}
