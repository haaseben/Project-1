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
#include "Vector.h"
#include "GameVisitor.h"

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
	double GetX() const { return mX; }

	/**  The Y location of the center of the tile
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/**  Set the item location
	* \param x X location
	* \param y Y location */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/**  Draw this item
	* \param graphics The graphics context to draw on */
	virtual void Draw(Gdiplus::Graphics *graphics);

	/**  Test this item to see if it has been clicked on
	* \param x X location on the gameto test
	* \param y Y location on the game to test
	* \return true if clicked on */
	virtual bool HitTest(int x, int y);

	///  Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	///  Get the game this item is in
	/// \returns game pointer
	CGame *GetGame() { return mGame; }

	double CGamePiece::GetHeight();
	double CGamePiece::GetWidth();


	///virtual function for determining if gru
	/// \returns true if it is
	virtual bool GruOrNot()=0 ;

	//virtual CVector CGamePiece::GetP

	/// determines if a game piece can be deleted
	virtual bool CanCollide() { return false; }

	void SetVelocity(CVector NewVector) { mV = NewVector; }/// Velocity in virtual pixels/second

	const CVector GetVelocity() { return mV; }

	const CVector GetPVector() { return mP; }

	const int GetBaseSpeed() { return mBaseSpeed; }
	/** Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CGameVisitor *visitor) = 0;

protected:
	/**
	* Describe the gamepiece and it's file
	* \param game Game object
	* \param filename File name
	*/
	CGamePiece(CGame *game, const std::wstring &filename);


	/// The image of this item
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	// Item location in the game
	double   mX = 0;     ///< X location for the center of the item
	double   mY = 0;     ///< Y location for the center of the item

						 // Item location in the playing area
	CVector mP;			///< Position 

	int mBaseSpeed;

	CVector mV;


private:
	/// The city this item is contained in
	CGame   *mGame;

	/// The file for this item
	std::wstring mFile;


};