#pragma once
#include <iostream>
#include<string>
using namespace std;
class triad
{
public:
	triad(void);
public:
	virtual ~triad(void);
	triad(int, int, int);
	triad(const triad&);
	int get_first()
	{
		return first;
	}
	int get_second()
	{
		return second;
	}
	int get_third()
	{
		return third;
	}
	void set_first(int);
	void set_second(int);
	void set_third(int);
	triad& operator=(const triad&);
	friend istream& operator>>(istream& in, triad& g);
	friend ostream& operator<<(ostream& out, const triad& g);
protected:
	int first;
	int second;
	int third;
};

