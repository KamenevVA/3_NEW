#include<iostream>
#include<time.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

int** Create(int row, int col)
{
    int** arr;
    arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    return arr;
}

void Fill(int** arr, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}



void Del(int** arr, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}

int** Add_Row(int** arr, int& height, int width)
{
    int** arr_2;
    int pos;
    cout << "Введите номер строки, которуб надо добавить" << endl;
    cin >> pos;
    if (pos > height)
    {
        cout << "Недопустимое значение\n";
        return 0;
    }
    else
    {
        arr_2 = Create(height + 1, width);
        for (int i = 0; i < pos; i++)
        {
            for (int j = 0; j < width; j++)
            {
                arr_2[i][j] = arr[i][j];
            }
        }
        for (int i = 0; i < height - pos; i++)
        {
            for (int j = 0; j < width; j++)
            {
                arr_2[i + pos + 1][j] = arr[i + pos][j];
            }
        }
        height++;
        for (int i = pos; i < pos + 1; i++)
        {
            for (int j = 0; j < width; j++)
            {
                arr_2[i][j] = rand() % 100;
            }
        }
        Del(arr, height - 1);
        arr = arr_2;
        return arr;
    }
}
    int width, height;
    int choice;
    int pos;

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите количество строк\n"; cin >> width;
    cout << "Введите количество столбцов\n"; cin >> height;
    int** arr;
    arr = Create(height, width);
    Fill(arr, height, width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
            arr = Add_Row(arr, height, width);
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    cout  << arr[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            Del(arr, height);
}
