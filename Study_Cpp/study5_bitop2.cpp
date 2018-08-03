#include <iostream>
using namespace std;

int main(void)
{
	// ��� : ������ �ʴ� ��.
	// ����� ����� ���ÿ� ���� �����ؾ��Ѵ�.
	//0x : 16����
	const int iAttack	= 0x00000001;	//	1
	const int iArmor = 0x00000002;		//	10
	const int iHP = 0x00000004;			//	100
	const int iMP = 0x00000008;			//	1000
	const int iCritical = 0x00000010;	//	10000
	//�� bit���� �ǹ� �ο�

	int iBuf = iAttack | iHP | iCritical;

	//������ ����� iBuf = iBuf ^ iHP;
	iBuf ^= iHP;	// XOR�� ����ϸ� ����ġ���� ���·� ������ִ�.
	iBuf ^= iHP;

	cout << "Attack : " << (iBuf & iAttack) << endl;
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << "HP : " << (iBuf & iHP) << endl;
	cout << "MP : " << (iBuf & iMP) << endl;
	cout << "Critical : " << (iBuf & iCritical) << endl;

	/*
	����Ʈ ������ : << , >> ���� ���� �����Ͽ� ������ ����
	ex) 20 << 2 
	20 -> ������ ��ȯ -> 10100
	<<2 ���� -> 1010000
	�ٽ� 10���� ��ȯ -> 80
	<< = *2 , >> = /2 �� ����ȭ�� �����.
	�Ϲ����� ���� ���������� �ӵ��� �ξ� ������.
	*/

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;
	iNumber <<= 16;

	iNumber |= iLow;
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;


	// ���������� : ++, -- 1���� 1���� ȿ��
	iNumber = 10;

	//��ġ
	++iNumber;

	//��ġ
	iNumber++;

	cout << iNumber << endl;
	cout << ++iNumber << endl;
	cout << iNumber++ << endl;
	cout << iNumber << endl;
	return 0;
}