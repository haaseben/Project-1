/**
* \file Juicer.cpp
*
* \author Team Jorge
*
* Class the implements Juicer.
*/

#include "stdafx.h"
#include <string>
#include "Juicer.h"
#include "Game.h"
#include"VillainVisitor.h"

using namespace std;
using namespace Gdiplus;

/// Villain Filename
const wstring JuicerImageName = L"images/Juicer.png";

/** Constructor
* \param game The game this is a member of
*/
CJuicer::CJuicer(CGame *game) :
	CVillain(game, JuicerImageName)
{

}

/**
* Destructor
*/
CJuicer::~CJuicer()
{
}

bool CJuicer::GruOrNot()
{
	return false;
}

int CJuicer::GetMultiplier()
{
	return mMultiplier;
}