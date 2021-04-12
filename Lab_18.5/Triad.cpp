#include "Triad.h"
Triad::Triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}
Triad::~Triad(void)
{
}
Triad::Triad(int F, int S, int T)
{
	first = F;
	second = S;
	third = T;
}
Triad::Triad(const Triad& triad)
{
	first = triad.first;
	second = triad.second;
	third = triad.third;
}
void Triad::set_first(int F)
{
	first = F;
}
void Triad::set_second(int S)
{
	second = S;
}
void Triad::set_third(int T)
{
	third = T;
}

Triad& Triad::operator=(const Triad& c)
{
	if (&c == this) return *this;
	first = c.first;
	second = c.second;
	third = c.third;
	return *this;
}
istream& operator>>(istream& in, Triad& c)
{
	cout << "\nFirst: "; in >> c.first;
	cout << "\nSecond: "; in >> c.second;
	cout << "\nThird: "; in >> c.third;
	return in;
}
ostream& operator<<(ostream& out, const Triad& c)
{
	out << "\nFirst :" << c.first;
	out << "\nSecond :" << c.second;
	out << "\nThird :" << c.third;
	return out;
}
void Triad::Show()
{
	cout << "\FIRST: " << first;
	cout << "\nSECOND: " << second;
	cout << "\nTHIRD: " << third;
	cout << "\n";
}