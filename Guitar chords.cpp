#include "Guitar.h"
#include "menu.h"

using namespace std;

int main()
{
	menu mn;
	Guitar gtr;
	while (!GetAsyncKeyState(VK_ESCAPE))
	{
		mainMenu:
		mn.resetMenuItem();
		mn.drawMenu();
		system("cls");
		if (mn.getMenuItem() == 2)
			mn.aboutAutor();
		while (!gtr.exit())
		{
			gtr.drawStrings();
			gtr.listChords();
			gtr.resetMarkerPos();
			gtr.moveCursor();
			goto mainMenu;
		}
	}
    return 0;
}