#include <iostream>

using namespace std;

int main(void)
{
	/*
	문자 표현 : ASCII 코드 표
	false	: 0
	true	: 0이 아닌 모든 수
	unsigned : 부호 비트 없음.

	변수 : 변하는 수. 값 변경 가능
	종류	|	용량	|	데이터	|	표현범위		|	unsigned	|
	char	|	1byte	|	문자	|	-128 ~ 127		|	0 ~ 255		|
	bool	|	1byte	|	참/거짓	|	true / false	|	true/false	|
	short	|	2byte	|	정수	|	-32768 ~32767	|	0 ~ 65535	|
	int		|	4byte	|	정수	|	약 -22억 ~ 21억	|	0 ~ 약 43억	|
	float	|	4byte	|	실수	|
	double	|	8byte	|	실수	|
	*/
	int Number = 10;
	// = : 대입 연산자. 오른쪽 값을 왼쪽에 대입.
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
	// f : float형 함수
	cout << fNumber << endl;

	double dNumber = 123.4567;
	cout << dNumber << endl;


	cout << "number :" << Number << " bTest : " << bTest
		<< " cTest : " << cTest << " fNumber : " << fNumber
		<< " dNumber : " << dNumber << endl;
	return 0;
}