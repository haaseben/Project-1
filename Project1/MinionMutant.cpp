#include "stdafx.h"
#include "MinionMutant.h"


/// Minion filename 
const wstring MinionMutantImageName = L"images/mutant.png";

/**
* Constructor
* \param game Game this gamepiece is a member of
*/
CMinionMutant::CMinionMutant(CGame *game) :
	CMinion(game, MinionMutantImageName)
{
	SetSpeedX(100);
	SetSpeedY(140);
}


CMinionMutant::~CMinionMutant()
{
}


/**
* Save this item to an XML node
* \param node The node we are going to be a child of
* \return item node with the type of fish
*/
std::shared_ptr<xmlnode::CXmlNode>
CMinionMutant::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CMinion::XmlSave(node);

	itemNode->SetAttribute(L"type", L"beta");

	return itemNode;
}