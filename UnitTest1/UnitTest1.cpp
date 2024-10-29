#include "pch.h" 
#include "CppUnitTest.h"
#include "../lab_6.1/6.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int size = 25;
			const int min_value = 15;
			const int max_value = 94;
			int arr[size];

			generateArray(arr, size, min_value, max_value);

			for (int i = 0; i < size; i++) {
				Assert::IsTrue(arr[i] >= min_value && arr[i] <= max_value, L"Element out of bounds!");
			}
		}
	};
}