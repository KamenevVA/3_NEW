#include <iostream>
using namespace std;

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
};

List* readFile() 
{
    List* first, * p;
    first = NULL; 

    FILE* fp;
    if ((fp = fopen("data.dat", "rb")) == NULL) {
        perror("\nОшибка при открытии файла data.dat");
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
        if ((fp = fopen("data.dat", "wb")) == NULL)
        {
            perror("\nОшибка при открытии файла data.dat");
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


List* make() {
    List* first, * p;
    first = NULL;

    p = new List;   
 
    p->data.name = "Иванов Иван Петрович";
    p->data.adress = "г.Москва, ул.Ленина, 17.";
    p->data.number = 79993332211;
    p->data.card_number = 1276390011241765;
    p->next = NULL; 

    first = p;

    List* h = new List; 
    p->next = h;
    p = p->next;        
    p->data.name = "Петров Иван Сергеевич";
    p->data.adress = "г.Пермь, ул.Леонова, 25";
    p->data.number = 79998887766;
    p->data.card_number = 1600523114952873;
    p->next = NULL; 
    return first;
}


void print(List* first) {
    if (first == NULL) {
        cout << "Список пуст" << endl;
    }
    else 
    {
        List* p = first;
        while (p != NULL) 
        {
            cout << "ФИО: " << p->data.name << " | ";
            cout << "Домашний адрес: " << p->data.adress << " | ";
            cout << "Номер телефона: " << p->data.number << " | ";
            cout << "Номер кредитной карты: " << p->data.card_number << endl;
            p = p->next;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List* list = make();
    cout << "Сформирован файл data.dat" << endl;
    saveFile(list);
    
    cout << "Содержание файла" << endl;
    List* list_file = readFile();
    print(list_file);
    cout << endl;
    
    
    return 0;
}
