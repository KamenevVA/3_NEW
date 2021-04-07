#include <iostream>
#include "dist.h"
#include <math.h>
using namespace std;

dist make_distance(double F, double S)
{
	dist t;
	t.Init(F, S);
	return t;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	dist A;
	dist B;
	A.Init(3.0, 4.0);
	B.Read();
	A.Show();
	B.Show();
	cout << "A.distanse(" << A.first << ", " << A.second << ")=" << A.distance() << endl;
	cout << "B.distance(" << B.first << ", " << B.second << ")=" << B.distance() << endl;



	dist* X = new dist;
	X->Init(6.0, 8.0);
	X->Show();
	X->distance();
	cout << "X.distance(" << X->first << ", " << X->second << ")=" << X->distance() << endl;
	
	
	
	dist mas[3];
	for (int i = 0; i < 3; i++)
	{
		mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].Show();
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].distance();
		cout << "mas[" << i << "].disctance(" << mas[i].first << ", " << mas[i].second << ") = " << mas[i].distance() << endl;
	}

	dist* d_mas = new dist[3];
	for (int i = 0; i < 3; i++)
	{
		d_mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		d_mas[i].Show();
	}
	for (int i = 0; i < 3; i++)
	{
		d_mas[i].distance();
		cout << "d_mas[" << i << "].disctance(" << d_mas[i].first << ", " << d_mas[i].second << ") = " << d_mas[i].distance() << endl;

	}


	double y; double x;
	cout << "Введите координату x: ";
	cin >> x;
	cout << "Введите координату y: ";
	cin >> y;
	dist F = make_distance(x, y);
	F.Show();
	F.distance();
	return 0;
}
