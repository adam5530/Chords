#include "Guitar.h"
#include "menu.h"

using namespace std;

int main()
{
	//menu *mn = new menu;
	//mn->drawMenu();
	Guitar gtr;
	
	
	//while (!gtr.exit())
	//{
		gtr.drawStrings();
		gtr.listChords();
		gtr.resetMarkerPos();
		gtr.moveCursor();
	//}
    return 0;
}