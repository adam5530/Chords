#ifndef COMMON_H
#define COMMON_H

#include <windows.h>

class Common
{
private:
	HANDLE console;
	COORD cursorPos;

protected:
	void gotoXY(int, int);

public:
	Common();
	~Common();
};

#endif // COMMON_H