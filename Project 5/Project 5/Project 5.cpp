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
	float totalSales = 0, discount = 0, netSales = 0, orderPrice = 0, totalDiscounts = 0;
	int luckyCustomer;
	char itemType;
	MenuItem *itemList[100];
	for (int i = 0; i < 100; i++)
		itemList[i] = nullptr;
	ifstream orders;
	ofstream orderCopy;
	orders.open("program5data.txt");
	
	luckyCustomer = rand() % 20;
	while (orders>>itemType)
	{
		orders.ignore();
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
		totalSales += orderPrice;
		if (counter == luckyCustomer)
		{
			discountsGiven++;
			discount = orderPrice*.2;
			totalDiscounts += discount;
		}
		orderNum++;
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
	cout << "Number of discounts given: " << discountsGiven << endl;
	cout << "Discount amount: $" << fixed << setprecision(2) << totalDiscounts << endl;
	netSales = totalSales - totalDiscounts;
	cout << "Net sales: $" << fixed << setprecision(2) << netSales << endl;
	/*
	orderCopy.open("orders.txt");
	for (int k = 0; k < 100; k++)
	{
		if (itemList[k]->getType() == 'P')
			itemList[k]->writeData(orderCopy);
	}
	for (int k = 0; k < 100; k++)                    //Sorry about not being able to get the output to work.
	{
		if (itemList[k]->getType() == 'S')
			itemList[k]->writeData(orderCopy);
	}
	orderCopy.close();
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
	setName(tempName);
	getline(orderDetails, tempDesc);
	setDescription(tempDesc);
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
	orderWrite << getName() << endl;
	orderWrite << getDescription() << endl;
	orderWrite << size << endl;
	orderWrite << crust << endl;
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
	setName(tempName);
	getline(orderDetails, tempDesc);
	setDescription(tempDesc);
	getline(orderDetails, side);
	return;
}
void Sandwich::writeData(ostream& orderwrite)
{
	cout << getName() << "\n" << getDescription() << "\n" << side << endl;
	return;
}