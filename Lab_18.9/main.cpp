#include "Vector.h"
#include "error.h"
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	try
	{
		int n;
		cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ" << endl;
		cin >> n;

		Vector a(n, 0);
		Vector b(n, 3);
		int i;
		
		
		cout << "Ââåäèòå ýëåìåíòû âåêòîðà a" << endl;
		cin >> a;
		cout << endl;
		cout << "Âåêòîð a" << endl;
		cout << a << endl << endl;
		cout << "Âåêòîð b çàäàííûé ÷åðåç ïàðàìåòð" << endl;
		cout << b << endl << endl;

		cout << "Ðàçìåð âåêòîðà a" << endl;
		cout << a() << endl << endl;

		cout << "Ââåäèòå íîìåð ýëåìåíòà âåêòîðà a" << endl;
		cin >> i;
		cout << "Ýëåìåíò ïîä íîìåðîì  " << i << endl;
		cout << a[i] << endl << endl;

		cout << "Ââåäèòå ê êàêîìó ýëåìåíòó âåêòîðà a ïåðåéòè" << endl;
		cin >> i;
		cout << "Ýòîò ýëåìåíò" << endl;
		cout << a + i << endl << endl;


		cout << "Óìíîæåíèå ýëåìåíòîâ âåêòîðîâ a[i]*b[i]" << endl;	
		for (int i = 0; i < n; i++)
		{
			cout << a[i] * b[i] << "  ";
		}
		cout << endl << endl;
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}
