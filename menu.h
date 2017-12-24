#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "Common.h"

class menu : public Common
{
private:
	HANDLE console;
	COORD cursorPos;

public:
	menu();
	~menu();

	void drawMenu();
};

#endif // MENU_H