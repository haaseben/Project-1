/**
* \file:MinionMutant.h
*
* \author: Team Jorge
*
*  class for mutant minion 
*/


#pragma once
#include "Minion.h"
/**
* implements a mutant minion
*/
class CMinionMutant :
	public CMinion
{
public:
	/// Default constructor (disabled)
	CMinionMutant() = delete;

	/// Copy constructor (disabled)
	CMinionMutant(const CMinionMutant &) = delete;

	~CMinionMutant();

	CMinionMutant(CGame *game);

	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

private:
	///points minion is worth
	int mPoints = 5;
};

