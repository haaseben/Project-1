#include "stdafx.h"
#include "PlayingArea.h"

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

CPlayingArea::CPlayingArea()
{
}


CPlayingArea::~CPlayingArea()
{
}

void CPlayingArea::OnDraw(Gdiplus::Graphics * graphics)
{
	Pen pen(Color(0, 128, 0), 1);
	graphics->DrawRectangle(&pen, -500, -500, 1000, 1000);
}