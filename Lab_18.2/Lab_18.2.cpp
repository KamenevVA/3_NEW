#include <iostream>
#include"flat.h"
#include <string>
#include <windows.h>
using namespace std;

flat make_flat()
{
	string a;
	int c;
	double s;
	cout << "Введите адрес: " << endl;
	cin.ignore();
	getline(cin, a);
	cout << "Введите количество жителей: " << endl;
	cin >> c;
	cout << "Введите площадь квартиры: " << endl;
	cin >> s;
	flat t(a, c, s);
	return t;
}

void print_flat(flat t)
{
	t.show();
}



int main()
{
	setlocale(LC_ALL, "Rus");
	flat t1;
	t1.show();
	flat t2("Mira 19", 215, 1500);
	t2.show();
	flat t3 = t2;
	t3.set_address("Lenina 20");
	t3.set_cictizen(350);
	t3.set_square(1915.00);
	print_flat(t3);
	t1 = make_flat();
	t1.show();
	return 0;
}
