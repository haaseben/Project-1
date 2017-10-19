/**
* \file Villain.h
*
* \author Team Jorge
*
* Class to visit villain objects.
*/
#pragma once
#include "GameVisitor.h"

/**
* The class handles villain visits.
*/
class CVillainVisitor :
	public CGameVisitor
{
public:
	CVillainVisitor();
	~CVillainVisitor();

	virtual int VisitVillain(CVillain *villain) override;

	int CVillainVisitor::GetJuicerScore() { return mJuicerScore; }
	int CVillainVisitor::GetPokeScore() { return mPokeScore; }
	int CVillainVisitor::GetAryaScore() { return mAryaScroe; }

private:
	/// Collected score Juicer
	int mJuicerScore = 0;

	/// Collected socre Pokeball
	int mPokeScore = 0;

	/// Collected socre Arya
	int mAryaScroe = 0;

};

