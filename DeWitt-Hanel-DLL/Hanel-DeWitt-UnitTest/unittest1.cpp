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
		TEST_METHOD(TestGetTeamNotNull)
		{
			//Check for a non null string
			char* team = GetTeam();
			Assert::AreEqual("Group 10 -- Gavin Dewitt and Brad Hanel",team);
		}
		

		//SetMaze Tests
		TEST_METHOD(TestSetMaze)
		{
			// TODO: Your test code here
			const int** m = new const int*[3];
			for (int i = 0; i < 3; i++) 
			{ 
				m[i] = new int[4];
			}

			SetMaze(m, 3, 4);

		}

		//GetMaze Tests
		TEST_METHOD(TestGetMaze)
		{
			// TODO: Your test code here
			const int** m = new const int*[3];
			for (int i = 0; i < 3; i++)
			{
				m[i] = new int[4];
			}

			SetMaze(m, 3, 4);

			const int** n = new const int*[3];
			for (int i = 0; i < 3; i++)
			{
				n[i] = new int[4];
			}

			Assert::IsTrue(m == n);

		}

		//GetNextPosition Tests
		TEST_METHOD(TestGetNextPosition)
		{
			// TODO: Your test code here
		}

		//SetStart Tests
		TEST_METHOD(TestSetStartBadX)
		{
			//Checks for invalid x
			
		}

		TEST_METHOD(TestSetStartBadY)
		{
			//Checks for invalid y
			
		}

		//GetStart Tests
		TEST_METHOD(TestGetStartBadX)
		{
			//Checks for invalid x

			int x = -1;
			int y = 0;

			GetStart(x, y);
			
		}

		TEST_METHOD(TestGetStartBadY)
		{
			//Checks for invalid y

			int x = 0;
			int y = -1;

			GetStart(x, y);
	
		}

		//Set End Tests
		TEST_METHOD(TestSetEndBadX)
		{
			//Checks for invalid x
			
		}

		TEST_METHOD(TestSetEndBadY)
		{
			//Checks for invalid y
			
		}

		//GetEnd Tests
		TEST_METHOD(TestGetEndX)
		{
			//Checks for invalid x

			int x = -1;
			int y = 0;

			
		}

		TEST_METHOD(TestGetEndY)
		{
			//Checks for invalid y

			int x = 0;
			int y = -1;

			GetStart(x, y);
		}
	};
}