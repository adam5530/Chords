#include "menu.h"

menu::menu()
{
	system("Color 18");
}


menu::~menu()
{
}

void menu::drawMenu()
{
	system("Color 18");
	int x = 7;
	Common::running = true;
	const char* marker = ">";

	Common::gotoXY(18, 5); std::cout << "Main Menu";
	Common::gotoXY(18, 7); std::cout << marker;

	while (Common::running)
	{
		Common::gotoXY(20, 7);  std::cout << "1) Start";
		Common::gotoXY(20, 8);  std::cout << "2) Help";
		Common::gotoXY(20, 9);  std::cout << "3) About program";
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
				running = false;
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
				break;
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

void menu::help()
{
	system("Color 18");

	std::cout << std::endl << std::endl;
	std::cout << "\t\t    Main menu:" << std::endl;
	std::cout << std::endl;
	std::cout << "\t Press down/up  key  to  move cursor" << std::endl;
	std::cout << "\t and pres enter to choose the option." << std::endl;
	std::cout << "\t Press  escape  to  back  main  menu." << std::endl;
	std::cout << std::endl;

	std::cout << "\t How  to  move  in  program???" << std::endl;
	std::cout << "\t If You are in first option - start-" << std::endl;
	std::cout << "\t press up/down/left/right to choose" << std::endl;
	std::cout << "\t the chord. Press  enter to  accept" << std::endl;
	std::cout << "\t the  chord. Press  escape  to back" << std::endl;
	std::cout << "\t main menu" << std::endl;
	
	system("pause>nul");
	system("cls");
}

void menu::aboutProgram()
{
	system("Color 18");
	Common::gotoXY(18, 7); std::cout << "Guitar Chords" << std::endl;
	Common::gotoXY(21, 8); std::cout << "Ver 1.0" << std::endl;

	system("pause>nul");
	system("cls");
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
