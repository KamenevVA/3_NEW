#pragma once
#include <iostream>
#include "Object.h"
#include "Event.h"
#include "Person.h"

using namespace std;


class Person
{
public:
	Person(int);
public:
	~Person(void);
	void Add();
	void Del();
	void Show();
	
	int operator()();
	void HandleEvent(const TEvent& e);
	void average_age(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};
