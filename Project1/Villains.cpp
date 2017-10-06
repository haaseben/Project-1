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

CVillains(CGame * game, const std::wstring & filename)
	CGame(game, filename)
{
	mLocationx = 200;
	mLocationy = 200;
}
	

CVillains::~CVillains()
{
}


void CVillains::SetLocation(double x, double y)
{
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mLocationX * elapsed,
		GetY() + mLocationY * elapsed);
}