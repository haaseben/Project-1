/**
* \file GamePiece.h
*
* \author Team Jorge
*
* Class that implements a gamepiece for the game
*/
#pragma once


#include <string>
#include <memory>
#include "XmlNode.h"


using namespace Gdiplus;
using namespace std;

class CGame;

/**
* implements a gamepiece for the game
*/
class CGamePiece
{
public:


	/** The directory where the images are stored */
	static const std::wstring ImagesDirectory;

	///  Default constructor (disabled)
	CGamePiece() = delete;

	///  Copy constructor (disabled)
	CGamePiece(const CGamePiece &) = delete;

	virtual ~CGamePiece();

	void SetImage(const std::wstring &file);

	/**  Get the file name for this tile image
	* \returns Filename or blank if none */
	std::wstring GetFile() { return mFile; }

	/**  The X location of the center of the tile
	* \returns X location in pixels */
	int GetX() const { return mX; }

	/**  The Y location of the center of the tile
	* \returns Y location in pixels */
	int GetY() const { return mY; }

	/**  Set the item location
	* \param x X location
	* \param y Y location */
	void SetLocation(int x, int y) { mX = x; mY = y; }

	/**  Draw this item
	* \param graphics The graphics context to draw on */
	virtual void Draw(Gdiplus::Graphics *graphics);

	/**  Test this item to see if it has been clicked on
	* \param x X location on the aquarium to test
	* \param y Y location on the aquarium to test
	* \return true if clicked on */
	virtual bool HitTest(int x, int y);


	///  Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	///  Get the game this item is in
	/// \returns game pointer
	CGame *GetGame() { return mGame; }

	double CGamePiece::GetMinionHeight();
	double CGamePiece::GetMinionWidth();


	/// Set the mirror status
	/// \param m New mirror flag
	void SetMirrorX(bool m) { mMirrorX = m; };

	/// Set the mirror status
	/// \param m New mirror flag
	void SetMirrorY(bool m) { mMirrorY = m; };

protected:
	CGamePiece(CGame *game);

private:
	/// The city this item is contained in
	CGame   *mGame;

	// Item location in the aquarium
	int   mX = 0;     ///< X location for the center of the item
	int   mY = 0;     ///< Y location for the center of the item

					  /// The image of this tile
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	/// The file for this item
	std::wstring mFile;

	bool mMirrorX = false;   ///< True mirrors the item image for x
	bool mMirrorY = false;   ///< True mirrors the item image for y
};