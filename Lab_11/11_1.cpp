#include <iostream>

using namespace std;

struct lab
{
	int num;
	char data;
	lab* next;
};

void vvod(int size, lab** head)
{
	if (size > 0) {
		(*head) = new lab;
		cout << "Введите элемент списка: ";
		cin >> (*head)->data;
		(*head)->next = NULL;
		vvod(size - 1, &((*head)->next));
	}
}

void dob(lab* head)
{
	lab* p = head;
	lab* n = new lab;
	while (p != 0)
	{
		if (p->num % 2 != 0) {
			lab* o = new lab;
			n = p->next;
			p->next = o;
			p = p->next;
			cout << "Введите новый элемент: ";
			cin >> p->data;
			p->next = n;
		}
		p = p->next;
	}
}

void print(lab* head)
{
	if (head == NULL)
	{
		cout << "Список пуст.";
		cout << endl;
	}
	else {
		lab* p = head;
		while (p != 0)
		{
			cout << p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	cout << "Введите кол-во элементов списка: ";
	cin >> size;
	lab* head;

	vvod(size, &head);
	print(head);
	cout << endl;

	dob(head);
	print(head);
	cout << endl;

	return(0);
}
