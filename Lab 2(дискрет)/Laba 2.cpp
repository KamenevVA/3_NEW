#include <iostream>

using namespace std;

int** Create(int size1)
{
    int** arr;
    arr = new int* [size1];
    for (int i = 0; i < size1; i++)
    {
        arr[i] = new int[size1];
    }
    return arr;
}

void Fill(int** arr, int size1)
{
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            cout << "Введите элемент [" << i << "][" << j << "] ";
            cin >> arr[i][j];
        }
    }
}

int siz;
int k = 0;
bool trans = true;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите размерность матрицы\n"; cin >> siz;
    int** arr;
    arr = Create(siz);
    Fill(arr, siz);
    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            if (i == j) {
                if (arr[i][j] == 1) {
                    k++;
                }
            }
        }
    }
    if (k == siz) {
        cout << "Рефлективность - да" << endl;
        cout << "Анти-рефлективность - нет" << endl;
    }
    else {
        cout << "Рефлективность - нет" << endl;
    }

    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            if (i == j) {
                if (arr[i][j] == 0) {
                    k++;
                }
            }
        }
    }
    if (k == siz) {
        cout << "Анти-рефлективность - да" << endl;
    }



    bool check_sim = true; //служит для проверки симметричности матрицы
    for (int i = 0; i < siz; ++i) {
        for (int j = 0; j < siz; ++j) {
            if (arr[i][j] != arr[j][i]) {
                check_sim = false;
            }
        }
    }
    if (!check_sim) {
        cout << "Симметричность - нет\n";
    }
    else if (check_sim) {
        cout << "Симметричность - да\n";

    }

    bool check_asim = true; //служит для проверки асимметричности матрицы
    for (int i = 0; i < siz; ++i) {
        for (int j = 0; j < siz; ++j) {
            if (((arr[i][j] * arr[j][i]) != 0) && (i!=j)) {
                check_asim = false;
            }
        }
    }
    if (!check_asim) {
        cout << "Асимметричность - нет\n";
    }
    else if (check_asim) {
        cout << "Асимметричность - да\n";
    }
    bool anti_sem = true;
    for (int i = 0; i < siz; ++i) {
        for (int j = 0; j < siz; ++j) {
                if (((arr[i][j] == 1) && (arr[j][i] == 1)) && (i!=j)) {
                    anti_sem =
                        false;
                }
        }
    }
    if (anti_sem) {
        cout << "Антиcимметричность - да\n";
    }
    else if (!anti_sem){
        cout << "Антисимметричность - нет\n";
    }


    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) {
            for (int k = 0; k < siz; k++)
            {
                if ((i != j && j != k) && !(arr[i][j] == 1 && arr[j][k] == 1 && arr[k][i] == 1))
                    trans = false;
            }
        }
    }

    if (trans) {
        cout << "Транзитивность - да\n";
    }
    else if (!trans) {
        cout << "Транзитивность - нет\n";
    }

    cout << "\n";

    return 0;
}