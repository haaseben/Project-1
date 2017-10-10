/**
 * \file PlayingArea.h
 *
 * \author Team Jorge
 *
 * The class which will handle the Game Playing Area
 */

#pragma once
#include <vector>
#include <memory>
#include "GamePiece.h"

class CGame;

class CPlayingArea 
{
public:

	const static double GridSize;
	const static double GridRadius;
	const static double GridMargin;

	CPlayingArea();
	~CPlayingArea();

	void OnDraw(Gdiplus::Graphics * graphics);

private:



};

