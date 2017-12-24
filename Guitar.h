#ifndef GUITAR_H
#define GUITAR_H

#include <iostream>

#include "Common.h"

class Guitar : public Common
{
private:
	std::string** chords;
	std::string strings[6];

	HANDLE console;
	COORD cursorPos;
	SMALL_RECT rect;

	int xChords;
	int yChords;

public:
	Guitar();
	~Guitar();

	void drawStrings();
	void listChords();
	void moveCursor();

	int chord() const;

	bool exit();
};

#endif // GUITAR_H