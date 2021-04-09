#include "Triad.h"
triad::triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}
triad::~triad(void)
{

}
triad::triad(int f, int s, int t)
{
	first = f;
	second = s;
	third = t;
}
triad::triad(const triad& a)
{
	first = a.first;
	second = a.second;
	third = a.third;
}
void triad::set_first(int f)
{
	first = f;
}
void triad::set_second(int s)
{
	second = s;
}
void triad::set_third(int t)
{
	third = t;
}
triad& triad::operator=(const triad& g)
{
	if (&g == this)
	{
		return*this;
	}
	first = g.first;
	second = g.second;
	third = g.third;
	return *this;
}
istream& operator>>(istream& in, triad& g)
{
	cout << "\nfirst: "; in >> g.first;
	cout << "\nsecond: "; in >> g.second;
	cout << "\nthird: "; in >> g.third;
	return in;
}
ostream& operator<<(ostream&out, const  triad& g)
{
	out << "\nfirst: " << g.first;
	out << "\nsecond: " << g.second;
	out << "\nthird: " << g.third;
	return out;
}
