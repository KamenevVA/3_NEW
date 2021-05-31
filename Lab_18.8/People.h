#pragma once
#include <iostream>
#include "Object.h"
#include "People.h"
#include "Event.h"
using namespace std;


class People :
	public Object
{
public:
	People(void);

public:
	virtual ~People(void);
	void Show();
	void Input();	
	People(string, int);
	People(const People&);


	string Get_Name() { return Name; }
	int Get_Age() { return Age; }


	void Set_Name(string);
	void Set_Age(int);

	People& operator=(const People&);		
	void HandleEvent(const TEvent& e);
	void average_age(const TEvent& e);
protected:
	string Name;
	int Age;
};
