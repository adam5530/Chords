#include "Guitar.h"
#include "menu.h"

using namespace std;

int main()
{
	menu mn;
	Guitar gtr;
	int mainMenu = 0;
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		mainMenu:
		mn.resetMenuItem();
		mn.drawMenu();
		system("cls");
		if (mn.getMenuItem() == 3) //exit program
		{
			system("cls");
			return EXIT_SUCCESS;
		}
		if (mn.getMenuItem() == 1) //go to help
		{
			mn.help();
			goto mainMenu;
		}
		if (mn.getMenuItem() == 2) //go to about author
		{
			mn.aboutAutor();
			goto mainMenu;
		}
		while (!gtr.exit())
		{
			gtr.setDefaultParameters();
			gtr.drawStrings();
			gtr.listChords();
			gtr.resetMarkerPos();
			gtr.moveCursor();
			goto mainMenu;
		}
	}
    return 0;
}