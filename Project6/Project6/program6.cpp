#include <iostream>
#include "header.h"
using namespace std;

int main()
{
	ListNode input;
	List test[4];
	ifstream fin;
	fin.open("Program6Input.txt");
	fin >> input.data;
	if (input.data % 2 == 0)
	{
		if(input.data<100)
			test[0]
		else
			test[2]
	}
	else
	{
		if (input.data<100)
			test[1]
		else
			test[3]
	}
	fin.close();
	return 0;
}
template <class T>
ListNode<T>::ListNode(const T& item)
{
	data = item;
	next = prev = nullptr;
}
template <class T>
List<T>::List()
{
	front = back = nullptr;
	count = 0;
}
template <class T>
List<T>::List(const List<T>& other)
{
	front = back = nullptr;
	count = 0;
	*this = other;
}
template <class T>
const List<T>& List<T>::operator=(const List<T>& rhs)
{

}
template <class T>
List<T>::~List()
{
	clear();
}
template <class T>
void List<T>::clear()
{
	ListNode<T> *temp = front;

}
template <class T>
void List<T>::traverse(ostream& out)
{

	ListNode<T> *P = front;
	while (P != nullptr)
	{
		out << P->data << ' ';
		P = P->next;
	}
	out << '\n';
}
template <class T>
void List<T>::push_front(const T& item)
{
	ListNode<T> *P;
	if (is_empty())
	{

	}
	else
	{

	}
}
template <class T>
void List<T>::push_back(const T& item)
{

}
template <class T>
void List<T>::push_ordered(const T& item)
{

}
template <class T>
T List<T>::pop_front()
{

}
template <class T>
T List<T>::pop_back()
{

}
template <class T>
int List<T>::size()
{

}
template <class T>
void List<T>::sort()
{

}