#include <iostream>
using namespace std;

int main()
{
	// do while : 선실행 후 조건 체크
	int iNumber = 0;
	do
	{
		//cout << iNumber << endl;
	} while (iNumber>0);

	/*
	배열 : 다중 변수 생성 및 관리
	형태 : 변수타입 배열명[개수]
	특징 : 연속된 메모리 블럭에 공간이 형성
	배열은 인덱스를 이용해 원하는 위치에 접근 가능
	index : 0 ~ 개수-1
	*/

	int iArray[10] = {};

	iArray[1] = 1234;

	for (int i = 0; i< 10 ; i++)
		cout << iArray[i] << endl;

	// 2차원 배열
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