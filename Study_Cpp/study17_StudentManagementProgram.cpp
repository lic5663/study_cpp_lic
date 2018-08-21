#include <iostream>
using namespace std;

#define NAME_SIZE		32
#define STUDENT_MAX		10
#define ADDRESS_SIZE	128
#define PHONE_SIZE		14

struct _tagStudent
{
	char	strName[NAME_SIZE];
	char	strAddress[ADDRESS_SIZE];
	char	strPhoneNumber[PHONE_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	// �迭�� ����� �� ī���Ϳ� ����
	int iStudentCount = 0;
	int iStdNumber = 1;
	char strName[NAME_SIZE] = {};

	while (true)
	{
		system("cls");

		// �޴� ���
		cout << "1. �л����" << endl;
		cout << "2. �л�����" << endl;
		cout << "3. �л�Ž��" << endl;
		cout << "4. �л����" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		
		int iMenu;
		cin >> iMenu;
		// cin�� ���ڰ� �Էµɽ� ���� ���� ���� �߻�
		// ���� �߻��� ���� ���۸� ����ֵ��� �ؼ�
		// ���ѷ��� �߻��� ���´�.

		// ���� üũ
		// cin���� �Է� ���� �߻��� true�� ��ȯ�Ѵ�.
		if (cin.fail())
		{
			// �������� �����
			cin.clear();
			// �Է� ���ۿ� \n�� ���������Ƿ� �Է¹��۸�
			// �˻��Ͽ� \n�� �����

			// ����: �˻��� ���� ũ��, ����: ã���� �ϴ� ����
			// �Է¹��� ó������ \n�� �ִ°� ���� ã�� �ش�
			// �κ��� ��� �����ؼ� ���� �Է��� �����ϵ���
			// �����
			cin.ignore(1024, '\n');
		}
		

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			// ��ϵ� �л��� �ִ��� ��� ����� ����
			if (iStudentCount == STUDENT_MAX)
			{
				cout << "��� �ִ� �� ����" << endl;
				break;
			}

			// �л����� �߰�. 
			// �й�, �ּ�, ��ȭ, �̸�, ����, ����, ����, ����, ���
			system("cls");
			cout << "=================== �л� �߰� ===================" << endl;

			cout << "�̸� : ";
			cin >> tStudentArr[iStudentCount].strName;
			// �Ĺ� cin ���� ���ſ�
			cin.ignore(1024, '\n');
			

			cout << "�ּ� : ";
			// cin�� ���鵵 ������ �ν������� ������
			// cin >> tStudentArr[iStudentCount].strAddress;
			// cin.getline(���� ����, ���۰�)
			// �׷��� cin.getline �� cin�� ���� ���ۿ� ���Ͱ�
			// ���� ���������� �۵����� �ʴ´�.
			cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

			cout << "�޴��� : ";
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber,PHONE_SIZE);

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;
			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;
			tStudentArr[iStudentCount].iNumber = iStdNumber;
			
			++iStdNumber;
			++iStudentCount;

			cout << "�л� �߰� �Ϸ�" << endl;
			break;
		case MENU_DELETE:
			system("cls");
			// ������ ����� ���� ������ ����
			if (iStudentCount == 0)
			{
				cout << "����� �л��� �����ϴ�." << endl << endl;
				break;
			}
			cout << "=================== �л� ���� ===================" << endl;
			cin.ignore(1024, '\n');
			cout << "������ �̸��� �Է��ϼ��� :";
			cin.getline(strName, NAME_SIZE);
		
			for (int i = 0; i < iStudentCount; i++)
			{
				// ������ ����� �����ϴ� ���
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					for (int j = i; j < iStudentCount - 1; j++)
					{
						tStudentArr[i] = tStudentArr[i + 1];
					}
					--iStudentCount;
					cout << "�л��� ���������� �����߽��ϴ�." << endl;
				}
				else if (i == (iStudentCount-1))
				{
					cout << "�ش� �л��� �������� �ʽ��ϴ�" << endl << endl;
					break;
				}
			}

			break;
		case MENU_SEARCH:
			// �̸����� �˻��Ѵ�.
			system("cls");
			cout << "=================== �л� Ž�� ===================" << endl;
			// ������ ����� �����Ͱ� �������� ������ ����
			if (iStudentCount == 0)
			{
				cout << "����� �л��� �����ϴ�." << endl<<endl;
				break;	
			}
			// switch�� ���ο� ���� ����� �ʱ�ȭ ������ �߻��Ѵ�.
			//char strSeachName[NAME_SIZE] = {};
			// ���� �ش� �κ��� while�� �ۿ� ����
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ��� :";
			cin.getline(strName,NAME_SIZE);

			for (int i = 0; i < iStudentCount; i++)
			{
				//ã�� ���
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "�̸� :" << tStudentArr[i].strName << endl;
					cout << "�ּ� :" << tStudentArr[i].strAddress << endl;
					cout << "��ȭ��ȣ :" << tStudentArr[i].strPhoneNumber << endl;
					cout << "�й� :" << tStudentArr[i].iNumber << endl;
					cout << "���� :" << tStudentArr[i].iKor << endl;
					cout << "���� :" << tStudentArr[i].iEng << endl;
					cout << "���� :" << tStudentArr[i].iMath << endl;
					cout << "���� :" << tStudentArr[i].iTotal << endl;
					cout << "��� :" << tStudentArr[i].fAvg << endl << endl;
					break;
				}
				else if (i == (iStudentCount - 1))
					cout << "�ش� �л��� �������� �ʽ��ϴ�." << endl << endl;
			}

			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "=================== �л� ��� ===================" << endl;
			// ������ ����� ���� ������ ����
			if (iStudentCount == 0)
			{
				cout << "����� �л��� �����ϴ�." << endl<< endl;
				break;
			}
			
			// ��ϵ� �л� ����ŭ �ݺ��ϸ� ���
			for (int i = 0; i < iStudentCount; i++)
			{
				cout << "�̸� :" << tStudentArr[i].strName << endl;
				cout << "�ּ� :" << tStudentArr[i].strAddress << endl;
				cout << "��ȭ��ȣ :" << tStudentArr[i].strPhoneNumber << endl;
				cout << "�й� :" << tStudentArr[i].iNumber << endl;
				cout << "���� :" << tStudentArr[i].iKor << endl;
				cout << "���� :" << tStudentArr[i].iEng << endl;
				cout << "���� :" << tStudentArr[i].iMath << endl;
				cout << "���� :" << tStudentArr[i].iTotal << endl;
				cout << "��� :" << tStudentArr[i].fAvg << endl << endl;
			}
			break;
		default:
			cout << "�߸��� �޴� ����!" << endl;
			break;
		}
		system("pause");

	}

	return 0;
}