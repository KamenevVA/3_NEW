#include <iostream>
using namespace std;
int n, k, c, k_id, t;
int a[100];


int main()
{
	setlocale(LC_ALL, "");
	cout << "Введите количество чисел в массиве: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100-50;
		cout << a[i] << " ";
	}

	
	cout << "\nВведите значение, которое необходимо удалить из массива: ";
	cin >> k;
	c = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == k)
		{
			c = a[i];
			k_id = i;
			if (k_id == n)
			{
				n = n - 1;
			}
			else {
				for (int j = k_id; j < n - 1; j++)
				{
					a[j] = a[j + 1];
				}
				n--;
			}
		}
	}
	if (c == 0)
	{
		cout << "Такой элемент в массиве не найден.";
	}
	else {
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
	}

	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			n++;
			for (int j = n; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			i++;
			a[i] = 0;
			
		}
	}

for (int i = 0; i < n; i++)
{
	cout << a[i] << " ";
}
	return 0;
}
