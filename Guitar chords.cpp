#include "stdafx.h"
#include "Guitar.h"

int main()
{
	Guitar gtr;
	gtr.drawStrings();
	gtr.listChords();
	while (!gtr.exit())
	{

	}
    return 0;
}

