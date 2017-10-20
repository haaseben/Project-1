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

/**
* The class that handling the playingarea and the object in it.
*/
class CPlayingArea 
{
public:
	/// size of the grid
	const static double GridSize;

	/// radius of the grid
	const static double GridRadius;

	/// margin of the grid
	const static double GridMargin;

	/// default constructor
	CPlayingArea();

	/// default destructor
	~CPlayingArea();

	/**
	* draws 
	* \param graphics 
	* \param gameover
	*/
	void OnDraw(Gdiplus::Graphics * graphics, bool gameover);

private:
	/// Describe our game
	CGame   *mGame;
	

};

