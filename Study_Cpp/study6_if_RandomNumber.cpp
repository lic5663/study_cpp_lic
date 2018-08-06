#include <iostream>
#include <time.h>
using namespace std;

int main(void)
{
	// 난수 발생
	srand((unsigned int)time(0));	// srand : 난수 테이블 작성
	// srand는 성능이 쓰레기라 c++ 11부터 사용가능한 random을 include 하거나
	// 난수 발생기를 자체 제작해서 사용한다.

	cout << rand() << endl;					// 무작위 숫자
	cout << (rand() % 100 + 100) << endl;	// 100~200 숫자
	cout << rand()%10000 / 100.f << endl;	// 0~99.99 까지

	while (1)
	{

		int iUpgrade = 0;
		cout << "Upgrade 기본 수치를 입력하시오 : ";
		cin >> iUpgrade;

		// 강화 확률을 구한다.
		float fPercent = rand() % 10000 / 100.f;

		// 강화 확률 : 업그레이드 0~3 : 100%, 4~6 : 40%, 7~9: 10%
		// 10~13 : 1% , 14~15 : 0.01%
		cout << "Upgrade : " << iUpgrade << endl;
		cout << "Percent : " << fPercent << endl;

		if (iUpgrade <= 3)
			cout << "강화 성공" << endl;

		else if (4 <= iUpgrade && iUpgrade <= 6)
		{
			if (fPercent < 40.f)
				cout << "강화 성공" << endl;
			else
				cout << "강화 실패" << endl;
		}

		else if (7 <= iUpgrade && iUpgrade <= 9)
		{
			if (fPercent < 10.f)
				cout << "강화 성공" << endl;
			else
				cout << "강화 실패" << endl;
		}

		else if (10 <= iUpgrade && iUpgrade <= 13)
		{
			if (fPercent < 1.f)
				cout << "강화 성공" << endl;
			else
				cout << "강화 실패" << endl;
		}

		else if (14 <= iUpgrade && iUpgrade <= 15)
		{
			if (fPercent < 0.01f)
				cout << "강화 성공" << endl;
			else
				cout << "강화 실패" << endl;
		}

		else if (16 <= iUpgrade)
		{
			cout << "강화 한도에 도달했습니다." << endl;
		}

	}


	return 0;
}