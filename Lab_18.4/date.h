#pragma once
#include "Triad.h"
class date : public triad
{
public:
	date(void);
public:
	~date(void);
	date(int, int, int, int, int, int);
	date(const date&);
	int get_day()
	{
		return day;
	}
	void set_day(int);

	int get_month()
	{
		return month;
	}
	void set_month(int);

	int get_year()
	{
		return year;
	}
	void set_year(int);

	date& operator=(const date&);
	friend istream& operator>>(istream& in, date& l);
	friend ostream& operator<<(ostream& out, const date& l);
protected:
	int day;
	int month;
	int year;
};

