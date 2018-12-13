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
	cout << "���� ��� :" << numOfApples << endl;
	cout << "�Ǹ� ���� :" << myMoney << endl << endl;
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
		cout << "�߸��� �� ����" << endl;
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
		cout << "���� �Ұ�" << endl;
}

void FruitBuyer::ShowBuyResult()
{
	cout << "���� �ܾ� :" << myMoney << endl;
	cout << "��� ���� :" << numOfApples << endl << endl;
}