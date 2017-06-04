#ifndef _NODE_H_
#define _NODE_H_

template <class KEY, class DATA>
class Node
{
protected:
	KEY k;//ключ(то по чему мы получаем доступ)
	DATA val;//значение, то что храним
public:
	KEY GetKey();//получаем ключ
	DATA& GetData();//получаем значение
	void SetKey(KEY k_);//устанавливаем ключ
	void SetVal(DATA val_);//устанавливаем значение
	bool operator==(Node<KEY, DATA>&);//для поиска в листе нужен оператор сравнивания
	bool operator!=(Node<KEY, DATA>&);//тоже самое
	Node<KEY, DATA> operator=(Node<KEY, DATA>& r);//для копирование узлов(node)
};

template <class KEY, class DATA>
KEY Node<KEY, DATA>::GetKey()
{
	return k;
}
template <class KEY, class DATA>
DATA& Node<KEY, DATA>::GetData()
{
	return val;
}
template <class KEY, class DATA>
void Node<KEY, DATA>::SetKey(KEY k_)
{
	k = k_;
}
template <class KEY, class DATA>
void Node<KEY, DATA>::SetVal(DATA val_)
{
	val = val_;
}

template<class KEY, class DATA>
bool Node<KEY, DATA>::operator==(Node<KEY, DATA> &r)//если ключи равны то это один и тот же объект
{
	return k == r.k;
}

template<class KEY, class DATA>
bool Node<KEY, DATA>::operator!=(Node<KEY, DATA> &r)
{
	return k != r.k;
}

template<class KEY, class DATA>
Node<KEY, DATA> Node<KEY, DATA>::operator=(Node<KEY, DATA>& r)//копируем данные
{
	k = r.k;
	val = r.val;
	return *this;
}

#endif //_NODE_H_