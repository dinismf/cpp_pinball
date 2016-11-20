#include "stdafx.h"
#include "CppUnitTest.h"
#include "../include/Vector2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(Vector2DTest)
	{
	public:
		
		TEST_METHOD(EmptyConstructorTest)
		{
			Vector2D testVector(0, 0);

			Assert::AreEqual(testVector.x(), 0.0f);
			Assert::AreEqual(testVector.y(), 0.0f);
		}
		TEST_METHOD(FullConstructorTest)
		{
			Vector2D testVector(10, 5);

			Assert::AreEqual(testVector.x(), 10.0f);
			Assert::AreEqual(testVector.y(), 5.0f);
		}
		TEST_METHOD(AddVector)
		{
			Vector2D v1Test(5, 5);
			Vector2D v2Test(10, 5);
			Vector2D result = v1Test + v2Test;
			
			Assert::AreEqual(result.x(), 15.0f);
			Assert::AreEqual(result.y(), 10.0f);
		}


	};
}