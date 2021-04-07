#pragma once
#include <iostream>
#include <string>
using namespace std;

class flat
{
	string address;
	int citizen;
	double square;
public:
	flat();
	flat(string, int, double);
	flat(const flat&);
	~flat();
	string get_address();
	void set_address(string);
	int get_citizen();
	void set_cictizen(int);
	double get_square();
	void set_square(double);
	void show();
};
