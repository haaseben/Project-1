#include "stdafx.h"
#include "PlayingArea.h"

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
