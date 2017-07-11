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
	int pizzas = 0, sandwiches = 0, counter = 0, discountsGiven = 0;
	float totalSales = 0, discount = 0, netSales = 0, orderPrice = 0;
	int luckyCustomer;
	char itemType;
	MenuItem *itemList[100];
	for (int i = 0; i < 100; i++)
		item_list[i] = nullptr;
	ifstream orders;
	orders.open("program5data.txt");
	luckyCustomer = rand() % 20;
	while (orders >> itemType)
	{
		orders.ignore();
		if (itemType == 'P')
		{
			Pizza pizza;
			pizza.readData(orders);
			orderPrice = pizza.getPrice();
			totalSales += orderPrice;
			if (luckyCustomer == counter)
			{
				discount += orderPrice*0.2;
				discountsGiven++;
			}
			pizzas++;
		}
		if (itemType == 'S')
		{
			Sandwich sandwich;
			sandwich.readData(orders);
			orderPrice = sandwich.getPrice();
			totalSales += orderPrice;
			if (luckyCustomer == counter)
			{
				discount += orderPrice*0.2;
				discountsGiven++;
			}
			sandwiches++;
		}
		counter++;
		if (counter > 19)
		{
			counter = 0;
			luckyCustomer = rand() % 20;
		}
	}
	orders.close();
	cout << "Pizzas sold: " << pizzas << endl;
	cout << "Sandwiches sold: " << sandwiches << endl;
	cout << "Total sales: $" << fixed << setprecision(2) << totalSales << endl;
	cout << "Number of discounts given" << discountsGiven << endl;
	cout << "Discount amount: $" << fixed << setprecision(2) << discount << endl;
	netSales = totalSales - discount;
	cout << "Net sales: $" << fixed << setprecision(2) << netSales << endl;
	system("pause");
	return 0;
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
		getline(orderWrite, modification);
		tooManyMods++;
	}
	return;
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