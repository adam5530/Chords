#ifndef MENU_H
#define MENU_H

#include "Common.h"

class menu : private Common
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