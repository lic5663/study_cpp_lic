#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	// Lotto Program
	int iLotto[45] = {};

	for (int i = 0; i < 45; ++i)
	{
		// 배열에 1~45까지 순차적으로 대입
		iLotto[i] = i + 1;
	}

	// Swap 알고리즘 사용
	// Shuffle을 이용한다. 중복되지 않은 값을 저장한 배열을
	// 무작위의 두 위치를 선정해 값을 바꾼다.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;

		cout << "idx1: " << idx1 << " \tidx2: " << idx2 << endl;
	}

	for (int i = 1; i <= 45; ++i)
	{
		cout << iLotto[i-1] << " ";

		if ((i % 5) == 0)
			cout << endl;
	}

	for (int i = 0; i < 6; ++i)
		cout << iLotto[i] << "\t";
	cout << "보너스 번호 : " << iLotto[6] << endl;
	
	return 0;
}