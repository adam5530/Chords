#include "Guitar.h"
#include "menu.h"

int main()
{
	menu mn;
	Guitar gtr;
	bool mainMenu = true; //true->in main menu, false->not in main menu
	do
	{
		if (mainMenu == true) //go to main menu
		{
			mn.resetMenuItem();
			mn.drawMenu();
			system("cls");
			mainMenu = false;
		}
		if (mn.getMenuItem() == 3) //exit program
		{
			system("cls");
			return EXIT_SUCCESS;
		}
		if (mn.getMenuItem() == 1) //go to help
		{
			mn.help();
			mainMenu = true;
		}
		if (mn.getMenuItem() == 2) //go to about author
		{
			mn.aboutProgram();
			mainMenu = true;
		}
		while (!gtr.exit() && mainMenu == false)
		{
			gtr.setDefaultParameters();
			gtr.drawStrings();
			gtr.listChords();
			gtr.resetMarkerPos();
			gtr.moveCursor(6, 8);
			mainMenu = true;
		}
	} while (true);
    return 0;
}