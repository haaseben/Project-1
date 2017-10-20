/**
* \file Pokeball.cpp
*
* \author Team Jorge
*
* Class the implements the Pokeball.
*/

#include "stdafx.h"
#include <string>
#include "Pokeball.h"
#include "Game.h"
#include"VillainVisitor.h"

using namespace std;
using namespace Gdiplus;

/// Villain filename
const wstring PokeBallImageName = L"images/pokeball.png";

/** Constructor
* \param game The game this is a member of
*/
CPokeBall::CPokeBall(CGame *game) :
	CVillain(game, PokeBallImageName)
{
}
/**
* Destructor
*/
CPokeBall::~CPokeBall()
{
}

