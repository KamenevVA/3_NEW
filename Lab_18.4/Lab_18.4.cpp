#include "Triad.h"
#include "date.h"
#include <iostream>
using namespace std;

void f1(triad& c)
{
	c.set_first(20);
	cout << c;
}

triad f2()
{
	date l(20, 10, 15, 25, 2, 2002);
	return l;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	triad a;
	cin >> a;
	cout << a;
	triad b(10, 100, 1000);
	cout << "\n";
	cout << b;
	cout << "\n";
	cout << "Копирован b в a" << endl;
	a = b;
	cout << a;
	date c;
	cin >> c;
	cout << c;
	cout << "\n";
	cout << "Изменение значения first " << endl;
	f1(c);
	a = f2();
	cout << "\n";
	cout << "Изменение всех полей" << endl;
	cout << a;
}
