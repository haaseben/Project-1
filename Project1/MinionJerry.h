/**
* \file:MinionJerry.h
*
* \author: Team Jorge
*
*  class for minion Jerry
*/


#pragma once
#include "Minion.h"

/**
* implements a jerry minion
*/
class CMinionJerry :
	public CMinion
{
public:

	/// Default constructor (disabled)
	CMinionJerry() = delete;

	/// Copy constructor (disabled)
	CMinionJerry(const CMinionJerry &) = delete;

	~CMinionJerry();

	CMinionJerry(CGame *game);

	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

private:
	///points minion is worth
	int mPoints = 1;
};

