#include <iostream>
#include<string>
using namespace std;

struct items
{
	string name;
	int size;
};

void ShellSort(items* arr, int n)
{
	int b = n / 2;
	while (b > 0)
	{
		for (int i = 0; i < n - b; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (arr[j].size < arr[j + b].size)
				{
					int d = arr[j].size;
					arr[j].size = arr[j + b].size;
					arr[j + b].size = d;
					string f = arr[j].name;
					arr[j].name = arr[j + b].name;
					arr[j + b].name = f;
					j -= b;
				}
				else
					j = -1;
			}
		}
		b /= 2;
	}
}

void HoaraSort(items* arr, int left, int right)
{
	int d;
	string f;
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (arr[i].size > arr[(left + right) / 2].size && i < right)
			i++;
		while (arr[j].size < arr[(left + right) / 2].size && j > left)
			j--;
		if (i <= j)
		{
			d = arr[i].size;
			arr[i].size = arr[j].size;
			arr[j].size = d;
			f = arr[i].name;
			arr[i].name = arr[j].name;
			arr[j].name = f;
			i++;
			j--;
		}
		if (i < right)
		{
			HoaraSort(arr, i, right);
		}
		if (j > left)
		{
			HoaraSort(arr, left, j);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество предметов: ";
	cin >> n;
	cout << "Введите предметы: " << endl;
	cin.ignore();
	items* st = new items[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Название дисплея:";
		cout << " ";
		getline(cin, st[i].name);
		cout << "Размер дисплея:";
		cin >> st[i].size;
		cin.ignore();
	}
	int a;
	cout << "Введите 0, если хотите произвести сортировка методом Шелла\nВведите 1, если хотите произвести сортировку методом Хоара." << endl;
	cin >> a;
	switch (a)
	{
	case 0: ShellSort(st, n); break;
	case 1: HoaraSort(st, 0, n - 1);; break;
	default: cout << "Неизвестная операция. Сортировка не выполнена." << endl;
	}
	cout << endl << "После сортировки: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Название дисплея: " << st[i].name << endl;
		cout << "Размер дисплея: " << st[i].size << endl;
	}
}
