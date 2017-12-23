#ifndef GUITAR_H
#define GUITAR_H

#include <iostream>
#include <windows.h>

class Guitar
{
private:
	std::string** chords;
	std::string strings[6];
public:
	Guitar();
	~Guitar();

	void drawStrings();
	void listChords();

	int chord() const;

	bool exit();
};

#endif // GUITAR_H