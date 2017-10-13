#include "stdafx.h"
#include "CppUnitTest.h"
#include"Game.h"
#include"MinionJerry.h"

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
				L"Testing empty aquarium");

			shared_ptr<CMinionJerry> minion1 = make_shared<CMinionJerry>(&game);
			minion1->SetLocation(100, 200);
			game.Add(minion1);

			Assert::IsTrue(game.HitTest(100, 200) == minion1,
				L"Testing minion at 100, 200");

			shared_ptr<CMinionJerry> minion2 = make_shared<CMinionJerry>(&game);
			minion2->SetLocation(100, 200);
			game.Add(minion2);

			Assert::IsTrue(game.HitTest(100, 200) == minion2,
				L"Testing game for second return");

		}

		TEST_METHOD(TestCGameClearTest)
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


			game.Clear();
			Assert::IsTrue(game.HitTest(100, 200) == nullptr);
			Assert::IsTrue(game.HitTest(400, 400) == nullptr);
			Assert::IsTrue(game.HitTest(600, 100) == nullptr);
		}

	};
}