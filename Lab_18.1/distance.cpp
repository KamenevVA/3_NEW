#include <iostream>
#include "dist.h"
#include <math.h>
using namespace std;

void dist::Init(double F, double S)
{
	first = F; second = S;
}

void dist::Read()
{
	cout << "\nВведите координату x: ";cin >> first;
	cout << "\nВведите координату y:";cin >> second;
}

void dist::Show()
{
	cout << "\nКоордината x =" << first;
	cout << "\nКоордината y =" << second;
	cout << "\n";
}

double dist::distance()
{
	return sqrt(first*first + second*second);
}
