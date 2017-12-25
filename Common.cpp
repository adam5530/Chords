#include "Common.h"

Common::Common()
	: console(GetStdHandle(STD_OUTPUT_HANDLE))
{
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = 22;
	rect.Right = 50;
	SetConsoleWindowInfo(console, true, &rect);

	//////////////////////////////////////////////// not blinking
	CONSOLE_CURSOR_INFO     cursorInfo;			  // underscore
	GetConsoleCursorInfo(console, &cursorInfo);   //
	cursorInfo.bVisible = false;				  //
	SetConsoleCursorInfo(console, &cursorInfo);   //
	////////////////////////////////////////////////

	/////////////////////////////////////////////////// hide scrollbars
	CONSOLE_SCREEN_BUFFER_INFO info;				 //
	GetConsoleScreenBufferInfo(console, &info);	     //
	COORD new_size =								 //
	{												 //
		info.srWindow.Right - info.srWindow.Left + 1,//
		info.srWindow.Bottom - info.srWindow.Top + 1 //
	};												 //
	SetConsoleScreenBufferSize(console, new_size);   //
	///////////////////////////////////////////////////
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
