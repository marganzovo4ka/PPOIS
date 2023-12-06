#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/Mnogochlen.h"
#include "../ConsoleApplication1/Mnogochlen.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double coef1[5] = { 1, 0, 3, 4, 2 };
			Mnogochlen a(4, coef1);
			Assert::AreEqual(2.0, a[0]);
		}
		TEST_METHOD(TestMethod2)
		{
			double coef1[5] = { 1, 0, 3, 4, 2 };
			Mnogochlen a(4, coef1);
			Assert::AreEqual(0.0, a[3]);
		}

		TEST_METHOD(TestMethod3)
		{
			double coef1[5] = { 1, 1, 1, 1, 1 };
			Mnogochlen a(4, coef1);
			Assert::AreEqual(31.0, a(2));
		}

		TEST_METHOD(TestMethod4)
		{
			double coef1[5] = { 1, 0, 3, 4, 2 };
			double coef2[4] = {2, 5, 0, 1};
			Mnogochlen a(4, coef1);
			Mnogochlen b(3, coef2);
			Mnogochlen c;
			c = a + b;
			Assert::IsTrue(c.ToString() == "1 2 8 4 3");
		}
		
		TEST_METHOD(TestMethod5)
		{
			double coef1[4] = { 2, 5, 0, 1};
			double coef2[5] = { 1, 0, 3, 4, 2 };
			Mnogochlen a(3, coef1);
			Mnogochlen b(4, coef2);
			a += b;
			Assert::IsTrue(a.ToString() == "1 2 8 4 3");
		}

		TEST_METHOD(TestMethod6)
		{
			double coef1[4] = { 2, 5, 0, 1 };
			double coef2[5] = { 1, 0, 5, 4, 2 };
			Mnogochlen a(3, coef1);
			Mnogochlen b(4, coef2);
			Mnogochlen c;
			c = a - b;
			Assert::IsTrue(c.ToString() == "-1 2 -4 -1");
		}

		TEST_METHOD(TestMethod7)
		{
			double coef1[4] = { 2, 5, 0, 1 };
			double coef2[5] = { 1, 0, 5, 4, 2 };
			Mnogochlen a(3, coef1);
			Mnogochlen b(4, coef2);
			a -= b;
			Assert::IsTrue(a.ToString() == "-1 2 -4 -1");
		}

		TEST_METHOD(TestMethod8)
		{
			double coef1[5] = { 1, 0, 1, 0, -3 };
			double coef2[5] = { 3, 0, 5, 0, -4 };
			Mnogochlen a(4, coef1);
			Mnogochlen b(4, coef2);
			Mnogochlen c;
			c = a * b;
			Assert::IsTrue(c.ToString() == "3 8 -8 -19 12");
		}

		TEST_METHOD(TestMethod9)
		{
			double coef1[5] = { 1, 0, 1, 0, -3 };
			double coef2[5] = { 3, 0, 5, 0, -4 };
			Mnogochlen a(4, coef1);
			Mnogochlen b(4, coef2);
			a *= b;
			Assert::IsTrue(a.ToString() == "3 8 -8 -19 12");
		}

		TEST_METHOD(TestMethod10)
		{
			double coef1[6] = { 3, 2, 0, 1, -1, 1 };
			double coef2[4] = { 1,2,1,0 };
			Mnogochlen a(5, coef1);
			Mnogochlen b(3, coef2);
			Mnogochlen c;
			c = a / b;
			Assert::IsTrue(c.ToString() == "3 -4 5");
		}
	};
}
