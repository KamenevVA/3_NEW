#include "People.h"
#include "Event.h"


People::People(void)
{
	Name = "";
	Age = 0;
}



People::~People(void)
{}


People::People(string N, int A)
{
	Name = N;
	Age = A;;
}


People::People(const People& car)
{
	Name = car.Name;
	Age = car.Age;
}


void People::Set_Age(int A)
{
	Age = A;
}
void People::Set_Name(string N)
{
	Name = N;
}

People& People::operator=(const People& c)
{
	if (&c == this)return *this;
	Name = c.Name;
	Age = c.Age;
	return *this;
}


void People::Show()
{
	cout << "\nName : " << Name;
	cout << "\nAge : " << Age;
	cout << endl << endl;
}


void People::Input()
{
	cout << "\nName:"; cin >> Name;
	cout << "\nAge:"; cin >> Age;
	cout << endl << endl;
}


int sum = 0;
int k = 0;

void People::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			sum = sum + Get_Age();
			k++;
			cout << "Âîçðàñò ÷åëîâåêà" << endl << Get_Age() << endl << endl;
			break;
		}
	}
}


void People::average_age(const TEvent& e)
{
	cout << "Îáùèé âîçðàñò" << endl << sum << endl << endl;
	sum = sum / k;
	cout << "Ñðåäíèé âîçðàñò" << endl << sum << endl << endl;
}
