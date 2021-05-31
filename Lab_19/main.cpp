#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите размер стэка" << endl;
    cin >> n;
    stack s(n);
    cout << "Стэк: ";
    s.print();
    cout << endl;
    cout << "Добавить число в стэк " << endl;
    s.push();
    cout << "Стэк после добавления " << endl;
    s.print();
    cout << endl;
    cout << "Стэк после удаления " << endl;
    s.pop();
    s.print();
    cout << endl;
    cout << "Верхний элемент стэка " << endl;
    cout << s.top() << endl;
}
