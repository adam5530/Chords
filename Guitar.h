#ifndef GUITAR_H
#define GUITAR_H

#include <iostream>
#include <windows.h>

class Guitar
{
private:
	std::string** chords;
	std::string strings[6];

	HANDLE console;
	COORD cursorPos;
	SMALL_RECT rect;

public:
	Guitar();
	~Guitar();

	void drawStrings();
	void listChords();
	void gotoXY(int, int);
	void moveCursor();

	int chord() const;

	bool exit();
};

#endif // GUITAR_H