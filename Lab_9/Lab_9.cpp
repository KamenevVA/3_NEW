#include <iostream>
#include <fstream>
#include<string>
using namespace std;

bool isNumber(string str)
{
	int k = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			return 1;
			
		}
		else
		{
			str[i] = str[i + 1];
			k++;
		}
	}
	if (k == str.length())
	{
		return 0;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	int n; //кол-во строк в F1.txt
	cout << "Введите кол-во строк: ";
	cin >> n;
	cin.ignore();



	ofstream file1("F1.txt");
	if (!file1.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}


	string str;
	cout << "Введите строки: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << " ";
		getline(cin, str);
		file1 << str << "\n";
	}
	file1.close();



	ifstream fin("F1.txt");
	if (!fin.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}


	cout << "Содержание файла F1:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << " ";
	    getline(fin, str);
		cout << str << endl;
	}
	fin.close();
	fin.clear();


	ofstream file2("F2.txt");
	if (!file2.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}

	fin.open("F1.txt");
	if (!fin.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}
	int n1 = 0; //кол-во строк в F2.txt
    for (int i = 0; i <= n; i++)
	{
		getline(fin, str);
		if (isNumber(str) == 0)
		{
				file2 << str << "\n";
				n1++;
		}
	}
	file2.close();
	fin.close();
	file2.clear();
	fin.clear();
	int k = 0;
	fin.open("F2.txt");
	if (!fin.is_open())
	{
		cout << "Файл не открыт: ";
		return 0;
	}
	cout << "Содержание файла F2.txt: " << endl;
	for (int i = 0; i < n1; i++)
	{
		cout << " ";
		getline(fin, str);
		if ((str[0] == 'A') or (str[0] == 'a'))
		{
			k++;
		}
		cout << str << endl;
	}
	if (k == 0) {
		cout << "Строк, начинающихса на А нет.";
	}
	else {
		cout << "Строк, начинающихся на А: " << k;
	}
	fin.close();
	fin.clear();
	return 0;
}
