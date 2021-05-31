#include "Dialog.h"
#include "Event.h"


Dialog::Dialog(void) :Person(0)
{
	EndState = 0;
}



Dialog::~Dialog(void)
{
}



void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "m+-szq"; 
	string s;
	string param;
	char code;
	cout << "Âîçìîæíûå êîìàíäû:  m+-szq" << endl << "m - ñîçäàòü ãðóïïó(íå ñîçäàøü ãðóïïó íå ñìîæåøü âçàèìîäåéñòâîâàòü ñ ëþäüìè)"
		<< endl << "+ - äîáàâàòü ÷åëîâåêà â ãðóïïó" << endl << "-  - óäàëèòü ÷åëîâåêà èç ãðóïïû" << endl
		<< "s - âûâåñòè âñåõ ëþäåé ãðóïïû" << endl << "z - ñðåäèíèé âîçðàñò ïî ãðóïïå" << endl
		<< "q - îêîí÷àíèå ïðîãðàììû" << endl << "Ââåäèòå ÷òî áóäåì äåëàòü" << endl << '>';
	cin >> s; code = s[0];
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case'z': event.command = cmGet; break; 
		case'q': event.command = cmQuit; break; 		
		}
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);

			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else event.what = evNothing;
}
int Dialog::Execute()
{
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}
int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}


void Dialog::EndExec()
{
	EndState = 1;
}



void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			cout << "Âû ñîçäàëè ãðóïïó" << endl << endl;
			size = 10; 
			beg = new Object * [size];
			cur = 0; 
			ClearEvent(event);
			break;
		case cmAdd:
			cout << "Êîãî äîáàâèì â ãðóïïó" << endl << endl;
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			cout << "Óäàëèëè ïîñëåäíåãî ÷åëîâåêà äîáîâëåííîãî â ãðóïïó" << endl << endl;
			Del();
			ClearEvent(event);
			break;
		case cmShow:
			cout << "Íà äàííûé ìîìåíò èìååòñÿ òàêàÿ ãðóïïà" << endl << endl;
			Show();
			ClearEvent(event);
			break;
		case cmQuit:
			cout << "Âû ðåøèëè çàêîí÷èòü ñ ïðîãðàììîé" << endl << endl;
			EndExec(); 
			ClearEvent(event);
			break;
		case cmGet:	
			cout << "Âîçðàñò âñåõ ëþäåé" << endl << endl;
			Person::HandleEvent(event);
			ClearEvent(event);
			break;
		default:
			cout << "Òàêîãî ñîáûòèÿ íåò" << endl << endl;
		};
	}
}
