#include "stdafx.h"	
#include "Guitar.h"

#include <iostream>

Guitar::Guitar()
{
}


Guitar::~Guitar()
{
}

void Guitar::drawStrings()
{
	std::cout << "E" << std::endl;
	std::cout << "A" << std::endl;
	std::cout << "D" << std::endl;
	std::cout << "G" << std::endl;
	std::cout << "H(B)" << std::endl;
	std::cout << "E" << std::endl;
}