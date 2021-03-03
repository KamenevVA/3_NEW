#include <iostream>

using namespace std;

char a;

struct stack{
char data;
stack* prev;
};

stack* make_stack(int n)
{
if (n==0)
{
return NULL;
}
stack* top, *p;
top = NULL;
p = new stack;
cout << "Введите 1-ый элемент: ";
cin >> a;
p->data = a;
p->prev=NULL;
top = p;
for (int i = 2; i <= n; i++)
{
stack *h = new stack;
cout << "Введите " << i << "-ый элемент: ";
cin >> a;
h->data = a;
h->prev = top;
top = h;
}
return top;
}

void print(stack*top)
{
if (top==NULL)
{
cout << "Стек пуст" << endl;
}
else {
stack* p = top;
while(p != NULL)
{
cout << p->data << " ";
p = p->prev;
}
cout << endl;
}
}

void add(stack* &first, int n)
{
stack* p = first;
stack* h = new stack;
cout << "Введите элемент для добавления: ";
cin >> h->data;
h->prev=p;
first=h;
while(p->prev!=NULL){
stack* h = new stack;
cout << "Введите элемент для добавления: ";
cin >> h->data;
h->prev = p->prev;
p->prev = h;
if(p->prev->prev!=NULL)
{
p=p->prev->prev;
}
else {
p=p->prev;
}
}
}

int main()
{
setlocale(LC_ALL, "Rus");
cout<< "Введите кол-во элементов в стеке: ";
int n;
cin >> n;
cout << "Введите элементы стека. " << endl;
stack* st = make_stack(n);
cout << "Стек: ";
print(st);
add(st, n);
cout << "Стек после добавления элементов: ";
print(st);
return 0;
} 
