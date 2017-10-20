#include "stdafx.h"
#include "CppUnitTest.h"
#include"Game.h"
#include"MinionJerry.h"
#include "Arya.h"
#include "Pokeball.h"
#include "Juicer.h"
#include "Gru.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CGameTest)
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

		TEST_METHOD(TestCGameConstruct)
		{
			CGame game;
		}

		TEST_METHOD(TestCGameHitTest)
		{
			//tests for hittest but also villain placement
			CGame game;
			CPokeBall pokeball(&game);
			

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			pokeball.SetLocation(300, 150);

			// Center of the game piece should be a true
			Assert::IsTrue(pokeball.HitTest(300, 150));

			// Left of the game piece
			Assert::IsFalse(pokeball.HitTest(10, 150));

			// Right of the game piece
			Assert::IsFalse(pokeball.HitTest(150, 150));

			// Above the game piece
			Assert::IsFalse(pokeball.HitTest(300, 0));

			// Below the game piece
			Assert::IsFalse(pokeball.HitTest(300, 300));

			// Of game piece transparent pixel
			Assert::IsFalse(pokeball.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
			

		}

		TEST_METHOD(TestCGameRemoveTest)
		{
			CGame game;

			shared_ptr<CMinionJerry> minion1 = make_shared<CMinionJerry>(&game);
			minion1->SetLocation(100, 200);
			game.Add(minion1);


			shared_ptr<CMinionJerry> minion2 = make_shared<CMinionJerry>(&game);
			minion2->SetLocation(400, 400);
			game.Add(minion2);

			shared_ptr<CMinionJerry> minion3 = make_shared<CMinionJerry>(&game);
			minion3->SetLocation(600, 100);
			game.Add(minion3);


			game.Remove(minion1);
			game.Remove(minion2);
			game.Remove(minion3);

			Assert::IsTrue(game.HitTest(100, 200) == nullptr);
			Assert::IsTrue(game.HitTest(400, 400) == nullptr);
			Assert::IsTrue(game.HitTest(600, 100) == nullptr);
		}

	};
}