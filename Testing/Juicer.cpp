/**
* file juicer.cpp
*
* author Team Jorge
*
*/

#include "stdafx.h"
#include "Juicer.h"
#include "Game.h"
#include <string>

///Juicer File

const wstring JuicerImageName = L"images/juicer.png";

/** Constuctor
*Game that this villain is on
*/
CJuicer::CJuicer(CGame *game) :
	CVillains(game, JuicerImageName)
{
}

/**
*Destructor
*/
CJuicer::~CJuicer()
{
}
