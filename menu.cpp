#include "menu.h"

menu::menu()
{
}


menu::~menu()
{
}

void menu::drawMenu()
{
	system("Color 18");
	int x = 7;
	bool running = true;
	const char* marker = "*";

	Common::gotoXY(18, 5); std::cout << "Main Menu";
	Common::gotoXY(18, 7); std::cout << marker;

	while (running)
	{
		Common::gotoXY(20, 7);  std::cout << "1) Start";
		Common::gotoXY(20, 8);  std::cout << "2) Help";
		Common::gotoXY(20, 9);  std::cout << "3) About autor";
		Common::gotoXY(20, 10); std::cout << "Quit Program";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 10)
		{
			Common::gotoXY(18, x); std::cout << "  ";
			x++;
			Common::gotoXY(18, x); std::cout << marker;
			Common::menu_item++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 7)
		{
			Common::gotoXY(18, x); std::cout << "  ";
			x--;
			Common::gotoXY(18, x); std::cout << marker;
			Common::menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) {
			switch (Common::menu_item) {
			case 0: {
				system("cls");
				Common::gotoXY(20, 16);
				return;
				break;
			}
			case 1: {
				system("cls");
				Common::gotoXY(20, 16);
				break;
			}
			case 2: {
				system("cls");
				running = false;
				break;
			}
			case 3: {
				system("cls");
				Common::gotoXY(20, 16);
				running = false;
			}
			}
		}

	}
	Common::gotoXY(20, 21);
}

void menu::resetMenuItem()
{
	menu_item = 0;
}

void menu::aboutAutor()
{
	system("Color 18");
	Common::gotoXY(22, 7); std::cout << "Adam Lacki" << std::endl;
	Common::gotoXY(21, 8); std::cout << "Lodz - Poland" << std::endl;
	Common::gotoXY(20, 9); std::cout << "C++ programmer :)" << std::endl;
	system("pause>nul");
}

int menu::getMenuItem() const
{
	return menu_item;
}

bool menu::exitMenu()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return false;
	return true;
}
