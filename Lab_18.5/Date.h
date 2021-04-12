#pragma once
#include "Triad.h"
class Date : public Triad
{
public:
	Date(void);
	~Date(void);
	void Show();
	Date(int, int, int, int, int, int);
	Date(const Date&);
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	void set_day(int);
	void set_month(int);
	void set_year(int);
	Date& operator=(const Date&);
	friend istream& operator>>(istream& in, Date& l);
	friend ostream& operator<<(ostream& out,const Date& l);
protected:
	int day;
	int month;
	int year;

};

