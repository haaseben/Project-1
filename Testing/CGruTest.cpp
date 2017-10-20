#include "stdafx.h"
#include "CppUnitTest.h"
#include"Gru.h"
#include"Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CGruTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCGruConstruct)
		{
			CGame game;
			CGru Gru(&game);
		}


		TEST_METHOD(TestCGruHitTest)
		{
			// Create a minion to test
			CGame game;
			CGru Gru(&game);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			Gru.SetLocation(300, 150);

			// Center of the game piece should be a true
			Assert::IsTrue(Gru.HitTest(300, 150));

			// Left of the game piece
			Assert::IsFalse(Gru.HitTest(10, 150));

			// Right of the game piece
			Assert::IsFalse(Gru.HitTest(150, 150));

			// Above the game piece
			Assert::IsFalse(Gru.HitTest(300, 0));

			// Below the game piece
			Assert::IsFalse(Gru.HitTest(300, 300));

			// Of game piece transparent pixel
			Assert::IsFalse(Gru.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
		}

	};
}