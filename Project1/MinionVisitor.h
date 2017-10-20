/**
* \file Minion.h
*
* \author: Team Jorge
*
*  Base class for minion visit

*/
#pragma once
#include "GameVisitor.h"
/**
* implements a minion visitor
*/
class CMinionVisitor :
	public CGameVisitor
{
public:
	CMinionVisitor();
	~CMinionVisitor();
	

};

