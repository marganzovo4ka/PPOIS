#include <iostream>
#include <cmath>
#include "Polynominal.h"
using namespace std;

int main()
{
	double coef1[4] = { 2, 5, 0, 1 };
	double coef2[5] = { 1, 0, 5, 4, 2 };
	Mnogochlen a(3, coef1);
	Mnogochlen b(4, coef2);
	Mnogochlen c;
	c = a - b;
	//Assert::IsTrue(c.ToString() == "-1 2 -4 -1");
	c.View();

	cout << c.ToString();
}

