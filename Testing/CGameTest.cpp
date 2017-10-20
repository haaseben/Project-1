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
			CGame game;

			Assert::IsTrue(game.HitTest(100, 200) == nullptr,
				L"Testing empty game");

			auto arya = make_shared<CArya>(&game);
			arya->SetLocation(-50.0, 225.0);
			game.Add(arya);

			Assert::IsTrue(game.HitTest(-50.0, 225.0) == arya,
				L"Testing minion at 100, 200");

			auto juicer = make_shared<CJuicer>(&game);
			juicer->SetLocation(-250.0, -325.0);
			game.Add(juicer);

			Assert::IsTrue(game.HitTest(-250.0, -325.0) == juicer,
				L"Testing game for second return");

			auto gru = make_shared<CGru>(&game);
			gru->SetLocation(-15.0, -50.0);
			game.Add(gru);

			Assert::IsTrue(game.HitTest(-15.0, -50.0) == gru,
				L"Testing game for third return");

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