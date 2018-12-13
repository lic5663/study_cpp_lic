#pragma once

#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>
using namespace std;


class FruitSeller
{
public:
	void InitMembers(int price, int num, int money);
	int SaleApples(int money);
	void ShowSalesResult();

private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

};

class FruitBuyer
{
public:
	void InitMembers(int money);
	bool BuyChecker(int money);
	void BuyApples(FruitSeller &seller, int money);
	void ShowBuyResult();

private:
	int myMoney;
	int numOfApples;
};

#endif // !__FRUIT_H__
