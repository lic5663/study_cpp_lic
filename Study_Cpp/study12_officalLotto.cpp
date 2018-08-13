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
		// �迭�� 1~45���� ���������� ����
		iLotto[i] = i + 1;
	}

	// Swap �˰��� ���
	// Shuffle�� �̿��Ѵ�. �ߺ����� ���� ���� ������ �迭��
	// �������� �� ��ġ�� ������ ���� �ٲ۴�.
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
	cout << "���ʽ� ��ȣ : " << iLotto[6] << endl;
	
	return 0;
}