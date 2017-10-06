/**
* file Juicer.h
* author Team Jorge
* 
*Class implements the villain Juicer.
*/

#pragma once
#include <memory>
#include "GamePiece.h"
#include "Villains.h"

class CJuicer : public CVillains
{
public:
	CJuicer(CGame *game);

	/// Default constructor disabled
	CJuicer() = delete;

	/// Copy constructor (disabled)
	CJuicer(const CJuicer &) = delete;

	virtual ~CJuicer();
};

