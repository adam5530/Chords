#include "stdafx.h"
#include "Guitar.h"
#include "menu.h"

using namespace std;

int main()
{
	//menu *mn = new menu;
	//mn->drawMenu();
	Guitar gtr;
	gtr.drawStrings();
	gtr.listChords();
	gtr.moveCursor();
	
	/*while (!gtr.exit())
	{

	}*/
    return 0;
}