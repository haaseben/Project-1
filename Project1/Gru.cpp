/**
* \file Arya.cpp
*
* \author Team Jorge
*
* Class the implements Gru.
*/

#include "stdafx.h"
#include <string>
#include "Gru.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;

/// Gru filename
const wstring GruImageName = L"images/gru.png";

/** Constructor
* \param game The game this is a member of
*/
CGru::CGru(CGame *game) :
	CGamePiece(game, GruImageName)
{
}
/**
* Destructor
*/
CGru::~CGru()
{
}


