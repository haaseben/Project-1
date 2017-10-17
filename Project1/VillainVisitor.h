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
};

