#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
__declspec(dllimport) char* GetTeam();
__declspec(dllimport) void SetMaze(const int** p_data, int p_width, int p_height);
__declspec(dllimport) int** GetMaze(int& p_width, int& p_height);
__declspec(dllimport) void GetNextPosition(int& xpos, int& ypos);
__declspec(dllimport) void SetStart(int xPos, int yPos);
__declspec(dllimport) void GetStart(int& xPos, int& yPos);
__declspec(dllimport) void SetEnd(int xPos, int yPos);
__declspec(dllimport) void GetEnd(int& xPos, int& yPos);

namespace HanelDeWittUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		//GetTeam Tests
		TEST_METHOD(TestGetTeam)
		{
		}
		
		TEST_METHOD(SetMaze)
		{
			
		}

		TEST_METHOD(GetMaze)
		{
			int** data;
			int num1 = 0;
			int num2 = 0;
			data = GetMaze(num1, num2);

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
		TEST_METHOD(TestGetEndBadX)
		{
			//Checks for invalid x

			int x = -1;
			int y = 0;

			bool ret = GetStart(x, y);
			Assert::IsFalse(ret);
		}
		
		TEST_METHOD(TestGetEndBadY)
		{
			//Checks for invalid y

			int x = 0;
			int y = -1;

			bool ret = GetStart(x, y);
			Assert::IsFalse(ret);
		}

	};
}
