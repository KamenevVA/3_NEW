#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int siz = 100;

struct info {
	string fio;
	string birthday;
	string address;
};

info* astr = new info[siz];

void make() {
	string a;
	ifstream str("Struct.txt");
	for (int i = 0; i < siz; i++) {
		if (str.is_open()) {
			if (getline(str, a)) {
				astr[i].fio = a;
			}
			if (getline(str, a)) {
				astr[i].birthday = a;
			}
			if (getline(str, a)) {
				astr[i].address = a;
			}
		}
	}
	str.close();
}

void linear_search() {
	string a;
	bool n = true;
	cout << "Введите ключ: ";
	getline(cin, a);
	getline(cin, a);
	for (int i = 0; i < siz; i++) {
		if (astr[i].fio == a) {
			cout << "Номер элемента: " << i + 1 << endl;
			cout << "Этот элемент: " << endl;
			cout << "	" << astr[i].fio << endl;
			cout << "	" << astr[i].birthday << endl;
			cout << "	" << astr[i].address << endl;
			n = false;
		}
	}
	if (n == true) {
		cout << "Элемент по такому ключу не найден !" << endl;
	}
}

void substr_search() {
	string substr;
	cout << "Введите подстроку: ";
	getline(cin, substr);
	getline(cin, substr);
	string str;
	bool x = true, n = true;
	for (int i = 0; i < siz; i++) {
		str = astr[i].address;
		for (int j = 0; j < str.size(); j++) {
			x = true;
			for (int k = 0; k < substr.size(); k++) {
				if (substr[k] != str[j + k]) {
					x = false;
				}
			}
			if (x == true) {
				cout << "Номер элемента: " << i + 1 << endl;
				cout << "Этот элемент: " << endl;
				cout << "	" << astr[i].fio << endl;
				cout << "	" << astr[i].birthday << endl;
				cout << "	" << astr[i].address << endl;
				n = false;
			}
		}
	}
	if (n == true) {
		cout << "Элемент по такому ключу не найден !" << endl;
	}
}


void interp_search() {
	int* arr = new int[siz];
	int sum;
	string str;
	for (int i = 0; i < siz; i++) {
		str = astr[i].fio;
		sum = 0;
		for (int j = 0; j < str.size(); j++) {
			sum += str[j];
		}
		arr[i] = sum;
	}
	int min, temp;
	for (int i = 0; i < siz - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < siz; j++)
		{
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	string key;
	int sumkey = 0;
	cout << "Введите ключ: ";
	getline(cin, key);
	getline(cin, key);
	for (int i = 0; i < key.size(); i++) {
		sumkey = sumkey + key[i];
	}
	int mid, left = 0, right = siz - 1;
	int answer;
	bool z = true;
	while (arr[left] <= sumkey && arr[right] >= sumkey && z) {
		mid = left + ((sumkey - arr[left]) * (right - left)) / (arr[right] - arr[left]);
		if (arr[mid] < sumkey) {
			left = mid + 1;
		}
		else {
			if (arr[mid] > sumkey) {
				right = mid - 1;
			}
			else {
				answer = mid;
				z = false;
			}
		}
	}
	sum = 0;
	int l = 0;
	if (z == true) {
		if (arr[left] == sumkey) {
			answer = left;
		}
		else {
			answer = -1;
		}
	}
	if (answer > -1) {
		for (int i = 0; i < siz; i++) {
			str = astr[i].fio;
			sum = 0;
			for (int j = 0; j < str.size(); j++) {
				sum += str[j];
			}
			if (sum == arr[answer]) {
				cout << "Номер элемента: " << i + 1 << endl;
				cout << "Этот элемент: " << endl;
				cout << "	" << astr[i].fio << endl;
				cout << "	" << astr[i].birthday << endl;
				cout << "	" << astr[i].address << endl;
			}
		}
	}
	else {
		cout << "Элемент по такому ключу не найден" << endl;
	}
}

void print() {
	cout << "Стрктура: " << endl;
	for (int i = 0; i < siz; i++) {
		cout << i + 1 << " элемент: " << endl;
		cout << "	" << astr[i].fio << endl;
		cout << "	" << astr[i].birthday << endl;
		cout << "	" << astr[i].address << endl;
	}
}


void save() {
	string a;
	ofstream str;
	str.open("Struct.txt");
	for (int i = 0; i < siz; i++) {
		str << astr[i].fio << endl;
		str << astr[i].birthday << endl;
		str << astr[i].address << endl;
	}
	str.close();
}

int main() {
	setlocale(LC_ALL, "Rus");
	bool x = true;
	int i;
	while (x) {
		cout << "1 - Взять информацию из файла Struct.txt" << endl;
		cout << "2 - Сохранить структуру в файл Struct.txt" << endl;
		cout << "3 - Вывести структуру на экран" << endl;
		cout << "4 - Найли элемент в структуре" << endl;
		cout << "0 - Выйти из программы" << endl;
		cout << "Ваш выбор: ";
		cin >> i;
		switch (i) {
		case 1:
			make();
			break;
		case 2:
			save();
			break;
		case 3:
			print();
			break;
		case 4:
			int v;
			cout << "1 - Метод линейного поиска" << endl;
			cout << "2 - Метод поиска подстроки в строке" << endl;
			cout << "3 - Интреполяционный метод" << endl;
			cout << "0 - Выбрать другое действие" << endl;
			cout << "Ваш выбор: ";
			cin >> v;
			switch (v) {
			case 1:
				linear_search();
				break;
			case 2:
				substr_search();
				break;
			case 3:
				interp_search();
				break;
			case 0:
				break;
			default:
				cout << "Неизвестный выбор, попробуйте ещё раз !" << endl;
				break;
			}
			break;
		case 0:
			x = 0;
			break;
		default:
			cout << "Неизвестный выбор, попробуйте ещё раз !" << endl;
			break;
		}
	}
	return 0;
}
