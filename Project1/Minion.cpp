#include "stdafx.h"
#include "Minion.h"



/**
* Constructor
* \param game The game we are in
* \param filename Filename for the image we use
*/
CMinion::CMinion(CGame *game, const std::wstring &filename) :
	CMinion(game, filename)
{
	mSpeedX;
	mSpeedY;

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
	//SetLocation(GetX() + mSpeedX * elapsed,
	//	GetY() + mSpeedY * elapsed);
	/////checks to see when the fish gets within 10 pixels of the edge in x direction on right
	//if (GetGame()->GetWidth() - GetX() - (GetMinionWidth() / 2) <= 10)
	//{
	//	if (mSpeedX > 0 && GetX() >= GetGame()->GetWidth())
	//	{
	//		mSpeedX = -mSpeedX;
	//		SetMirrorX(mSpeedX < 0);
	//	}

	//}

	/////checks to see when the fish gets within 10 pixels of the edge in x direction on left
	//if (GetX() <= 10)
	//{
	//	if (mSpeedX < 0 && GetX() <= 0)
	//	{
	//		mSpeedX = -mSpeedX;
	//		SetMirrorX(mSpeedX < 0);
	//	}
	//}

	///checks to see when the fish gets within 10 pixels of the edge in y direction on bottom
	//if (GetGame()->GetHeight() - GetY() - (GetMinionHeight() / 2) <= 10)
	//{
	//	if (mSpeedY > 0 && GetY() >= GetAquarium()->GetHeight())
	//	{
	//		mSpeedY = -mSpeedY;
	//		SetMirrorY(mSpeedY < 0);
	//	}

	//}
	///checks to see when the fish gets within 10 pixels of the edge in y direction on top
	//if (GetY() <= 10)
	//{
	//	if (mSpeedY < 0 && GetY() <= 0)
	//	{
	//		mSpeedY = -mSpeedY;
	//		SetMirrorY(mSpeedY < 0);
	//	}
	//}

}


