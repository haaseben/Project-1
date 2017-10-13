#include "stdafx.h"
#include "CppUnitTest.h"
#include "GamePiece.h"
#include "Game.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/// Minion filename 
const wstring MinionJerryImageName = L"images/jerry.png";

namespace Testing
{
	/** Mock class for testing CItem */
	class CGamePieceMock : public CGamePiece
	{
	public:
		/** Constructor
		* \param game The game this is a member of */
		CGamePieceMock(CGame *game) : CGamePiece(game, MinionJerryImageName) {}
		/** Draw the item
		* \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics *graphics) {}

	};
	TEST_CLASS(CGamePieceTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCGamePieceConstruct)
		{
			CGame game;
			CGamePieceMock gamepiece(&game);
		}

		TEST_METHOD(TestCGamePieceGettersSetters)
		{
			// Construct a gamepiece to test
			CGame game;
			CGamePieceMock gamepiece(&game);

			// Test initial values
			Assert::AreEqual(0, gamepiece.GetX(), 0);
			Assert::AreEqual(0, gamepiece.GetY(), 0);

			// Test SetLocation, GetX, and GetY
			gamepiece.SetLocation(20, 25);
			Assert::AreEqual(20, gamepiece.GetX(), 0.0001);
			Assert::AreEqual(25, gamepiece.GetY(), 0.0001);

			// Test a second with with different values
			gamepiece.SetLocation(-1, -10);
			Assert::AreEqual(-1, gamepiece.GetX(), 0.0001);
			Assert::AreEqual(-10, gamepiece.GetY(), 0.0001);
		}

		TEST_METHOD(TestCItemMockHitTest)
		{
			// Construct a gamepiece to test
			CGame game;
			CGamePieceMock gamepiece(&game);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			gamepiece.SetLocation(100, 200);

			// Center of the game piece should be a true
			Assert::IsTrue(gamepiece.HitTest(100, 200));

			// Left of the game piece
			Assert::IsFalse(gamepiece.HitTest(10, 200));

			// Right of the game piece
			Assert::IsFalse(gamepiece.HitTest(200, 200));

			// Above the game piece
			Assert::IsFalse(gamepiece.HitTest(100, 0));

			// Below the game piece
			Assert::IsFalse(gamepiece.HitTest(100, 300));

			// Of game piece transparent pixel
			Assert::IsFalse(gamepiece.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
		};
	};
}