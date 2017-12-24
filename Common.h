#ifndef COMMON_H
#define COMMON_H

#include <windows.h>
#include <iostream>

class Common
{
private:
	HANDLE console;
	COORD cursorPos;
	SMALL_RECT rect;

protected:
	void gotoXY(int, int);

public:
	Common();
	~Common();
};

#endif // COMMON_H