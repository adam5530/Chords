#include "stdafx.h"
#include "menu.h"


menu::menu()
    :console(GetStdHandle(STD_OUTPUT_HANDLE))
{
}


menu::~menu()
{
}

void menu::drawMenu()
{
	int menu_item = 0, run, x = 7;
	bool running = true;

	gotoXY(18, 5); std::cout << "Main Menu";
	gotoXY(18, 7); std::cout << "->";

	while (running)
	{
		gotoXY(20, 7);  std::cout << "1) Start";
		gotoXY(20, 8);  std::cout << "2) About";
		gotoXY(20, 9); std::cout << "Quit Program";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 9)
		{
			gotoXY(18, x); std::cout << "  ";
			x++;
			gotoXY(18, x); std::cout << "->";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7)
		{
			gotoXY(18, x); std::cout << "  ";
			x--;
			gotoXY(18, x); std::cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) {
			switch (menu_item) {
			case 0: {
				system("cls");
				gotoXY(20, 16);
				std::cout << "Start using program";
				break;
			}
			case 1: {
				system("cls");
				gotoXY(20, 16);
				std::cout << "Help";
				break;
			}

			case 2: {
				system("cls");
				gotoXY(20, 16);
				std::cout << "The program has now terminated!!";
				running = false;
			}
			}
		}

	}

	gotoXY(20, 21);
}

void menu::gotoXY(int x, int y)
{
	cursorPos.X = x;
	cursorPos.Y = y;
	SetConsoleCursorPosition(console, cursorPos);
}