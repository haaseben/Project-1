#include "stdafx.h"
#include "MinionJerry.h"


/// Minion filename 
const wstring MinionJerryImageName = L"images/jerry.png";

/**
* Constructor
* \param game Game this gamepiece is a member of
*/
CMinionJerry::CMinionJerry(CGame *game) :
	CMinion(game, MinionJerryImageName)
{
	SetSpeedX(50);
	SetSpeedY(70);
}


CMinionJerry::~CMinionJerry()
{
}


/**
* Save this item to an XML node
* \param node The node we are going to be a child of
* \return item node with the type of fish
*/
std::shared_ptr<xmlnode::CXmlNode>
CMinionJerry::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CMinion::XmlSave(node);

	itemNode->SetAttribute(L"type", L"beta");

	return itemNode;
}