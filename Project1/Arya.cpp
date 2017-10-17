/**
* \file Arya.cpp
*
* \author Team Jorge
*
* Class the implements Arya.
*/

#include "stdafx.h"
#include <string>
#include "Arya.h"
#include "Game.h"
#include"VillainVisitor.h"


using namespace std;
using namespace Gdiplus;

/// Villain filename
const wstring AryaImageName = L"images/Arya.png";

/** Constructor
* \param game The game this is a member of
*/
CArya::CArya(CGame *game) :
	CVillain(game, AryaImageName)
{
}
/**
* Destructor
*/
CArya::~CArya()
{
}

bool CArya::GruOrNot()
{
	return false;
}

int CArya::GetMultiplier()
{
	return mMultiplier;
}