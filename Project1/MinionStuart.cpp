#include "stdafx.h"
#include "MinionStuart.h"


/// Minion filename 
const wstring MinionStuartImageName = L"images/stuart.png";

/**
* Constructor
* \param game Game this gamepiece is a member of
*/
CMinionStuart::CMinionStuart(CGame *game) :
	CMinion(game, MinionStuartImageName)
{
	SetSpeedX(50);
	SetSpeedY(70);
}


CMinionStuart::~CMinionStuart()
{
}


/**
* Save this item to an XML node
* \param node The node we are going to be a child of
* \return item node with the type of fish
*/
std::shared_ptr<xmlnode::CXmlNode>
CMinionStuart::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CMinion::XmlSave(node);

	itemNode->SetAttribute(L"type", L"beta");

	return itemNode;
}