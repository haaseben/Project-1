/**
 * \file Minion.cpp
 *
 * \author Team Jorge
 */

#include "stdafx.h"
#include "Minion.h"
#include "GamePiece.h"
#include "Game.h"


/**
* Constructor
* \param game The game we are in
* \param filename Filename for the image we use
*/
CMinion::CMinion(CGame *game, const std::wstring &filename) :
	CGamePiece(game, filename)
{
	mP = CVector(GetX(), GetY());

}

CMinion::~CMinion()
{
}


/**Handle updates in time of our minion
*
* This is called before we draw and allows us to
* move our minion.We add our speed times the amount
* of time that has elapsed.
* \param elapsed Time elapsed since the class call
*/
void CMinion::Update(double elapsed)
{
	
	mP = CVector(GetX(), GetY());

	CVector newP = mP + mV * elapsed;
	
	SetLocation(newP.X(), newP.Y());

	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();

	///checks to see when the minion gets within 10 pixels of the edge in x direction on right
	if (abs(mSpeedX) > 0 && 500 - GetX() - (wid)+2 <= 2)
	{
		mV = CVector(-mV.X(), mV.Y());
	}

	
	///checks to see when the minion gets within 10 pixels of the edge in x direction on left
	if (GetX() <= -498)
	{
		if (mSpeedX < 0 && GetX() <= 0)
		{
			mV = CVector(-mV.X(), mV.Y());
		}
	}
	
	
	double iegiahg = GetY();
	//checks to see when the minion gets within 10 pixels of the edge in y direction on bottom
	if (abs(mSpeedY) > 0 && 500 - GetY() - (hit) <= 2)
	{
		mV = CVector(mV.X(), -mV.Y());
	}
	
	
	//checks to see when the minion gets within 10 pixels of the edge in y direction on top
	if (mSpeedY < 0 && GetY() <= -490)
	{
		mV = CVector(mV.X(), -mV.Y());
	}
		
}





