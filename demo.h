/* Задача:
	Это ознакоминетльная версия программы, чтобы получить полную версию купить ее)))
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

//создает пустой список
void CreatNulList(list *&head, list *&tail)
{

}

//Функция формирует список из N целых элементов со сторожами head и tail
void CreateRandomlist(list *&head, list *&tail, int n = 10)
{

}

/*
Функция исключает элмент Р из списка
возвращает указатель на следующий элемент после Р
*/
list *RemoveElement(list *&p)
{

}

//функция вставляет новый элемент p в список
void Insert(list * head, list * tail, list * p)
{

}


//Функуция выводит двусвязанный список на экран
void PrintList(list* head, list* tail)
{

}

//Функция удаляеь минимальный элемент в списке
void DeleteMin(list* &head, list* &tail)
{

}


void main()
{
	setlocale(LC_ALL, "Russian");  //Устанавливаем русскую кодировку
	list* head, *tail;
	srand(time(NULL));  //Включение генератора случайных чисел

	//Создаем и выводим на экран список L
	CreateRandomlist(head, tail);
	cout << "Список : " << endl;
	PrintList(head, tail);
	cout << endl;

	//Удаление минимального элемента и вывод списка на экран
	DeleteMin(head, tail);
	cout << "Список после удаления минимального элемента: " << endl;
	PrintList(head, tail);
	cout << endl;

	system("pause");
}
