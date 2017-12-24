#ifndef GUITAR_H
#define GUITAR_H

#include <sstream>

#include "Common.h"

class Guitar : private Common
{
private:
	std::string** chords;	//chords of guitar
	std::string strings[6];	//strings of guitar

	std::string chordsParameters; //g  334553b3  /number->thresholds and strings
								  //b->bare on 3 threshold
	std::string bare;			  //bare parameter

	unsigned int xMarkerPos; //x index of marker
	unsigned int yMarkerPos; //y index of marker

	int numberOfString[6]; //for example [0] first string which threshold

	bool isBare;
	int numberBare;

public:
	Guitar();
	~Guitar();

	void drawStrings();		//function to draw strings of guitar
	void listChords();		//function to list all chords
	void moveCursor();		//function to move cursor in the list of chords
	void resetMarkerPos();	//set marker position 0 0
	void setThresholds();

	bool exit();
};

#endif // GUITAR_H