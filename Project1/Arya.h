/**
* \file Arya.h
*
* \author Team Jorge
*
* Class the implements Arya.
*/

#pragma once

#include <memory>
#include "GamePiece.h"
#include "Villain.h"


/**
* Implements Arya
*/
class CArya: public CVillain
{
public:
	/// constructor
	CArya(CGame *game);

	/// Default constructor (disabled)
	CArya() = delete;

	/// Copy constructor (disabled)
	CArya(const CArya &) = delete;

	/// destructor
	virtual ~CArya();


};