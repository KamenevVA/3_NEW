#pragma once
#include <iostream> 
using namespace std;
class money
{
	long rub;
	int pen;
public:
	money() {
		rub = 0;
		pen = 0.0;
	};
	money(int m, int s) {
		rub = m;
		pen = s;
	}
	money(const money& t)
	{
		rub = t.rub;
		pen = t.pen;
	}
	~money() {};
	int get_f() {
		return rub;
	}
	int get_sec() {
		return pen;
	}
	void set_f(int m)
	{
		rub = m;
	}
	void set_sec(int s) {
		pen = s;
	}
	money& operator=(const money&);
	money operator+(const money&);
	bool operator<(const money&);
	bool operator>(const money&);
	bool operator==(const money&);
	friend istream& operator>>(istream& in, money& t);
	friend ostream& operator<<(ostream& out, const money& t);
};
