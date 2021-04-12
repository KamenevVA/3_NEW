#include "Object.h"
#include "Triad.h"
#include "Date.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Vector v(5);
	Triad a;
	cin >> a;
	Date b;
	cin >> b;
	Object* p = &a;
	cout << "Просмотре объектов класса Triad через указатель " << endl;
	p->Show();
	v.Add(p);
	p = &b;
	cout << "Просмотре объектов класса Date через указатель " << endl;
	p->Show();
	v.Add(p);
	cout << "Содержание вектора " << endl;
	cout << v;
	return 0;
}
