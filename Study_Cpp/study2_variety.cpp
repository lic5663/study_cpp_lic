#include <iostream>

using namespace std;

int main(void)
{
	/*
	���� ǥ�� : ASCII �ڵ� ǥ
	false	: 0
	true	: 0�� �ƴ� ��� ��
	unsigned : ��ȣ ��Ʈ ����.

	���� : ���ϴ� ��. �� ���� ����
	����	|	�뷮	|	������	|	ǥ������		|	unsigned	|
	char	|	1byte	|	����	|	-128 ~ 127		|	0 ~ 255		|
	bool	|	1byte	|	��/����	|	true / false	|	true/false	|
	short	|	2byte	|	����	|	-32768 ~32767	|	0 ~ 65535	|
	int		|	4byte	|	����	|	�� -22�� ~ 21��	|	0 ~ �� 43��	|
	float	|	4byte	|	�Ǽ�	|
	double	|	8byte	|	�Ǽ�	|
	*/
	int Number = 10;
	// = : ���� ������. ������ ���� ���ʿ� ����.
	cout << Number << endl;
	Number = 20;
	cout << Number << endl;

	bool bTest = true;
	cout << bTest << endl;
	bTest = false;
	cout << bTest << endl;

	char cTest = 't';
	cout << cTest << endl;

	float fNumber = 3.14f;
	// f : float�� �Լ�
	cout << fNumber << endl;

	double dNumber = 123.4567;
	cout << dNumber << endl;


	cout << "number :" << Number << " bTest : " << bTest
		<< " cTest : " << cTest << " fNumber : " << fNumber
		<< " dNumber : " << dNumber << endl;
	return 0;
}