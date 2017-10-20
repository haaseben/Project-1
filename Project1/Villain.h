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
	/// Destrcutor
	~CVillain();

	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CGameVisitor *visitor) override { visitor->VisitVillain(this); }

	/**  gets the multiplier of the villian
	* \return multiplier */
	virtual int GetMultiplier()=0;

	/**  gets the score of the juicer
	* \return juicerscore */
	int CVillain::GetJuicerScore() { return mJuicerScore; }

	/**  gets the score of the pokeball
	* \return pokeball score */
	int CVillain::GetPokeScore() { return mPokeScore; }

	/**  gets the score of the arya
	* \return arya score */
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

