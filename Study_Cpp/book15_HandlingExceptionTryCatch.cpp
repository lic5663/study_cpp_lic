#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;
	cout << "�� ���� �Է� : ";
	cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
			throw num2;
		
	}
	catch (int expn)
	{
		cout << "������ " << expn << "�� �� �� �����ϴ�." << endl;
		cout << "���α׷� ����� �ʿ�" << endl;
	}
	cout << "end of main" << endl;

	return 0;
}