/*
Name: Jaxson Johnston
Assignment: Final Project
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "time.h"
#include "header.h"

using namespace std;

int main()
{
	srand(time(NULL));
	int tick = 0;
	int num_customers = 0;
	int customer_counter = 0;
	int most_customers_in_line = 0;
	int longest_wait_time = 0;
	bool end_customer_list = false;
	Register lanes[6];
	List<Customer> arrivals[500];
	List<Customer> departures[500];
	Customer temp;

	ifstream fin;
	fin.open("steadystate.txt");
	while (!fin.eof())
	{
		cin >> temp.time_arrived;
		cin >> temp.items;
		temp.payment_time = rand() % 4;
		arrivals[num_customers].push_back(temp);
		num_customers++;
	}
	fin.close();
	while(end_customer_list == false)
	{
		for (int i = 0; i < num_customers; i++)
		{
			temp = arrivals[i];
			if (temp.time_arrived == tick)
			{
				if (temp.items <= 10 && lanes[0].customers_in_line <= 5)
				{
					lanes[0].lines.push_front(temp);
					lanes[0].busy = true;
					lanes[0].customers_in_line++;
					if (lanes[0].customers_in_line > most_customers_in_line)
						most_customers_in_line++;
				}
				else
				{
					for (int j = 1; j < 6; j++)
					{
						if (lanes[j].busy == false)
						{
							lanes[j].lines.push_front(temp);
							lanes[j].busy = true;
							lanes[j].customers_in_line++;
							if (lanes[j].customers_in_line > most_customers_in_line)
								most_customers_in_line++;
						}
					}
					for (int j = 2; j < 6; j++)
					{
						if (lanes[j].customers_in_line > lanes[j - 1].customers_in_line)
						{
							lanes[j - 1].lines.push_back(temp);
							lanes[j - 1].customers_in_line++;
							if (lanes[j - 1].customers_in_line > most_customers_in_line)
								most_customers_in_line++;
						}
					}
				}
			}
			customer_counter++;
		}
		for (int i = 0; i < 6; i++)
		{
			if (lanes[i].busy == true)
			{
				temp.total_time = temp.total_time - 3;
				if (temp.total_time <= 0)
					lanes[i].lines.pop_front();
			}
		}
		tick++;
		if (customer_counter == num_customers - 1)
			end_customer_list = true;
	}
	cout << "Steady State Condition:" << endl;
	cout << "Number of customers served: " << num_customers << endl;
	cout << "Longest line length: " << most_customers_in_line << endl;
	cout << "Average lenth of time spent in line: " << endl;
	cout << "Maximum length of time spent in line: " << endl;
	cout << "Total time registers were idle: " << endl;
	tick = 0;
	end_customer_list = false;
	num_customers = 0;
	customer_counter = 0;
	
	ifstream fin;
	fin.open("bigtickets.txt");
	while (!fin.eof())
	{
		cin >> temp.time_arrived;
		cin >> temp.items;
		temp.payment_time = rand() % 4;
		arrivals[num_customers].push_back(temp);
		num_customers++;
	}
	fin.close();
	cout << "Big Tickets Condition:" << endl;
	cout << "Number of customers served: " << num_customers << endl;
	cout << "Longest line length: " << most_customers_in_line << endl;
	cout << "Average lenth of time spent in line: " << endl;
	cout << "Maximum length of time spent in line: " << endl;
	cout << "Total time registers were idle: " << endl;
	
	
	ifstream fin;
	fin.open("bigcrunch.txt");
	while (!fin.eof())
	{
		cin >> temp.time_arrived;
		cin >> temp.items;
		temp.payment_time = rand() % 4;
		arrivals[num_customers].push_back(temp);
		num_customers++;
	}
	fin.close();
	cout << "Big Crunch Condition:" << endl;
	cout << "Number of customers served: " << num_customers << endl;
	cout << "Longest line length: " << most_customers_in_line << endl;
	cout << "Average lenth of time spent in line: " << endl;
	cout << "Maximum length of time spent in line: " << endl;
	cout << "Total time registers were idle: " << endl;

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
	ListNode<T> *P = new ListNode<T>();
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
	if (back == nullptr)//checks for empty list case
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
	if (size() == 0 || (front == nullptr&&back == nullptr))
		return true;
	else
		return false;
}