#ifndef _HT_H_
#define _HT_H_

#include "node.h"
#include "LinkedList.h"

template <class KEY, class DATA>
class Table
{
protected:
	int size; //общий размер
	int count;//текущее число записей
	LinkedList<Node<KEY,DATA>>* mas; // данные
	int Hash(KEY K);//функция выщитывающая индекс(хэшфункция)
public:
Table(int size_ = 1); // конструктор принимаем разме рмассива
Table(Table& ht);//Копирование 
~Table();//деструктор
DATA& operator[](KEY k_);//оператор доступа
Table& operator=(Table& ht);//оператор присваения
void Add(DATA val_,KEY k_);//добавить элемент в таблицу
void Del(KEY k_);//удаление по ключу
void resize(int newSize);//ресайз
};

template <class KEY, class DATA>
Table<KEY, DATA>::Table(int size_)
{
	size = size_;
	count = 0;
	mas = new LinkedList<Node<KEY,DATA>>[size];//выделяем память под список типа Node<key,data>
}

template <class KEY, class DATA>
Table<KEY, DATA>::Table(Table& ht)
{
	size=ht.size;
	count=ht.count;

	mas=new LinkedList<Node<KEY,DATA>>[ht.size];
	for(int i=0; i<ht.size;++i)
		mas[i]=ht.mas[i];
}

template <class KEY, class DATA>
Table<KEY, DATA>::~Table()
{
	delete[] mas;
	size=0;
	count=0;
}

template <class KEY, class DATA>
int Table<KEY, DATA>:: Hash(KEY K)
{
	return ((int)K)% size;

}
template <class KEY, class DATA>
DATA& Table<KEY, DATA>::operator[](KEY K)
{
	int index=Hash(K);
	Node<KEY, DATA> nod;//создали временную ноду
	nod.SetKey(K);//установили ключ
	if (!mas[index].contains(nod))//ищем существует ли в списке этот узел
		throw 5;

	return mas[index].get(mas[index].indexOf(nod)).GetData();
}

template<class KEY, class DATA>
Table<KEY,DATA> & Table<KEY, DATA>::operator=(Table & ht)
{
	size = ht.size;
	count = ht.count;
	p = ht.p;
	mas = new Node[ht.size];
	for (int i = 0; i<ht.size; ++i)
		mas[i] = ht.mas[i];
}

template <class KEY, class DATA>
void Table<KEY, DATA>::Add(DATA val_, KEY k_)
{
	int index=Hash(k_);//получаем индекс

	Node<KEY, DATA> nod;//создаём временную ноду
	nod.SetKey(k_);
	nod.SetVal(val_);
	if (!mas[index].contains(nod))//если нода ещё нет в списке
	{
		mas[index].add(nod);//добавляем в список
	}
	else//если есть
	{
		Node<KEY, DATA>* tmp = &mas[index].get(mas[index].indexOf(nod));//получаем прямой доступ к ноде
		tmp->SetVal(val_);//меняем значение
	}
}

template<class KEY, class DATA>
void Table<KEY, DATA>::Del(KEY k_)//удаление по ключу
{
	int index = Hash(k_);//получаем индекс

	Node<KEY, DATA> nod;//создаём временную ноду
	nod.SetKey(k_);
	if (mas[index].contains(nod))//если в списке по этому индексу существует нода
	{
		mas[index].remove(mas[index].indexOf(nod));//удалём её из списка
	}
}

template<class KEY, class DATA>
void Table<KEY, DATA>::resize(int newSize)//ресайз
{
	LinkedList<Node<KEY, DATA>>*tmp = mas;//делаем 2 указателя на один и тот же массив
	if (count > newSize)//проверяем что новый размер меньше количества элементов
		throw 112;
	mas = new LinkedList<Node<KEY, DATA>>[newSize];//меняем основной указатель класса на новый участок памяти
	count = 0;//обозначаем что в новом участке нет элементов
	int oldSize = size;//запоминаем старый размер что бы пройти по стараму массиву
	size = newSize;//устанавливаем новый участок памяти
	for (int i = 0; i < oldSize; i++)//проходим по стараму массиву
	{
		for(size_t x=0;x<tmp[i].size();x++)//и по списку в массиве
			Add(tmp[i].get(x).GetData(), tmp[i].get(x).GetKey());//добавляем каждый элемент через уже готовый метод Add
	}
	delete[] tmp;//удаляем старую память
}

#endif