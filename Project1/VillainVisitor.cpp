#include "stdafx.h"
#include "VillainVisitor.h"
#include "Villain.h"

CVillainVisitor::CVillainVisitor()
{
}


CVillainVisitor::~CVillainVisitor()
{
}



/** \brief Visit a CVillain object
* \param vilain Villain tile we are visiting */
int CVillainVisitor::VisitVillain(CVillain *villain)
{
	return villain->GetMultiplier();
}