#include "Common.h"

Common::Common()
	: console(GetStdHandle(STD_OUTPUT_HANDLE))
{
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
