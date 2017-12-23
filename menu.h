#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <windows.h>

class menu
{
private:
	HANDLE console;
	COORD cursorPos;

public:
	menu();
	~menu();

	void drawMenu();
	void gotoXY(int, int);
};

#endif // MENU_H