#include <iostream>

using namespace std;

char a;

struct qu{
int data;
qu* next;
};

qu* make_qu(int n, qu*& first, qu*& last)
{
if (n == 0) return NULL;
qu* p = new qu;
int a;
cout << "Введите элемет очереди: ";
cin >> a;
p->data =a;
p->next = NULL;
first = p;
last = p;
for (int i = 2; i <=n; i++)
{
qu* h = new qu;
cout << "Введите элемет очереди: ";
cin>>a;
h->data=a;
h->next = p;
last = h;
p = last;
}
return first;
}

qu* push(int n, qu*& last)
{
qu* p= new qu;
p->data=n;
p->next = last;
last = p;
return last;
}

void print(qu*last)
{
qu* p = last;
while(p!=NULL)
{
cout << p->data « " ";
p = p->next;
}
cout << endl;
}




int pop(qu*& first, qu*& last)
{
qu* p =last;
int k = 0;
while(p != NULL)
{
k++;
p = p->next;
}
p = last;
if (k==1)
{
int t = last->data;
delete p;
last = NULL;
first = NULL;
return t;
}
else{
while (p->next->next != NULL)
{
p = p->next;
}
qu* t = p;
int e = p->next->data;
p = p->next;
t->next = NULL;
first = t;
delete p;
return e;
}
}
int main()
{
setlocale(LC_ALL, "Rus");
cout<<"Введите кол-во элементов в стеке: ";
int n;
int k;
cin >> n;
qu* first, * last;
make_qu(n,first,last);
print(last);
int *mas = new int[n];

for(int i = 0; i < n; i++)
{
int t = pop (first, last);
mas[i]=t;
if (t % 2 == 0)
{
k=t;
}
}


for(int i = 0; i < n; i++)
{
if (mas[i]!=k)
{
push(mas[i], last);
}
}


cout << "Очередь после удаления: ";
print(last);
return 0;
}
