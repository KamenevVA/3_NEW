#include "money.h" 
#include <iostream> 
using namespace std;
void main()
{
	setlocale(LC_ALL, "Rus");
	money a;
	money b;
	money c;
	cin >> a;
	cin >> b;
	cout << "Первая сумма денег:" << a << endl;
	cout << "Вторая сумма денег:" << b << endl;
	c = a + b;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
	cout << "a > b= " << (a > b) << endl;
	cout << "a < b= " << (a < b) << endl;
	cout << "a == b= " << (a == b) << endl;
}
