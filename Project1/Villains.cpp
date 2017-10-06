/**
* \file Villains.cpp
*
* \author Team jorge
*
* This will serve as the template for all 3 villains.
*/


#include "stdafx.h"
#include "Villains.h"
#include "GamePiece.h"
#include "Game.h"

CVillains::CVillains(CGame *game, const std::wstring & filename) :
	CGamePiece(game, filename)
{
}
	
CVillains::~CVillains()
{
}