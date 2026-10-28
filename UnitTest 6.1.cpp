#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 6.1./Project 6.1.cpp" // Підключаємо файл з вашим основним кодом або опустіть цей рядок і винесіть функції вище

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest611
{
	TEST_CLASS(UnitTest611)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// Готуємо тестовий масив
			const int size = 5;
			// c[0] = 15 -> index 0 % 13 == 0 (не підходить)
			// c[1] = 17 -> непарне, index 1 (підходить)
			// c[2] = 20 -> парне (не підходить)
			// c[3] = 21 -> непарне, index 3 (підходить)
			// c[4] = 30 -> парне (не підходить)
			int c[size] = { 15, 17, 20, 21, 30 };

			// Перевіряємо обчислення кількості (має бути 2)
			int actualCount = Count(c, size);
			Assert::AreEqual(2, actualCount);

			// Перевіряємо обчислення суми (17 + 21 = 38)
			int actualSum = Sum(c, size);
			Assert::AreEqual(38, actualSum);
		}
	};
}