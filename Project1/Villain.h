/**
 * \file Villain.h
 *
 * \author Team Jorge
 *
 * Class to handle villain objects. 
 */

#pragma once
#include "GamePiece.h"

 /**
 * The class handle villain object. 
 */
class CVillain : public CGamePiece
{



public:
	/// Default constructor (disabled)
	CVillain() = delete;

	/// Copy constructor (disabled)
	CVillain(const CVillain &) = delete;

	~CVillain();

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CGameVisitor *visitor) override { visitor->VisitVillain(this); }

	virtual int GetMultiplier()=0;

	int CVillain::GetJuicerScore() { return mJuicerScore; }
	int CVillain::GetPokeScore() { return mPokeScore; }
	int CVillain::GetAryaScore() { return mAryaScroe; }

protected:
	/**
	* Constructor
	* \param game The game we are in
	* \param filename Filename for the image we use
	*/
	CVillain::CVillain(CGame *game, const std::wstring &filename);

private:
	/// Collected score Juicer
	int mJuicerScore = 0;

	/// Collected socre Pokeball
	int mPokeScore = 0;

	/// Collected socre Arya
	int mAryaScroe = 0;



};

