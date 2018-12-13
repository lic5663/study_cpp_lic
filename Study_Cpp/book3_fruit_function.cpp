#include "Fruit.h"

void FruitSeller::InitMembers(int price, int num, int money)
{
	APPLE_PRICE = price;
	numOfApples = num;
	myMoney = money;
}

int FruitSeller::SaleApples(int money)
{
	int num = money / APPLE_PRICE;
	numOfApples -= num;
	myMoney += money;
	return num;
}

void FruitSeller::ShowSalesResult()
{
	cout << "남은 사과 :" << numOfApples << endl;
	cout << "판매 수익 :" << myMoney << endl << endl;
}

void FruitBuyer::InitMembers(int money)
{
	myMoney = money;
	numOfApples = 0;
}

bool FruitBuyer::BuyChecker(int money)
{
	if (money < 0)
	{
		cout << "잘못된 돈 기입" << endl;
		return false;
	}
}

void FruitBuyer::BuyApples(FruitSeller &seller, int money)
{
	if (BuyChecker(money))
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	else
		cout << "구매 불가" << endl;
}

void FruitBuyer::ShowBuyResult()
{
	cout << "현재 잔액 :" << myMoney << endl;
	cout << "사과 개수 :" << numOfApples << endl << endl;
}