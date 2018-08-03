#include <iostream>
using namespace std;

int main(void)
{
	// 상수 : 변하지 않는 수.
	// 상수는 선언과 동시에 값을 지정해야한다.
	//0x : 16진수
	const int iAttack	= 0x00000001;	//	1
	const int iArmor = 0x00000002;		//	10
	const int iHP = 0x00000004;			//	100
	const int iMP = 0x00000008;			//	1000
	const int iCritical = 0x00000010;	//	10000
	//각 bit마다 의미 부여

	int iBuf = iAttack | iHP | iCritical;

	//연산자 축약형 iBuf = iBuf ^ iHP;
	iBuf ^= iHP;	// XOR을 사용하면 스위치같은 형태로 만들수있다.
	iBuf ^= iHP;

	cout << "Attack : " << (iBuf & iAttack) << endl;
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << "HP : " << (iBuf & iHP) << endl;
	cout << "MP : " << (iBuf & iMP) << endl;
	cout << "Critical : " << (iBuf & iCritical) << endl;

	/*
	쉬프트 연산자 : << , >> 값대 값을 연산하여 값으로 나옴
	ex) 20 << 2 
	20 -> 이진수 변환 -> 10100
	<<2 연산 -> 1010000
	다시 10진수 변환 -> 80
	<< = *2 , >> = /2 의 값변화가 생긴다.
	일반적인 곱셈 나눗셈보다 속도가 훨씬 빠르다.
	*/

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;
	iNumber <<= 16;

	iNumber |= iLow;
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;


	// 증감연산자 : ++, -- 1증가 1감소 효과
	iNumber = 10;

	//전치
	++iNumber;

	//후치
	iNumber++;

	cout << iNumber << endl;
	cout << ++iNumber << endl;
	cout << iNumber++ << endl;
	cout << iNumber << endl;
	return 0;
}