#pragma once
#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<fstream>
using namespace std;

template <class T>
class List;

template <class T>
class ListNode
{
	friend class List <T>;
private:
	T data;
	ListNode<T> *next, *prev;
public:
	ListNode() { next = prev = nullptr; };
	ListNode(const T& item);
};

template <class T>
class List
{
private:
	ListNode<T> *front, *back;
	int count;
public:
	List();
	List(const List<T>& other);
	~List();
	const List<T>& operator = (const List<T>& rhs);
	void push_front(const T& item);
	void push_back(const T& item);
	void push_ordered(const T& item);
	T pop_front();
	T pop_back();
	void clear();
	int size();
	bool is_empty();
	void traverse(ostream& out) const;
};
struct Customer
{
	int items=0;
	int time_arrived=0;
	int time_checkout_started=0;
	int time_completed=0;
	int payment_time=0;
	int total_time=items+payment_time;
};
struct Register
{
	List<Customer> lines;
	bool busy = false;
	Customer checking_out;
	int customers_in_line = 0;
};
#endif // !HEADER_H
