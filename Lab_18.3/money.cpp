#include "money.h" 
#include <iostream> 
using namespace std;
money& money::operator=(const money& t)
{
	if (&t == this)
		return *this;
	rub = t.rub;
	pen = t.pen;
	return *this;
}
bool money::operator<(const money& p)
{
	return rub < p.rub;
}
bool money::operator>(const money& p)
{
	return rub > p.rub;
}

bool money::operator==(const money& p)
{
	return (rub == p.rub) && (pen == p.pen);
}

money money::operator+(const money& t)
{
	long temp1 = rub * 100 + pen;
	long temp2 = t.rub * 100 + t.pen;
	money p;
	p.rub = (temp1+temp2) / 100;
	p.pen = (temp1+temp2) % 100;
	return p;
}
istream& operator>>(istream& in, money& t)
{
	cout << "Введите рубли:";
	cin >> t.rub;
	cout << "Введите копейки:";
	cin >> t.pen;
	return in;
}
ostream& operator<<(ostream& out, const money& t)
{

	return (out << t.rub << "," << t.pen);
}
