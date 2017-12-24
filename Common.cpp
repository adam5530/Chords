#include "Common.h"


Common::Common()
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
