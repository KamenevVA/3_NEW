#pragma once
#include <iostream>
#include "Object.h"
#include "People.h"
#include "Abiturient.h"
#include "Event.h"
#include "Person.h"
#include "Dialog.h"
using namespace std;


class Dialog :
	public Person
{
public:
	Dialog(void);
	virtual ~Dialog(void);

	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event); 
	virtual void ClearEvent(TEvent& event);

	int Valid();
	void EndExec();
protected:
	int EndState;
};
