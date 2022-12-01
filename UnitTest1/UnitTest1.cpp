#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Dmytro\Documents\C++\SoftwareEngeneeringLab\Software Engeneering App\Software Engeneering App\Software Engeneering App.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(calculate_get4and3_0expect)
		{
			int n = 4;
			double x = 3;
			double expected = 0;
			double actual = calculate(n, x);
			Assert::AreEqual(expected,actual);
		}
		TEST_METHOD(calculate_get5and6_365expect)
		{
			int n = 5;
			double x = 6;
			double expected = 365;
			double actual = calculate(n, x);
			Assert::AreNotEqual(expected, actual);
		}
		TEST_METHOD(calculate_get5andNegative2_errorExpect_exceptionThrown)
		{
			int n = 5;
			double x = -2;
			try
			{
				calculate(n, x);
				Assert::Fail;
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
	TEST_CLASS(checkValidParamN_Tests)
	{
	public:
		TEST_METHOD(checkValidParamN_get5_exceptionNotThrown)
		{
			int n = 5;
			try
			{
				checkValidParamN(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail;
			}
		}
		TEST_METHOD(checkValidParamN_get2_exceptionThrown)
		{
			int n = 2;
			try
			{
				checkValidParamN(n);
				Assert::Fail;
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
	TEST_CLASS(checkValidParamsAB_Tests)
	{
	public:
		TEST_METHOD(checkValidParamsAB_get5and8_exceptionNotThrown)
		{
			double a = 5;
			double b = 8;
			try
			{
				checkValidParamsAB(a, b);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail;
			}
		}
		TEST_METHOD(checkValidParamsAB_get2and0_exceptionThrown)
		{
			double a = 2;
			double b = 0;
			try
			{
				checkValidParamsAB(a, b);
				Assert::Fail;
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
	TEST_CLASS(checkValidParamStep_Tests)
	{
	public:
		TEST_METHOD(checkValidParamStep_get5_exceptionNotThrown)
		{
			double step = 5;
			try
			{
				checkValidParamStep(step);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail;
			}
		}
		TEST_METHOD(checkValidParamStep_getNegative2_exceptionThrown)
		{
			double step = -2;
			try
			{
				checkValidParamStep(step);
				Assert::Fail;
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
}
