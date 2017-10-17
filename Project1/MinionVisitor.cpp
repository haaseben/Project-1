#include "stdafx.h"
#include "MinionVisitor.h"
#include "Minion.h"

CMinionVisitor::CMinionVisitor()
{
}


CMinionVisitor::~CMinionVisitor()
{
}

/** \brief Visit a CMinion object
* \param minion Minion tile we are visiting */
int CMinionVisitor::VisitMinion(CMinion *minion)
{
	return minion->GetPoints();
}