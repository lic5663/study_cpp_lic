#include <iostream>
using namespace std;

/*
����ü : ���ӵ� ���ڿ� �̸��� �ο��� �� �մ� ���.
enum ����ü�� {} �� ���·� ����
����ü���� �̿��ؼ� ����ü Ÿ�� ���� ���� ����
��, ����ü ��ü�� ����� ���� ���� Ÿ���� �� ���� �ִ�.
*/

// �ַ� switch ������ ���ڿ� ��Ī�� �ο��� �ڵ� �������� ������Ŵ
enum NUM
{
	NUM_0,	// �ƹ��͵� �ο����� ���� ��� 0���� 1�� ���ʷ� ���� �ο�
	NUM_1,		// ��� 11 ���� ������.
	NUM_2,
	NUM_3
};
#define NUM_4 4 // ��,enum�� define�� ��ü�� �����ѰŶ� ����

int main(void)
{
	/*
	switch �� : �б⹮�� �� ����.
	if: ������ üũ vs switch : ���� ������ üũ
	���� : switch (����) {} �� ���·� ����
	�ڵ�� �ȿ��� case break�� �����Ѵ�.
	*/

	int iNumber;
	cout << "���ڸ� �Է��Ͻÿ� :";
	cin >> iNumber;

	switch (iNumber)
	{
	case NUM_0: cout << "�Է��� ���ڴ� 0��" << endl; break;
	case NUM_1: cout << "�Է��� ���ڴ� 1��" << endl; break;
	case NUM_2: cout << "�Է��� ���ڴ� 2��" << endl; break;

	default:
		break;
	}

	// ����ü Ÿ���� ������ �����ߴ�. ����ü Ÿ�� ������ 4byte
	// ����ü�� �̿��� ������ ������ ���� ǥ�� ������
	// ����ü�� ������ ���� �ȿ��� �����ϰ� �ȴ�.
	NUM eNum = (NUM)10;
	
	cout << sizeof(NUM) << endl;

	// typeid(Ÿ�� or ����).name()�� �ϸ� typeid �ȿ� ��
	// Ÿ�� Ȥ�� ������ Ÿ���� ���ڿ��� ��ȯ
	cout << typeid(NUM).name() << endl;
	cout << eNum << endl;
	return 0;
}