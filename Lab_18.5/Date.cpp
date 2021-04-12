#include "Date.h"
Date::Date(void):Triad()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::~Date(void)
{
}
Date::Date(int F, int S, int T, int D, int M, int Y) : Triad(F, S, T)
{
	day = D;
	month = M;
	year = Y;
}
Date::Date(const Date& L)
{
	first = L.first;
	second = L.second;
	third = L.third;
	day = L.day;
}
void Date::set_day(int D)
{
	day = D;
}
void Date::set_month(int M)
{
	month = M;
}
void Date::set_year(int Y)
{
	year = Y;
}
Date& Date::operator=(const Date& l)
{
	if (&l == this) return *this;
	first = l.first;
	second = l.second;
	third = l.third;
	day = l.day;
	month = l.month;
	year = l.year;
	return *this;
}

istream& operator>>(istream& in, Date&l)
{
	cout << "\nFirst: "; in >> l.first;
	cout << "\nSecond: "; in >> l.second;
	cout << "\nThird: "; in >> l.third;
	cout << "\nDay: "; in >> l.day;
	cout << "\nMonth: "; in >> l.month;
	cout << "\nYear: "; in >> l.year;
	return in;
}
ostream& operator<<(ostream& out, const Date& l)
{
	out << "\nFIRST: " << l.first;
	out << "\nSECOND: " << l.second;
	out << "\nTHIRD: " << l.third;
	out << "\nDAY: " << l.day;
	out << "\nMONTH: " << l.month;
	out << "\nYEAR: " << l.year;
	cout << "\n";
	return out;
}
void Date::Show()
{
	cout << "\nFIRST: " << first;
	cout << "\nSEDCOND: " << second;
	cout << "\nTHIRD: " << third;
	cout << "\nDAY: " << day;
	cout << "\nMONTH: " << month;
	cout << "\nYEAR: " << year;
	cout << "\n";
}