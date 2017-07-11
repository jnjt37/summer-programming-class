/*
Name: Jaxson Johnston
Assignment: Project 5
*/
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include "MenuItems.h"

using namespace std;

int main()
{
	srand(time(NULL));
	int pizzas = 0, sandwiches = 0, counter = 0, discountsGiven = 0, orderNum = 0;
	float totalSales = 0, discount = 0, netSales = 0, orderPrice = 0;
	int luckyCustomer;
	char itemType;
	MenuItem *itemList[100];
	for (int i = 0; i < 100; i++)
		itemList[i] = nullptr;
	ifstream orders;
	ofstream orderCopy;
	orders.open("program5data.txt");
	//orderCopy.open("orders.txt");
	luckyCustomer = rand() % 20;
	while (!orders.eof())
	{
		orders.ignore();
		orders >> itemType;
		if (itemType == 'P')
		{	
			itemList[orderNum] = new Pizza();
			itemList[orderNum]->readData(orders);
			itemList[orderNum]->setPrice();
			orderPrice = itemList[orderNum]->getPrice();
			pizzas++;
		}
		if (itemType == 'S')
		{
			itemList[orderNum] = new Sandwich();
			itemList[orderNum]->readData(orders);
			itemList[orderNum]->setPrice();
			orderPrice = itemList[orderNum]->getPrice();
			sandwiches++;
		}
		orderNum++;
		counter++;
		if (counter > 19)
		{
			counter = 0;
			luckyCustomer = rand() % 20;
		}
	}
	//orderCopy.close();
	orders.close();
	cout << "Pizzas sold: " << pizzas << endl;
	cout << "Sandwiches sold: " << sandwiches << endl;
	cout << "Total sales: $" << fixed << setprecision(2) << totalSales << endl;
	cout << "Number of discounts given" << discountsGiven << endl;
	cout << "Discount amount: $" << fixed << setprecision(2) << discount << endl;
	netSales = totalSales - discount;
	cout << "Net sales: $" << fixed << setprecision(2) << netSales << endl;
/*	
	for (int k = 0; k < 100; k++)
	{
		if (itemList[k]->WhatAmI(itemType) == "Pizza")
			itemList[k]->writeData(orderCopy);
	}
	for (int k = 0; k < 100; k++)
	{
		if (itemList[k]->WhatAmI(itemType) == "Sandwich")
			itemList[k]->writeData(orderCopy);
	}
*/	
	system("pause");
	return 0;
}
void Pizza::setPrice()
{
	switch (size)
	{
	case 's': price = 7; break;
	case 'm': price = 8; break;
	case 'l': price = 10; break;
	case 'f': price = 12; break;
	}
	if (crust == 's')
		price += 1;
}
void Pizza::readData(istream& orderDetails)
{
	string tempName, tempDesc;
	int tooManyMods = 0;
	getline(orderDetails, tempName);
	getline(orderDetails, tempDesc);
	orderDetails >> size;
	orderDetails >> crust;
	getline(orderDetails, modification);
	while (modification != "*" && tooManyMods <= 5)
	{
		getline(orderDetails, modification);
		tooManyMods++;
	}
	return;
}
void Pizza::writeData(ostream& orderWrite)
{
	string tempName, tempDesc;
	int tooManyMods = 0;
	orderWrite << tempName;
	orderWrite << tempDesc;
	orderWrite << size;
	orderWrite << crust;
	orderWrite << modification;
	while (modification != "*" && tooManyMods <= 5)
	{
		
	}
	return;
}
void Sandwich::setPrice()
{
	price = 8;
}
void Sandwich::readData(istream& orderDetails)
{
	string tempName, tempDesc;
	getline(orderDetails, tempName);
	getline(orderDetails, tempDesc);
	getline(orderDetails, side);
	return;
}
void Sandwich::writeData(ostream& orderwrite)
{
	cout << getName() << "\n" << getDescription() << "\n" << side << endl;
	return;
}