#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_8_1_rek/lab_8_1_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCount)
        {
            char testStr1[] = "This is a while test while and another while.";
            Assert::AreEqual(3, Count(testStr1));

            char testStr2[] = "No matches here.";
            Assert::AreEqual(0, Count(testStr2));

            char testStr3[] = "while";
            Assert::AreEqual(1, Count(testStr3));
        }
        // Тестуємо функцію Change
        TEST_METHOD(TestChange)
        {
            char testStr1[] = "This is a while test.";
            char expectedOutput1[] = "This is a *** test.";
            char* dest1 = new char[101];
            dest1[0] = '\0';
            Change(dest1, testStr1, dest1, 0);
            Assert::AreEqual(expectedOutput1, dest1);
            delete[] dest1;

            char testStr2[] = "No while here.";
            char expectedOutput2[] = "No *** here.";
            char* dest2 = new char[101];
            dest2[0] = '\0';
            Change(dest2, testStr2, dest2, 0);
            Assert::AreEqual(expectedOutput2, dest2);
            delete[] dest2;
        }

	};
}
