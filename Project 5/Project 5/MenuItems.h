#pragma once
#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>
using namespace std;
class MenuItem
{
public:
	MenuItem() : name(""), description(""), price(0) {};
	~MenuItem() {};
	string getName() { return name; };
	string getDescription() { return description; };
	float getPrice() { return price; };
	void setName(string s) { name = s; };
	void setDescription(string d) { description = d; };
	virtual void readData(istream& orderDetails) = 0;
	virtual void writeData(ostream& orderWrite) = 0;
	virtual string WhatAmI(char t) = 0;
private:
	string name;
	string description;
	float price;
};
class Pizza : public MenuItem
{
public:
	Pizza() : size('s'), crust('t'), modification(""), MenuItem() {};
	~Pizza() {};
	void readData(istream& orderDetails);
	void writeData(ostream& orderWrite);
	string Pizza::WhatAmI(char t) { return "Pizza"; };
private:
	char size;
	char crust;
	string modification;
};
class Sandwich : public MenuItem
{
public:
	Sandwich() : side(""), MenuItem() {};
	~Sandwich() {};
	void readData(istream& orderDetails);
	void writeData(ostream& orderWrite);
	string Sandwich::WhatAmI(char t) { return "Sandwich"; };
private:
	string side;
};

#endif // !MENUITEM_H