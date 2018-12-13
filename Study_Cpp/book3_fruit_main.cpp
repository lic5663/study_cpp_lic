#include "Fruit.h"

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, -1000);

	cout << "과일 판매자 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자 현황" << endl;
	buyer.ShowBuyResult();


	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자 현황" << endl;
	buyer.ShowBuyResult();



	return 0;
}