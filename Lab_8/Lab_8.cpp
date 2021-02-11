#include <iostream>
using namespace std;
int n;

struct Buyer
{
	string name; //ФИО
	string adress; //Домашний адресс
	int number; //Номер телефона
	int card_number; //Номер кредитной карты
};


struct List
{
	Buyer data;
	List* next;
  List* prev;
};

List* readFile() 
{
    List* first, * p;
    first = NULL; 

    FILE* fp;
    if ((fp = fopen("data.txt", "rb")) == NULL) {
        perror("\nОшибка при открытии файла data.txt");
        exit(0);
    }
    p = new List;
    if (!feof(fp))
    {
        fread(&p, sizeof(p), 1, fp);
    }
    first = p;
    fclose(fp);
    return first;
}

void saveFile(List* first)
{
    if (first == NULL)
    {
        cout << "Список пуст" << endl;
    }
    else
    {
        List* p = first;

        FILE* fp;
        if ((fp = fopen("data.txt", "wb")) == NULL)
        {
            perror("\nОшибка при открытии файла data.txt");
            exit(0);
        }
        rewind(fp);

        while (!feof(fp) && p != NULL) 
        {   
            fwrite(&p, sizeof(*p), 1, fp);
            p = p->next;
        }
        fclose(fp);
    }
}


void del(List* &first, int count)
{
    if (first == NULL)
    {
        cout << "Список пуст" << endl;
    }
    else
    {
        List* p = first;
        for (int i = 0; i < count; i++)
        {
            List* q = first;
            first = p->next;
            delete q;
            p = first;

        }
    }
}


List* make(int size) 
{
    if (size == 0)
    {
        cout << "Список не может быть создан" << endl;
        return 0;
    }
    List* first, * p;
    first = NULL;
    p = new List;
    cout << "Введите 1-ый элемент: " << endl;
    cout << "ФИО: ";
    cin >> p->data.name;
    cout << "Домашний адрес: ";
    cin >> p->data.adress;
    cout << "Номер телефона: ";
    cin >> p->data.number;
    cout << "Номер кредитной карты: ";
    cin >> p->data.card_number;
    first = p;
    p->next = NULL;
    p->prev = NULL;
    for (int i = 2; i <= size; i++)
    {
        List* h = new List;
        List* q = p;
        p->next = h;
        p = p->next;
        cout << "Введите " << i << "-ый элемент: " << endl;
        cout << "ФИО: ";
        cin >> p->data.name;
        cout << "Домашний адрес: ";
        cin >> p->data.adress;
        cout << "Номер телефона: ";
        cin >> p->data.number;
        cout << "Номер кредитной карты: ";
        cin >> p->data.card_number;
        p->next = NULL;
        p->prev = q;
    }
    return first;
}


void print(List* first)
{
    if (first == NULL)
    {
        cout << "Список пуст." << endl;
    }
    else
    {
        List* p = first;
        while (p != NULL)
        {
            cout<< "ФИО: " << p->data.name << " ";
            cout<< "Адрес: " << p->data.adress << " ";
            cout<< "Номер телефона: " << p->data.number << " ";
            cout<< "Номер карты:  " << p->data.card_number << " ";
            cout << endl;
            p = p->next;
        }
        cout << endl;
    }
}



void add(List* &first, int k)
{
    if (first == NULL)
    {
        cout << "Список пуст" << endl;
        return;
    }
    else
    {
        List* p = first;
        int size = 0;
        while (p->next != NULL)
        {
            p = p->next;
            size++;
        }
        p = first;
        for (int i = 1; i < size; i++) 
        {
            p = p->next;
        }
        for (int i = 1; i <= k; i++)
        {
            List* h = new List;
            List* q = p;
            p->next = h;
            p = p->next;

            cout << "Введите ФИО: ";
            cin >> p->data.name;

            cout << "Введите домашний адрес: ";
            cin >> p->data.adress;

            cout << "Введите номер телефона: ";
            cin >> p->data.number;

            cout << "Введите номер кредитной карты: ";
            cin >> p->data.card_number;

            p->next = NULL;
            p->prev = q;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество элементов: ";
    cin >> n;
    List* list = make(n);
    saveFile(list);
    cout << "Содержание файла: " << endl;
    List* list_file = readFile();
    print(list);
    cout << endl;
    cout << "Список после удаления: " << endl;
    del(list, 3);
    print(list);
    cout << "Добавление элементов в список. " << endl;
    add(list, 3);
    cout << "Список после добавления: " << endl;
    print(list);
    cout << "Файл data.txt обновлён." << endl;
    saveFile(list);
    return 0;
}
