#include "stdafx.h"
#include "CppUnitTest.h"
#include "Minion.h"
#include "Game.h"
#include "MinionJerry.h"
#include"GamePiece.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CMinionTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCMinionJerryConstruct)
		{
			CGame game;
			CMinionJerry minion(&game);
		}

		TEST_METHOD(TestCMinionJerryHitTest)
		{
			// Create a minion to test
			CGame game;
			CMinionJerry minion(&game);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			minion.SetLocation(300,150);

			// Center of the game piece should be a true
			Assert::IsTrue(minion.HitTest(300, 150));

			// Left of the game piece
			Assert::IsFalse(minion.HitTest(10, 150));

			// Right of the game piece
			Assert::IsFalse(minion.HitTest(150, 150));

			// Above the game piece
			Assert::IsFalse(minion.HitTest(300, 0));

			// Below the game piece
			Assert::IsFalse(minion.HitTest(300, 300));

			// Of game piece transparent pixel
			Assert::IsFalse(minion.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
		}

	};
}