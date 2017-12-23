#ifndef GUITAR_H
#define GUITAR_H

#include <iostream>

class Guitar
{
private:
	std::string** chords;
public:
	Guitar();
	~Guitar();

	void drawStrings();
	void listChords();
	int chord() const;
};

#endif // GUITAR_H