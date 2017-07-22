#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <string>
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
template <class T>
class ListException
{
public:
	ListException<T>(const string& M = "List Error") { msg = M; };
	string what() const { return msg; };
private:
	string msg;
};
#endif // !header.h
