#include <iostream>
using namespace std;

int n;
int a[100];

void sort(int a[100], int Left, int Right)//Left-первый индекс массива, Right-последний индекс массива.
{
	int i, j, x, y;
	i = Left;
	j = Right;
	x = a[(Left+Right) / 2]; //x - значение среднего элемента массива.
	while (a[i] < x)
	{
		i++;
	}
	while (a[j] > x)
	{
		j--;
	}
	if (i <= j)
	{
		y = a[i];
		a[i] = a[j];
		a[j] = y;
		i++;
	    j--;
	}
	if (Left < j)
	{
		sort(a, Left, j);
	}
	if (i < Right)
	{
		sort(a, i, Right);
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 - 50;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
	sort(a, 0, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
