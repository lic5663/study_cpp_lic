#include <iostream>
using namespace std;
#define NAME_SIZE 64
/*
����ü : ���� ������ ��Ƽ� �ϳ��� ���ο� Ÿ�Ի���
����� ���� ���� Ÿ��.
���� : struct ����ü�� {};

�迭�� ����ü ������
1. ������ ����
2. ���ӵ� �޸� ���� �Ҵ�. ����ü ������� ���ӵ�
�޸� ������ ������.

*/
struct _tagStudent
{
	char	strName[NAME_SIZE];
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	int		iNumber;
	float	fAvg;
};

int main()
{
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// ����ü ũ��� ���� ���� ũ�� ��
	cout << "_tagStudent ũ�� :" << sizeof(_tagStudent) << endl;
	cout << "tStudent ũ�� :" << sizeof(tStudent) << endl;
	cout << "tStudentArr ũ�� :" << sizeof(tStudentArr) << endl;

	// ����ü ��� ���ٽ� ����ü.������ ���·� ����
	tStudent.iKor = 100;

	// tStudent.strName = "dknf"; -> ���� �߻�
	// ���ڿ��� �迭�� ���� ������ �ܼ� �������� �Ұ���
	// strcpy_s �Լ��� ���ڿ��� �����ؾ��Ѵ�.

	// ���ڿ��� ���� �׻� 0(NULL)�� �������Ѵ�.
	// �����Ⱚ�� �̹� ���ԵǾ����� ��� ���ڿ�
	// ���� �� �� ���⿡ �����Ⱚ�� ���� ���´�.
	strcpy_s(tStudent.strName, "���");
	// strcpy_s �� �����ϰ� �ڵ����� ���� NULL�� ���� 

	// strcat_s �Լ� : ������ ���� ���ڿ� ���̱�
	strcat_s(tStudent.strName, " �ȳ�");

	// strcmp �Լ� : �� ���ڿ� ���Ͽ� ���� ��� 0,
	// �ٸ� ��� 0�� �ƴ� ���� ��ȯ�Ѵ�.

	strcpy_s(tStudent.strName, "ȫ�浿");
	cout << "���� �̸��� �Է��Ͻÿ� :";
	char strName[NAME_SIZE];
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "�ش� �л��� �����մϴ�" << endl;
	}

	cout << "�̸� :" << tStudent.strName << endl;
	cout << "�й� :" << tStudent.iNumber << endl;
	cout << "���� :" << tStudent.iKor << endl;
	cout << "���� :" << tStudent.iEng << endl;
	cout << "���� :" << tStudent.iMath << endl;
	cout << "���� :" << tStudent.iTotal << endl;
	cout << "��� :" << tStudent.fAvg << endl;
	cout << "�̸� ũ�� :" << sizeof(tStudent.strName) << endl;
	cout << "�̸� ���� :" << strlen(tStudent.strName) << endl;

	return 0;
}