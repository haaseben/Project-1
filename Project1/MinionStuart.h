/**
* \file:MinionStuart.h
*
* \author: Team Jorge
*
*  class for minion Stuart
*/


#pragma once
#include "Minion.h"
/**
* implements a Stuart minion
*/
class CMinionStuart :
	public CMinion
{
public:
	/// Default constructor (disabled)
	CMinionStuart() = delete;

	/// Copy constructor (disabled)
	CMinionStuart(const CMinionStuart &) = delete;

	~CMinionStuart();

	CMinionStuart(CGame *game);

	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
private:
	///points minion is worth
	int mPoints = 1;
};

