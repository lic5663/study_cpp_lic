#include <iostream>
using namespace std;
void binary_change(int number);

int main(void)
{
	int number;
	/*
	���� : 2����, 8����, 10����, 16����
	2����	: 0 ~ 1
	8����	: 0 ~ 7
	10����	: 0 ~ 9
	16����	: 0 ~ 15 -> 0 ~ f

	�������� ��ȣ ��ȯ�� �����ϴ�.

	��Ʈ���� �������� : 2���� ������ ������ ����
	���� : AND(&), OR(|), NOT(~), XOR(^)
	A	B	XOR
	0	0	0
	1	0	1
	0	1	1
	1	1	0

	*/

	cout << "2������ ��ȯ�� ���� �Է��Ͻÿ�" << endl;
	cin >> number;
	binary_change(number);

	return 0;
}

void binary_change(int number)
{
	int quotient =0;

	if (number == 1)
	{
		cout << number;
	}
	else
	{
		quotient = number / 2;
		binary_change(quotient);
		cout << number % 2;
	}
}