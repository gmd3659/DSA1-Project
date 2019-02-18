#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
__declspec(dllimport) char* GetTeam();
__declspec(dllimport) void SetMaze(const int** p_data, int p_width, int p_height);
__declspec(dllimport) int** GetMaze(int& p_width, int& p_height);
__declspec(dllimport) void GetNextPositions(int& xpos, int& ypos);
__declspec(dllimport) bool SetStart(int xPos, int yPos);
__declspec(dllimport) bool GetStart(int& xPos, int& yPos);
__declspec(dllimport) bool SetEnd(int xPos, int yPos);
__declspec(dllimport) bool GetEnd(int& xPos, int& yPos);

namespace HanelDeWittUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		//GetTeam Tests
		TEST_METHOD(TestGetTeam)
		{
			//Check for correct string
			char* team = GetTeam();
			bool ret = false;
			if (team == "Group 10 --Gavin Dewitt and Brad Hanel")
			{
				ret == true;
			}
			Assert::IsTrue(ret);
		}

		TEST_METHOD(SetMaze)
		{
			// TODO: Your test code here
		}

		TEST_METHOD(GetMaze)
		{
			// TODO: Your test code here
		}

		TEST_METHOD(GetNextPositions)
		{
			// TODO: Your test code here
		}

		//SetStart Tests
		TEST_METHOD(TestSetStartBadX)
		{
			//Checks for invalid x
			bool ret = SetStart(-1, 0);
			Assert::IsFalse(ret);
		}

		TEST_METHOD(TestSetStartBadY)
		{
			//Checks for invalid y
			bool ret = SetStart(0, -1);
			Assert::IsFalse(ret);
		}

		//GetStart Tests
		TEST_METHOD(TestGetStartBadX)
		{
			//Checks for invalid x

			int x = -1;
			int y = 0;

			bool ret = GetStart(x, y);
			Assert::IsFalse(ret);
		}

		TEST_METHOD(TestGetStartBadY)
		{
			//Checks for invalid y

			int x = 0;
			int y = -1;

			bool ret = GetStart(x, y);
			Assert::IsFalse(ret);
		}

		//Set End Tests
		TEST_METHOD(TestSetEndBadX)
		{
			//Checks for invalid x
			bool ret = SetEnd(-1, 0);
			Assert::IsFalse(ret);
		}

		TEST_METHOD(TestSetEndBadY)
		{
			//Checks for invalid y
			bool ret = SetEnd(0, -1);
			Assert::IsFalse(ret);
		}

		//GetEnd Tests
		TEST_METHOD(TestGetEnd)
		{
			//Checks for invalid x

			int x = -1;
			int y = 0;

			bool ret = GetStart(x, y);
			Assert::IsFalse(ret);
		}

		TEST_METHOD(TestGetEnd)
		{
			//Checks for invalid y

			int x = 0;
			int y = -1;

			bool ret = GetStart(x, y);
			Assert::IsFalse(ret);
		}

	};
}