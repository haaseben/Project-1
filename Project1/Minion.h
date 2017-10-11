/**
* \file:Minion.h
*
* \author: Team Jorge
*  
*  Base class for minion
* applies to all minions in the game
*/
#pragma once
#include "GamePiece.h"
#include "Game.h"


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

	/// Set the Speed in x direction
	/// \param NewSpeedX sets new speed for minion in x direction
	void SetSpeedX(double NewSpeedX) { mSpeedX = NewSpeedX; }

	/// Set the Speed in y direction
	/// \param NewSpeedY sets new speed for minion in y direction
	void SetSpeedY(double NewSpeedY) { mSpeedY = NewSpeedY; }

	///Updates the display over time
	/// \param elapsed amount of time since start of project
	void CMinion::Update(double elapsed);

	

	CMinion::~CMinion();

protected:
	CMinion::CMinion(CGame *game, const std::wstring &filename);

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

