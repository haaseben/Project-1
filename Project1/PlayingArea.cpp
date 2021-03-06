/**
 * \file PlayingArea.cpp
 *
 * \author Team Jorge
 * Draws the playing area for the game
 */

#include "stdafx.h"
#include "PlayingArea.h"
#include "Juicer.h"
#include "GamePiece.h"
#include "Villain.h"
#include "Gru.h"
#include <memory>
#include "Game.h"
using namespace std;
using namespace Gdiplus;


/// The size of the playing area square in virtual pixels
const double CPlayingArea::GridSize = 1000.0;

/// The range from the center to an edge for the playing area
/// in virtual pixels
const double CPlayingArea::GridRadius = CPlayingArea::GridSize / 2.0;

/// Do not allow Minions or Gru to come closer than this distance
/// to the playing area edges (virtual pixels)
const double CPlayingArea::GridMargin = 50.0;


/** Constructor
*/
CPlayingArea::CPlayingArea()
{
}

/** destructor
*/
CPlayingArea::~CPlayingArea()
{
}

/** Ondraw
*\param graphics used to draw
*\param gameover used as flag for gameover possiblity
*/
void CPlayingArea::OnDraw(Gdiplus::Graphics * graphics, bool gameover)
{
	
	Pen pen(Color(0, 128, 0), 1);
	graphics->DrawRectangle(&pen, -500, -500, 1000, 1000);
	if (gameover)
	{
		FontFamily fontFamily(L"Arial");
		Gdiplus::Font font(&fontFamily, 99);

		SolidBrush green(Color(255, 255, 0));
		graphics->DrawString(L"Gru is Dead!", -1, &font, PointF(-510, -100), &green);

	}
}