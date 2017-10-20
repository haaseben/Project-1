/**
 * \file VillainVisitor.cpp
 *
 * \author Team Jorge
 */

#include "stdafx.h"
#include "VillainVisitor.h"
#include "Villain.h"


/**  constructor
*/
CVillainVisitor::CVillainVisitor()
{
}


/**  destructor
*/
CVillainVisitor::~CVillainVisitor()
{
}



/** \brief Visit a CVillain object
* \param villain villain tile we are visiting 
*/
int CVillainVisitor::VisitVillain(CVillain *villain)
{
	return villain->GetMultiplier();
}