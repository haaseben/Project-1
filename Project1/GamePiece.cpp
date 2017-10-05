

/**
* \file GamePiece.cpp
*
* \author Team Jorge
*/

#include "stdafx.h"
#include "GamePiece.h"
#include "Game.h"


using namespace std;
using namespace Gdiplus;


/// The directory containing the file images
const std::wstring CGamePiece::ImagesDirectory = L"images/";


/**
*  Distance from center for inside of tiles.
*
* Our tiles are a diamond that is 64 pixels tall and 128 pixels
* wide. So, if we take the distance from the center vertically and
* double it, it would be as if we had a 64 by 64 diamond. The
* "Manhattan distance" from the center would be no more than 64
* in that case.
*/
const int InsideTolerance = 64;

/**  Constructor
* \param game The game this item is a member of
*/
CGamePiece::CGamePiece(CGame *game) : mGame(game)
{
}


/**
*  Destructor
*/
CGamePiece::~CGamePiece()
{
}

/**
*  Set the image file to draw
* \param file The base filename. Blank files are allowed
*/
void CGamePiece::SetImage(const std::wstring &file)
{
	if (!file.empty())
	{
		wstring filename = ImagesDirectory + file;
		mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
		if (mItemImage->GetLastStatus() != Ok)
		{
			wstring msg(L"Failed to open ");
			msg += filename;
			AfxMessageBox(msg.c_str());
			return;
		}
	}
	else
	{
		mItemImage.release();
	}

	mFile = file;
}

/**
*  Draw our gamepiece
* \param graphics The graphics context to draw on
*/
void CGamePiece::Draw(Gdiplus::Graphics *graphics)
{
	if (mItemImage != nullptr)
	{
		int wid = mItemImage->GetWidth();
		int hit = mItemImage->GetHeight();

		graphics->DrawImage(mItemImage.get(),
			mX , mY + hit,
			wid, hit);
	}

}





/**  Test to see if we hit this object with a mouse.
* \param x X position to test
* \param y Y position to test
* \return true if hit.
*/
bool CGamePiece::HitTest(int x, int y)
{
	// Simple manhattan distance 
	return (abs(x - mX) + abs(y - mY) * 2) <= InsideTolerance;
}


/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Created XML node
*/
std::shared_ptr<xmlnode::CXmlNode> CGamePiece::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = node->AddChild(L"tile");

	itemNode->SetAttribute(L"x", mX);
	itemNode->SetAttribute(L"y", mY);

	return itemNode;
}


/**
* brief Load the attributes for an item node.
*
* This is the  base class version that loads the attributes
* common to all items. Override this to load custom attributes
* for specific items.
*
* \param node The Xml node we are loading the item from
*/
void CGamePiece::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	mX = node->GetAttributeIntValue(L"x", 0);
	mY = node->GetAttributeIntValue(L"y", 0);
	
}