#include <iostream>
#include <ctime>
#include <string>
#include <math.h> 

using namespace std;

struct person {
    string name;
    string addres;
    string phone;
};

struct h_person {
    person current;
    h_person* next;
};

int get_value(string str) {
    int value = 0;
    int j = 1;
    for (auto i : str) {
        value += i * j;
        j++;
    }
    return value;
}

int hash_func(string key, int size) {
    double f;
    return int(size * modf(get_value(key) * 0.803523421, &f));
}

pair<h_person**, int> make_table(person* items, int n, int size) {
    h_person** table = new h_person * [size];
    for (int i = 0; i < size; i++) {

        table[i] = nullptr;
    }
    int n_of_collisions = 0;
    for (int i = 0; i < n; i++) {
        int hash = hash_func(items[i].name, size);
        if (table[hash] == nullptr) {
            h_person* p = new h_person;
            p->current = items[i];
            p->next = nullptr;
            table[hash] = p;
        }
        else {
            n_of_collisions++;
            h_person* current = table[hash];
            while (current->next != nullptr) {
                current = current->next;
            }
            h_person* p = new h_person;
            p->current = items[i];
            p->next = nullptr;
            current->next = p;
        }
    }
    return make_pair(table, n_of_collisions);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите необходимое количество генерируемых людей: ";
    cin >> n;
    person* people = new person[n];
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        person p;
        string full_name;
        string names[] = { "Aleksadr", "Stepan","Vladimir","Ivan", "Vladislav", "Petr","Igor", "Valentin", "Mark" };
        string surnames[] = { "Ivanov","Olegov", "Petrov", "Sokolov", "Mironov", "Vesnin", "Egorov", "Smirnov" };
        string thirdnames[] = { "Aleksandrovich","Andreevich","Petrovich","Evgenievich", "Urievisch", "Pavlovich" };
        full_name = names[rand() % 7] + " " + surnames[rand() % 6] + " " + thirdnames[rand() % 5];
        p.name = full_name;
        string number;
        for (int i = 0; i < 10; i++) {
            number.push_back(rand() % 10 + 48);
        }
        p.phone = number;
        string addres1[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
        string homes[] = { "Ленина", "Мира", "Пушкина", "Садовая", "Советская", "Центральная", "Молодёжная", "Школьная", "Лесная" };
        p.addres = homes[rand() % 7] + ' ' + addres1[rand() % 6 + 2] + addres1[rand() % 5 + 3];
        people[i] = p;
    }
    cout << "Введите размер хэш таблицы: ";
    int size;
    cin >> size;
    auto table = make_table(people, n, size);
    cout << "Количество коллизий: " << table.second << endl;
    int input = -1;
    while (input != 0) {
        cout << "0 - выход из программы, 1 - вывод на экран, 2 - поиск человека по ФИО\n";
        cin >> input;
        if (input == 1) {
            for (int i = 0; i < n; i++) {
                cout << people[i].name << ' ' << people[i].phone <<  ' ' << people[i].addres << endl;
            }
        }
        else if (input == 2) {
            cout << "Введите ФИО: ";
            string key;
            cin.ignore();
            getline(cin, key);
            int hash = hash_func(key, size);
            h_person* current = table.first[hash];
            if (current != nullptr) {
                while (current->current.name != key && current->next != nullptr) {
                    current = current->next;
                }
                if (current->current.name == key) {
                    cout << "Адрес: " << current->current.addres << endl;
                    cout << "Номер телефона: " << current->current.phone << endl;
                }
                else {
                    cout << "Такой человек не надйен" << endl;
                }
            }
            else {
                cout << "Такой человек не найден" << endl;
            }
        }
    }
}
