#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Triad :
	public Object
{
public:
	Triad(void);
public:
	virtual ~Triad(void);
	void Show();
	Triad(int, int, int);
	Triad(const Triad&);
	int get_first() { return first; }
	int get_second() { return second; }
	int get_third() { return third; }
	void set_first(int);
	void set_second(int);
	void set_third(int);
	Triad& operator=(const Triad&);
	friend istream& operator >>(istream& in, Triad& c);
	friend ostream& operator <<(ostream& out, const Triad& c);
protected:
	int first;
	int second;
	int third;

};

