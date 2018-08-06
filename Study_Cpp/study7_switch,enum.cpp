#include <iostream>
using namespace std;

/*
열거체 : 연속된 숫자에 이름을 부여할 수 잇는 기능.
enum 열거체명 {} 의 형태로 구성
열거체명을 이용해서 열거체 타입 변수 선언도 가능
즉, 열거체 자체가 사용자 정의 변수 타입이 될 수도 있다.
*/

// 주로 switch 문에서 숫자에 명칭을 부여해 코드 가독성을 증가시킴
enum NUM
{
	NUM_0,	// 아무것도 부여하지 않을 경우 0부터 1씩 차례로 값이 부여
	NUM_1,		// 얘는 11 값을 가진다.
	NUM_2,
	NUM_3
};
#define NUM_4 4 // 즉,enum은 define을 단체로 지정한거랑 같음

int main(void)
{
	/*
	switch 문 : 분기문의 한 종류.
	if: 조건을 체크 vs switch : 값이 뭔지를 체크
	형태 : switch (변수) {} 의 형태로 구성
	코드블럭 안에는 case break가 들어가야한다.
	*/

	int iNumber;
	cout << "숫자를 입력하시오 :";
	cin >> iNumber;

	switch (iNumber)
	{
	case NUM_0: cout << "입력한 숫자는 0임" << endl; break;
	case NUM_1: cout << "입력한 숫자는 1임" << endl; break;
	case NUM_2: cout << "입력한 숫자는 2임" << endl; break;

	default:
		break;
	}

	// 열거체 타입의 변수를 선언했다. 열거체 타입 변수는 4byte
	// 열거체를 이용해 선언한 변수는 값의 표현 범위가
	// 열거체에 나열된 값들 안에서 선택하게 된다.
	NUM eNum = (NUM)10;
	
	cout << sizeof(NUM) << endl;

	// typeid(타입 or 변수).name()을 하면 typeid 안에 들어간
	// 타입 혹은 변수의 타입을 문자열로 반환
	cout << typeid(NUM).name() << endl;
	cout << eNum << endl;
	return 0;
}