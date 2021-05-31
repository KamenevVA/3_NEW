#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node* pNext;
};


class List
{
private:
	Node* pFirst;

public:
	List() : pFirst(NULL) {}

	List& push_front(int);

	int& operator [] (int);

	class Iterator
	{
	protected:
		Node* iter;

	public:
		Iterator(Node* node) : iter(node) {}

		Iterator& operator ++ ();
		Iterator operator ++ (int);

		

		bool operator != (Iterator right);

		bool operator < (Iterator right);

		int& get();
	};

	Iterator start();
	Iterator end();
	Iterator n(int n1);
};


List& List::push_front(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->pNext = pFirst;
	pFirst = temp;
	return *this;
}


int& List::operator [] (int index)
{
	Node* temp = pFirst;
	for (int i = 0; i < index; i++)
	{
		temp = temp->pNext;
	}

	return temp->data;
}


List::Iterator& List::Iterator::operator ++ ()
{
	iter = iter->pNext;
	return *this;
}


List::Iterator List::Iterator::operator ++ (int)
{
	List::Iterator temp(iter);
	iter = iter->pNext;
	return temp;
}


int& List::Iterator::get()
{
	return iter->data;
}


bool List::Iterator::operator != (Iterator right)
{
	return bool(iter != right.iter);
}


List::Iterator List::start()
{
	return List::Iterator(pFirst);
}


List::Iterator List::end()
{
	return List::Iterator(NULL);
}


List::Iterator List::n(int n1)
{
	Node*tmp = pFirst;
	for (int i = 0; i < n1; i++)
	{
		tmp = tmp->pNext;
	}

	cout << tmp->data;
	return 0;
}


bool List::Iterator::operator < (Iterator right)
{
	return bool(iter < right.iter);
}




int main()
{
	setlocale(LC_ALL,"Russian");
	List lost_of;
	int n1;


	lost_of.push_front(87).push_front(10).push_front(25).push_front(46).push_front(101);


	cout << "Односвязный список имеет элементы:" << endl;
	for (List::Iterator iter = lost_of.start(); iter != lost_of.end(); iter++)
	{
		cout << iter.get() << "\t";
	}

	cout << endl << endl;
	
	cout << "Операция доступа по индексу 2" << endl;
	cout << lost_of[2];
	cout << endl << endl;


	cout << "Операция принадлежность числа множеству сотни" << endl;

	cout << "Взяли элемент под номером 0" << endl;
	cout << lost_of[0] << endl << endl;

	if (lost_of[0] < 100)
	{
		cout << "Число входит в множество меньше сотни" << endl;
	}
	else
	{
		cout << "Число не входит в множество меньше сотни" << endl;
	}
	cout << endl << endl;

	cout << "Введите переход к какому элементу сделать" << endl;
	cin >> n1;
	cout << endl;

	while (n1 < 0 || n1>4)
	{
		cout << "Неправильный ввод, введите заного" << endl;
		cin >> n1;
		cout << endl;
	}

	cout << "Мы перешли к элементу  " << n1 << endl;
	List::Iterator iter = lost_of.n(n1);

	cout << endl << endl;


}
