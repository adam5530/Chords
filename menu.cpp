#include "menu.h"


menu::menu()
{
}


menu::~menu()
{
}

void menu::drawMenu()
{
	int menu_item = 0, run, x = 7;
	bool running = true;

	Common::gotoXY(18, 5); std::cout << "Main Menu";
	Common::gotoXY(18, 7); std::cout << "->";

	while (running)
	{
		Common::gotoXY(20, 7);  std::cout << "1) Start";
		Common::gotoXY(20, 8);  std::cout << "2) About";
		Common::gotoXY(20, 9); std::cout << "Quit Program";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 9)
		{
			Common::gotoXY(18, x); std::cout << "  ";
			x++;
			Common::gotoXY(18, x); std::cout << "->";
			menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7)
		{
			Common::gotoXY(18, x); std::cout << "  ";
			x--;
			Common::gotoXY(18, x); std::cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) {
			switch (menu_item) {
			case 0: {
				system("cls");
				Common::gotoXY(20, 16);
				std::cout << "Start using program";
				break;
			}
			case 1: {
				system("cls");
				Common::gotoXY(20, 16);
				std::cout << "Help";
				break;
			}

			case 2: {
				system("cls");
				Common::gotoXY(20, 16);
				std::cout << "The program has now terminated!!";
				running = false;
			}
			}
		}

	}

	Common::gotoXY(20, 21);
}