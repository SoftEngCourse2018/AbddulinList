/* Задача:

Автор:
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <locale.h>
#include <ctime>
using namespace std;

struct list
{
	int info;
	list * pred, *next;
};


void CreatNulList(list *&head, list *&tail)
{
	head = new list;
	tail = new list;

	head->next = tail;
	tail->pred = head;
}


void CreateRandomlist(list *&head, list *&tail, int n = 10)
{
	head = new list;
	tail = new list;

	head->next = tail;
	tail->pred = head;
	list *last = head;
	for (int i = 0; i < n; i++)
	{
		list *p = new list;

		p->pred = last;
		p->next = last->next;
		last->next = p;
		p->next->pred = p;

		last = p;
		p->info = rand() % 20;

	}
	return;
}


list *RemoveElement(list *&p)
{
	if (p)
	{
		list *p1 = p->pred;
		list *p2 = p->next;

		p1->next = p2;
		p2->pred = p1;
		p->pred = NULL;
		p->next = NULL;
		return p2;
	}
	else
		return NULL;
}


void Insert(list * head, list * tail, list * p)
{
	if (p)
	{
		p->next = tail;
		p->pred = tail->pred;
		tail->pred = p;
		p->pred->next = p;
	}
	else
		cout << "Error!" << endl;
}


void PrintList(list* head, list* tail)
{
	if (head && tail)
	{
		list * p = head->next;
		while (p != tail)
		{
			cout << setw(4) << p->info;
			p = p->next;
		}
	}
	return;
}

void DeleteMin(list* &head, list* &tail)
{
	if (head && tail)
	{
		list * p = head->next;
		int min = 21;
		while (p != tail)
		{
			if (p->info < min)
			{
				min = p->info;
			}

			p = p->next;
		}

		list * k = head->next;
		while (k != tail)
		{
			if (k->info == min)
			{
				k = RemoveElement(k);
			}
			else
			{
				k = k->next;
			}
		}
	}
}


void main()
{
	setlocale(LC_ALL, "Russian");
	list* head, *tail;
	srand(time(NULL));


	CreateRandomlist(head, tail);
	cout << "Список : " << endl;
	PrintList(head, tail);
	cout << endl;


	DeleteMin(head, tail);
	cout << "Список после удаления минимального элемента: " << endl;
	PrintList(head, tail);
	cout << endl;

	system("pause");
}
