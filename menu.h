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
	void resetMenuItem();
	void help();
	void aboutProgram();

	int getMenuItem() const;

	bool exitMenu();
};

#endif // MENU_H