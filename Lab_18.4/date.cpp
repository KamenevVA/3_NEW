#include "date.h"
date::date(void):triad()
{
	day = 0;
	month = 0;
	year = 0;
}
date::~date(void)
{
}

date::date(int f, int s, int t, int D, int M, int Y):triad(f, s, t)
{
	day = D;
	month = M;
	year = Y;
}
date::date(const date& L)
{
	first = L.first;
	second = L.second;
	third = L.third;
	day = L.day;
	month = L.month;
	year = L.year;
}
void date::set_day(int D)
{
	day = D;
}
void date::set_month(int M)
{
	month = M;
}
void date::set_year(int Y)
{
	year = Y;
}
date& date::operator=(const date& L)
{
	if (&L == this)
	{
		return *this;
	}
	first = L.first;
	second = L.second;
	third = L.third;
	day = L.day;
	month = L.month;
	year = L.year;
	return *this;
}
istream& operator>>(istream& in, date& l)
{
	cout << "\nfirst: "; 
	in >> l.first;
	cout << "\nsecond: ";
	in >> l.second;
	cout << "\nthird: ";
	in >> l.third;
	cout << "\nday: ";
	in >> l.day;
	cout << "\nmonth: ";
	in >> l.month;
	cout << "\nyear: "; 
	in >> l.year;
	return in;
}
ostream& operator<<(ostream& out, const date& l)
{
	out << "\nfirst: " << l.first;
	out << "\nsecond: "<< l.second;
	out << "\nthird: "<< l.third;
	out << "\nday: "<< l.day;
	out << "\nmonth: "<< l.month;
	out << "\nyear: " << l.year;
	return out;
}
