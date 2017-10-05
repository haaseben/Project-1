/**
* Base class for minion
* applies to all minions in the game
*/
#pragma once
#include "GamePiece.h"




/**
* implements a base minion class
*/
class CMinion :
	public CGamePiece
{
public:
	/// Default constructor (disabled)
	CMinion() = delete;

	/// Copy constructor (disabled)
	CMinion(const CMinion &) = delete;



private:
	///name for a particular minion
	string mName;

	///speed in x direction of a minion
	double mSpeedX;

	///speed in y direction of a minion
	double mSpeedY;

	///time for minion to appear on screen
	double mAppearTime;


};

