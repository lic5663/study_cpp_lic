#include "Fruit.h"

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, -1000);

	cout << "���� �Ǹ��� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� ������ ��Ȳ" << endl;
	buyer.ShowBuyResult();


	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ��� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� ������ ��Ȳ" << endl;
	buyer.ShowBuyResult();



	return 0;
}