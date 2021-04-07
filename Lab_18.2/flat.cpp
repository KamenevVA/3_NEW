#include "flat.h"
#include <iostream>
#include <string>
using namespace std;

flat::flat()
{
	address = "";
	citizen = 0;
	square = 0;
	cout << "Конструктор без параметров для объекта " << this << endl;
}

flat::flat(string A, int C, double S)
{
	address = A;
	citizen = C;
	square = S;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}

flat::flat(const flat& t)
{
	address = t.address;
	citizen = t.citizen;
	square = t.square;
	cout << "Конструктор копирования для объекта " << this << endl;
}

flat::~flat()
{
	cout << "Деструктор для объекта " << this << endl;
}

string flat::get_address()
{
	return address;
}
int flat::get_citizen()
{
	return citizen;
}
double flat::get_square()
{
	return square;
}
void flat::set_address(string A)
{
	address = A;
}
void flat::set_cictizen(int C)
{
	citizen = C;
}
void flat::set_square(double S)
{
	square = S;
}
void flat::show()
{
	cout << "Адрес: " << address <<endl;
	cout << "Количество жителей: " << citizen <<endl;
	cout << "Площадь квартиры: " << square <<endl;
}
