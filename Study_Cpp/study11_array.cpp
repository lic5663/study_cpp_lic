#include <iostream>
using namespace std;

int main()
{
	// do while : ������ �� ���� üũ
	int iNumber = 0;
	do
	{
		//cout << iNumber << endl;
	} while (iNumber>0);

	/*
	�迭 : ���� ���� ���� �� ����
	���� : ����Ÿ�� �迭��[����]
	Ư¡ : ���ӵ� �޸� ���� ������ ����
	�迭�� �ε����� �̿��� ���ϴ� ��ġ�� ���� ����
	index : 0 ~ ����-1
	*/

	int iArray[10] = {};

	iArray[1] = 1234;

	for (int i = 0; i< 10 ; i++)
		cout << iArray[i] << endl;

	// 2���� �迭
	int iArray2[10][10] = {};

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << iArray2[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}