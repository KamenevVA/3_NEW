#pragma once
#include <iostream>
using namespace std;
struct st
{
	int data;
	st* next;
};
class stack
{
private:
	st* top1;
public:
	stack();
	stack(int k);
	~stack();
	void push();
	int top();
	bool empty();
	void pop();
	void print();
};
stack::stack()
{
	top1 = NULL;
}
stack::~stack()
{
	delete[]top1;
}
stack::stack(int k)
{

	top1 = new st;
	int a;
	cout << "Ââåäèòå çíà÷åíèÿ " << endl;
	cin >> a;
	top1->data = a;
	top1->next = NULL;
	for (int i = 1; i < k; i++)
	{
		st* h = new st;
		cin >> a;
		h->data = a;
		h->next = top1;
		top1 = h;
	}
}
void stack::push()
{
	st* h = new st;
	int a;
	cout << "Ââåäèòå çíà÷åíèå " << endl;
	cin >> a;
	h->data = a;
	h->next = top1;
	top1 = h;
}
int stack::top()
{
	return top1->data;
}
bool stack::empty()
{
	return top1 == NULL;
}
void stack::pop()
{
	if (top1 != NULL)
	{
		st* p = top1;
		top1 = top1->next;
		delete p;
	}
}
void stack::print()
{
	st* p = top1;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
