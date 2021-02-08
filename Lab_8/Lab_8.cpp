#include <iostream>
#include<stdio.h>
using namespace std;
struct myStruct
{
	string name[40]; //ФИО
	string adress[40]; //Адресс
	int number; //Номер
	int card_number; //Номер карты
};


struct List
{
	char data;
	List* next;
};

List* readFile() {
    List* first, * p;
    first = NULL; // Пока нет элементов, указываем на нул
    FILE* fp;
    if ((fp = fopen("data.dat", "rb")) == NULL) {
        perror("\nОшибка при открытии файла data.dat");
        exit(0);
    }
    p = new List;
    if (!feof(fp)) 
    {
        if (fread(&p->data.name, sizeof(char), 1, fp) != 1) {
            perror("\nОшибка при открытии файла data.dat");
            exit(0);
        }
        cout << p->data.name;
        exit(0);
    }
    fclose(fp);
    cout << "Чтение окончено" << endl;
    return first;
}

void saveFile(List* first) {
    if (first == NULL) {
        cout << "Список пуст" << endl;
    }
    else {
        List* p = first;

        FILE* fp;
        if ((fp = fopen("data.dat", "wb")) == NULL) {
            perror("\nОшибка при открытии файла data.dat");
            exit(0);
        }
        rewind(fp);
        while (!feof(fp) && p != NULL) {
            fwrite(&p->data.name, sizeof(string), 1, fp);
            fwrite(&p->data.adress, sizeof(string), 1, fp);
            fwrite(&p->data.number, sizeof(int), 1, fp);
            fwrite(&p->data.card_number, sizeof(int), 1, fp);
            p = p->next;
        }
        fclose(fp);
    }
}

List* make() {
    List* first, * p;
    first = NULL; // Пока нет элементов, указываем на нул

    p = new List;   // Память под элемент

    // Инициализация первого элемента
    p->data.name = "Иванов Иван Петрович";
    p->data.adress = "г.Москва, ул.Ленина, 17.";
    p->data.number = 79993332211;
    p->data.card_number = 1276390011241765;
    p->next = NULL; // Это последний элемент

    first = p;

    List* h = new List; // Память под новый элемент
    p->next = h;
    p = p->next;        // Перешли к управлению над след элементом, так сказать :)
    p->data.name = "Петров Иван Сергеевич";
    p->data.adress = "г.Пермь, ул.Леонова, 25";
    p->data.number = 79998887766;
    p->data.card_number = 1600523114952873;
    p->next = NULL; // Это последний элемент
    return first;
}


void del(List*& first, int count)
{
    if (first == NULL)
    {
        cout << "Список пуст" << endl;
    }
    else 
    {
        List* p = first;
        for (int i; i <= count; i++)
        {
            List* q = p->next;
            first = p->next;
            delete q;
            p = first;
        }
    }
}

void print(List* first) {
    if (first == NULL) {
        cout << "Список пуст" << endl;
    }
    else {
        List* p = first;
        while (p != NULL) {
            cout << "ФИО: " << p->data.name << " | ";
            cout << "Адрес: " << p->data.adress << " | ";
            cout << "Номер: " << p->data.number << " | ";
            cout << "Номер карты: " << p->data.card_number << endl;
            p = p->next;
        }
    }
}

int main()
{
    List* list = make();
    cout << "Актуальный список" << endl;
    print(list);
    cout << endl;
    del(list, 1);
    cout << "Актуальный список" << endl;
    print(list);
    cout << endl;
    return 0;
}

