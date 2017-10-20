/**
 * \file NewGame.h
 *
 * \author Team Jorge
 *
 * Class that handle the new game feature
 */

#pragma once

#include "GamePiece.h"
#include <memory>

 /** Describe the newgame button */
class CNewGame : public CGamePiece
{

public:
	/** constructor for mutant
	* \param game
	*/
	CNewGame(CGame *game);

	/// Default constructor (disabled)
	CNewGame() = delete;

	/// Copy constructor (disabled)
	CNewGame(const CNewGame &) = delete;

	/** destructor for new game
	*/
	virtual ~CNewGame();

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CGameVisitor *visitor) override { visitor->VisitNewGame(this); }


};

