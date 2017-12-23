#include "stdafx.h"	
#include "Guitar.h"


Guitar::Guitar():
	chords(new std::string*[12])
{
	for (unsigned int i = 0; i < 12; ++i)
		chords[i] = new std::string[4];
	chords[0][0] = "C"; chords[0][1] = "c"; chords[0][2] = "C7"; chords[0][3] = "c7";
	chords[1][0] = "C#"; chords[1][1] = "c#"; chords[1][2] = "C#7"; chords[1][3] = "c#7";
	chords[2][0] = "D"; chords[2][1] = "d"; chords[2][2] = "D7"; chords[2][3] = "d7";
	chords[3][0] = "D#"; chords[3][1] = "d#"; chords[3][2] = "D#7"; chords[3][3] = "d#7";
	chords[4][0] = "E"; chords[4][1] = "e"; chords[4][2] = "E7"; chords[4][3] = "e7";
	chords[5][0] = "F"; chords[5][1] = "f"; chords[5][2] = "F7"; chords[5][3] = "f7";
	chords[6][0] = "F#"; chords[6][1] = "f#"; chords[6][2] = "F#7"; chords[6][3] = "f#7";
	chords[7][0] = "G"; chords[7][1] = "g"; chords[7][2] = "G7"; chords[7][3] = "g7";
	chords[8][0] = "G#"; chords[8][1] = "g#"; chords[8][2] = "G#7"; chords[8][3] = "g#7";
	chords[9][0] = "A"; chords[9][1] = "a"; chords[9][2] = "A7"; chords[9][3] = "a7";
	chords[10][0] = "B"; chords[10][1] = "b"; chords[10][2] = "B7"; chords[10][3] = "b7";
	chords[11][0] = "H"; chords[11][1] = "h"; chords[11][2] = "H7"; chords[11][3] = "h7";
}


Guitar::~Guitar()
{
	for (unsigned int i = 0; i < 12; ++i)
	{
		if (!chords[i]) delete[] chords[i];
	}
	if (!chords) delete[] chords;
}

void Guitar::drawStrings()
{
	std::cout << "   e" << std::endl;
	std::cout << "B(H)" << std::endl;
	std::cout << "   G" << std::endl;
	std::cout << "   D" << std::endl;
	std::cout << "   A" << std::endl;
	std::cout << "   E" << std::endl;
}

void Guitar::listChords()
{
	for (unsigned int i = 0; i < 12; ++i)
	{
		for (unsigned int j = 0; j < 4; ++j)
			std::cout << chords[i][j][0] << chords[i][j][1] << "\t";
		std::cout << std::endl;
	}
}

int Guitar::chord() const
{
	return 0;
}