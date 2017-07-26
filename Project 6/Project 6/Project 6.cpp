/*
Name: Jaxson Johnston
Assignment: Project 6
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;

int main()
{
	int tempNum;
	List<int> lists[4];
	ifstream fin;
	fin.open("Program6Input.txt");
	while (!fin.eof())
	{
		fin >> tempNum;
		if (tempNum % 2 == 0)
		{
			if (tempNum < 100)
				lists[0].push_back(tempNum);
			else
				lists[2].push_ordered(tempNum);
		}
		else
		{
			if (tempNum < 100)
			{
				if (lists[1].size() >= 25)
					lists[1].pop_front();
				lists[1].push_back(tempNum);
			}
			else
			{
				if (lists[3].size() >= 25)
					lists[3].clear();
				lists[3].push_ordered(tempNum);
			}
		}
	}
	fin.close();
	for (int i = 0; i < 4; i++)
	{
		cout << "List ["<<i<<"]:" << endl;
		lists[i].traverse(cout);
	}
	system("pause");
	return 0;
}
//ListNode copy constructor
template <class T>
ListNode<T>::ListNode(const T& item)
{
	data = item;
	next = prev = nullptr;
}
//List default constructor
template <class T>
List<T>::List()
{
	front = back = nullptr;
	count = 0;
}
//List copy constructor
template <class T>
List<T>::List(const List<T>& other)
{
	front = back = nullptr;
	count = 0;
	*this = other;
}
//overloaded = operator
template <class T>
const List<T>& List<T>::operator=(const List<T>& rhs)
{
	ListNode<T> *temp = rhs.front;
	this->clear();
	while (temp != nullptr)
	{
		this->push_back(temp->data);// copies the item in list
		temp = temp->next;//moves through list
	}
	return *this;
}
//List destructor
template <class T>
List<T>::~List()
{
	clear();
}
template <class T>
void List<T>::clear()
{
	ListNode<T> *temp = new ListNode<T>();
	while (is_empty() != true)
	{
		temp = front->next;//looks at next item
		delete front;//deletes first item
		front = temp;//makes next item the first
		if (front->next == nullptr)
			break;//leaves the loop once there are no more items
	}
	count = 0;
	return;
}
//outputs the contents of the list
template <class T>
void List<T>::traverse(ostream& out) const
{
	ListNode<T> *P = front;
	while (P != nullptr)
	{
		out << P->data << " ";
		P = P->next;
	}
	out << "\n";
}
template <class T>
void List<T>::push_front(const T& item)
{
	ListNode<T> *P= new ListNode<T>();
	P->data = item;
	if (is_empty())//checks for empty list case
	{
		front = P;
		back = P;
	}
	else//assigns the new node to the front
	{
		P->next = front;
		front->prev = P;
		front = P;
	}
	count++;
}
template <class T>
void List<T>::push_back(const T& item)
{
	ListNode<T> *P = new ListNode<T>();
	P->data = item;
	if (back==nullptr)//checks for empty list case
	{
		back = P;
		front = P;
	}
	else//assigns the new node to the front
	{
		P->prev = back;
		back->next = P;
		back = P;
	}
	count++;
}
template <class T>
void List<T>::push_ordered(const T& item)
{
	ListNode<T> *P = new ListNode<T>();
	P->data = item;
	ListNode<T> *current = front;
	if (!front || item <= front->data)//checks if the list is empty or if the item is the smallest value for the list
	{
		push_front(item);
		return;
	}
	for (int i = 0; i < count; i++)//moves through the list
	{
		if (current == back)//case for item being the largest in the list
		{
			push_back(item);
			return;
		}
		if (current->next->data >= P->data)//case for any other point in the list
		{
			P->next = current->next;
			P->prev = current;
			current->next->prev = P;
			current->next = P;
			break;
		}
		current = current->next;
	}
	count++;
}
template <class T>
T List<T>::pop_front()
{
	if (front == nullptr)//checks for empty list
	{
		throw ListException<T>("Empty List");
	}
	else if (size() == 1)//deals with the case where there is only one item
	{
		clear();
	}
	else//every other case
	{
		ListNode<T> *temp = front->next;
		delete front;
		front = temp;
	}
	count--;
	return front->data;
}
//removes the back item
template <class T>
T List<T>::pop_back()
{
	ListNode<T> *temp = back->prev;
	delete back;
	back = temp;
	count--;
	return back->data;
}
//returns count
template <class T>
int List<T>::size()
{
	return count;
}
//checks the count and if the list is empty
template <class T>
bool List<T>::is_empty()
{
	if (size() == 0||(front==nullptr&&back==nullptr))
		return true;
	else
		return false;
}