/**
 * \file Villain.h
 *
 * \author Team Jorge
 *
 * Class to handle villain objects. 
 */

#pragma once
#include "GamePiece.h"
class CVillain : public CGamePiece
{



public:
	/// Default constructor (disabled)
	CVillain() = delete;

	/// Copy constructor (disabled)
	CVillain(const CVillain &) = delete;

	~CVillain();

protected:
	/**
	* Constructor
	* \param game The game we are in
	* \param filename Filename for the image we use
	*/
	CVillain::CVillain(CGame *game, const std::wstring &filename);


};

