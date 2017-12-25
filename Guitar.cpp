#include "Guitar.h"

Guitar::Guitar()
	: chords(new std::string*[12])
	, isBare{false}
{
	for (int i = 0; i < 12; ++i)
		chords[i] = new std::string[4];
	//chords[0] -- [2] chord, [3] -- [8] thresholds, [9] -- [10] barre threshold
	chords[0][0] = "C  010230  "; chords[0][1] = "c  345533b3"; chords[0][2] = "C7 013230  "; chords[0][3] = "c7 343530b3";
	chords[1][0] = "C# 466644b4"; chords[1][1] = "c# 456644b4"; chords[1][2] = "C#7464644b4"; chords[1][3] = "c#7454640b4";
	chords[2][0] = "D  23200x  "; chords[2][1] = "d  13200x  "; chords[2][2] = "D7 21200x  "; chords[2][3] = "d7 11200x  ";
	chords[3][0] = "D# 688866b6"; chords[3][1] = "d# 678866b6"; chords[3][2] = "D#7686866b6"; chords[3][3] = "d#7666866b6";
	chords[4][0] = "E  001220  "; chords[4][1] = "e  000220  "; chords[4][2] = "E7 001020  "; chords[4][3] = "e7 000020  ";
	chords[5][0] = "F  112331b1"; chords[5][1] = "f  111331b1"; chords[5][2] = "F7 112131b1"; chords[5][3] = "f7 111131b1";
	chords[6][0] = "F# 223442b2"; chords[6][1] = "f# 222442b2"; chords[6][2] = "F#7223242b2"; chords[6][3] = "f#7222242b2";
	chords[7][0] = "G  300023  "; chords[7][1] = "g  333553b3"; chords[7][2] = "G7 100023  "; chords[7][3] = "g7 333353b3";
	chords[8][0] = "G# 445664b4"; chords[8][1] = "g# 444664b4"; chords[8][2] = "G#7445464b4"; chords[8][3] = "g#7444464b4";
	chords[9][0] = "A  022200  "; chords[9][1] = "a  012200  "; chords[9][2] = "A7 020200  "; chords[9][3] = "a7 010200  ";
	chords[10][0] = "B  133311b1"; chords[10][1] = "b  123311b1"; chords[10][2] = "B7 131311b1"; chords[10][3] = "b7 121311b1";
	chords[11][0] = "H  244422b2"; chords[11][1] = "h  234422b2"; chords[11][2] = "H7 242422b2"; chords[11][3] = "h7 232422b2";
	
	strings[0] = "e"; strings[1] = "H"; strings[2] = "G";
	strings[3] = "D"; strings[4] = "A"; strings[5] = "E";
	setDefaultParameters();
}


Guitar::~Guitar()
{
	for (unsigned int i = 0; i < 12; ++i)
	{
		if (!chords[i]) 
			delete[] chords[i];
	}
	if (!chords) 
		delete[] chords;
}

void Guitar::drawStrings()
{
	std::string bare = "|-";
	bare += 219;
	bare += '-';
	std::string pressed = "|-O-";
	std::string empty = "|---";
	std::wcout << "         1   2   3   4   5   6   7   8" << std::endl;
	for (int i = 0; i < 6; ++i) //strings E A D G H e
	{
		for (int j = 0; j < 8; ++j) //thresholds 1 2 3 4 5 
		{
			if (j == 0 && numberOfString[i] == -10) 
				std::cout << "   " << strings[i][0] << "  X";
			else if (j == 0)
				std::cout << "   " << strings[i][0] << "   ";

			if ((isBare == true) && (j == numberBare - 1))
				std::wcout << bare[0] << bare[1] << bare[2] << bare[3];

			else if (numberOfString[i] == j)
				std::cout << pressed[0] << pressed[1] << pressed[2] << pressed[3];

			else
				std::cout << empty[0] << empty[1] << empty[2] << empty[3];
		}
		std::wcout << std::endl;
	}
}

void Guitar::listChords()
{
	system("Color 18");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_GREEN|FOREGROUND_BLUE);
	std::cout << std::endl;
	for (unsigned int i = 0; i < 12; ++i) //chord C, D, E
	{
		for (unsigned int j = 0; j < 4; ++j) //chord C moll, C dur, C dur 7
			std::cout << "\t" << chords[i][j][0] << chords[i][j][1] << chords[i][j][2];
		std::cout << "\t" << std::endl;
	}
	std::cout << "      Press ESC to back to main menu\t" << std::endl;
}

void Guitar::resetMarkerPos()
{
	xMarkerPos = 0;
	yMarkerPos = 0;
}

bool Guitar::exit()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return true;
	return false;
}


void Guitar::moveCursor(unsigned int x, unsigned int y)
{
	//static unsigned int x = 6, y = 8;
	bool running = true;
	const char* marker = "*";
	Common::gotoXY(x, y); std::cout << marker;
	while (running)
	{
		system("pause>nul");
		if (GetAsyncKeyState(VK_DOWN) && y < 19)
		{
			Common::gotoXY(x, y); std::cout << "  ";
			y++;
			yMarkerPos++;
			Common::gotoXY(x, y); std::cout << marker;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && y > 8)
		{
			Common::gotoXY(x, y); std::cout << "  ";
			y--;
			yMarkerPos--;
			Common::gotoXY(x, y); std::cout << marker;
			continue;
		}

		if (GetAsyncKeyState(VK_LEFT) && x > 13)
		{
			Common::gotoXY(x, y); std::cout << "  ";
			x -= 8;
			xMarkerPos--;
			Common::gotoXY(x, y); std::cout << marker;
			continue;
		}

		if (GetAsyncKeyState(VK_RIGHT) && x < 28)
		{
			Common::gotoXY(x, y); std::cout << "  ";
			x += 8;
			xMarkerPos++;
			Common::gotoXY(x, y); std::cout << marker;
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			setThresholds();
			drawStrings();
			listChords();
			Common::gotoXY(x, y); std::cout << marker;
			continue;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("cls");
			running = false;
		}
	}
}

void Guitar::setThresholds()
{
	chordsParameters = "";
	bare = "";
	numberBare = 0;
	isBare = false;
	for (int i = 0; i < 6; ++i)
		numberOfString[i] = 0;
	for (int i = 3; i < 9; ++i)
		chordsParameters += chords[yMarkerPos][xMarkerPos][i];
	for (int i = 9; i < 11; ++i)
		bare += chords[yMarkerPos][xMarkerPos][i];

	std::stringstream converted(chordsParameters);
	int temp = 0;
	converted >> temp;

	for (int i = 5; i >= 0; --i)
	{
		if (chordsParameters[i] == 'x') //if silent, write -10 to array
		{
			numberOfString[i] = -10;
		}
		else
		{
			int x = temp - (temp / 10) * 10;
			numberOfString[i] = x - 1;
			temp /= 10;
		}
	}

	if (bare[0] == 'b')
	{
		isBare = true;
		std::string tempBare = bare.substr(1, 2);
		std::stringstream convertedBare(tempBare);
		convertedBare >> numberBare;
	}
}

void Guitar::setDefaultParameters()
{
	isBare = false;
	numberOfString[0] = -1; numberOfString[1] = 0; numberOfString[2] = -1;
	numberOfString[3] = 1; numberOfString[4] = 2; numberOfString[5] = -1;
}