#include <iostream>
#include <ctime>
#include <set>
#include "Set_def.h"

using namespace Sets;
int mn[20], mn2[20], mn3[20];
set <int> m1, m2, m3, m4, m5, m6, m7, m8;
int f, e;
int p = 0;
bool a, z, vvod = true;


int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	bool x = true;
	bool y = true;
	while (x) {
		cout << "\nВыберети действие " << endl;
		cout << "1 - Автоматическое создание множества" << endl;
		cout << "2 - Создание множества вручную" << endl;
		cout << "3 - Создание множества с заданым условием" << endl;
		cout << "0 - Для выхода из программы" << endl;
		cin >> f;
		switch (f)
		{
		case 1:																						//Создание 1-ого множества:
			cout << "Введите количсетво чисел в множестве" << endl;
			while (z == true) {
				cin >> e;
				if ((e < 1) || (e > 19)) {
					cout << "Вы ввели недопустимое число, введите коректное число!";
				}
				else {
					z = false;
				}
			}
			cout << "Автоматическое создание множества..." << endl;
			cout << "1-ое множество:" << endl;
			for (int i = 0; i < e; i++) {
				m1.insert(rand() % 19 - 9);
			}
			cout << "{" << m1 << " }" << endl;
			break;
		case 2:																						//Создание 2-ого множества:
			cout << "Введите количество чисел в множестве, не больше 19 " << endl;
			int n;
			while (a == true) {
				cin >> n;
				if ((n < 1) || (n > 19)) {
					cout << "Вы ввели недопустимое число, введите коректное число!";
				}
				else {
					a = false;
				}
			}
			cout << "Заполните множетсво числами от -9 до 9" << endl;
			for (int i = 0; i< n; i++){
			int b;
		Second:
			cin >> b;
			if ((b < -9) || (b > 9)) {
				while (a == true) {
					cin >> n;
					if ((n < 1) || (n > 19)) {
						cout << "Вы ввели недопустимое число, введите коректное число!";
					}
					else {
						a = false;
					}
				}cout << "Вы ввели недопустимое число, введите коректное число!" << endl;
				goto Second;
			}
			else {
				mn2[i] = b;
				for (int j = 0; j < i; j++) {
					if (mn2[i] == mn2[j]) {
						cout << "Вы ввели недопустимое число, введите коректное число!" << endl;
						goto Second;
					}
				}
			}
		}
			for (int i = 0; i < n; i++)
			{
				m2.insert(mn2[i]);
			}

			cout << "2-ое множество:" << endl;
			cout << "{" << m2 << " }" << endl;
			break;
		case 3:																							//Создание 3-ого множества:
			cout << "Сгенерированное множество:" << endl;
			int k1, k2;
			for (int i = 0; i < 19; i++) {
			F:
				mn[i] = rand() % 19 - 9;
				for (int j = 0; j < i; j++) {
					if (mn[j] == mn[i]) {
						goto F;
					}
				}
			}
			for (int i = 0; i < 19; i++) {
				m3.insert(mn[i]);
			}
				cout << "{" << m3 << "}" << endl;
				
				while (y) {
					int v;
					cout << "\n1 - Вывести все отрицательные числа" << endl;
					cout << "2 - Вывести все положительные числа" << endl;
					cout << "3 - Вывести числа которые кратны числу" << endl;
					cout << "4 - Вывести все нечентые числа" << endl;
					cout << "5 - Вывести все четные числа" << endl;
					cout << "0 - Выход из программы " << endl;
					cin >> v;
					switch (v) {
					case 1:
						for (int i = 0; i < 19; i++) {
							if (mn[i] < 0) {
								mn3[p] = mn[i];
								p++;
							}
						}
						for (int i = 0; i < p; i++) {
							m4.insert(mn3[i]);
						}
						cout << "{" << m4 << "}";
						break;
					case 2:
						p = 0;
						for (int i = 0; i < 19; i++) {
							if (mn[i] >= 0) {
								mn3[p] = mn[i];
								p++;
							}
						}
						for (int i = 0; i < p; i++) {
							m5.insert(mn3[i]);
						}
						cout << "{" << m5 << "}";
						break;
					case 3:
						int c;
						cout << "Введите число кратности" << endl;
						cin >> c;
						if ((c == 0) || (c < -9) || (c > 9)) {
							cout << "Недопустимое число" << endl;
						}
						else {
							p = 0;
							for (int i = 0; i < 19; i++) {
								if ((mn[i] % c == 0) && (mn[i] != 0)) {
									mn3[p] = mn[i];
									p++;
								}
							}
							for (int i = 0; i < p; i++) {
								m6.insert(mn3[i]);
							}
							cout << "{" << m6 << "}";
						}
						break;

					case 4:
						p = 0;
						for (int i = 0; i < 19; i++) {
							if (mn[i] % 2 != 0) {
								mn3[p] = mn[i];
								p++;
							}
						}
						for (int i = 0; i < p; i++) {
							m7.insert(mn3[i]);
						}
						cout << "{" << m7 << "}";
						break;
					case 5:
						p = 0;
						for (int i = 0; i < 19; i++) {
							if ((mn[i] % 2 == 0) && (mn[i] != 0)) {
								mn3[p] = mn[i];
								p++;
							}
						}
						for (int i = 0; i < p; i++) {
							m8.insert(mn3[i]);
						}
						cout << "{" << m8 << "}";
						break;
					case 0:
						y = false;
						break;
					default:
						cout << "Неизвестный выбор, попробуйте ещё раз!" << endl;
						break;
					}
				}
		case 0:
			x = false;
			break;
		default:
			cout << "Неизвестный выбор, попробуйте ещё раз!" << endl;
		}
	}


	return 0;
}
