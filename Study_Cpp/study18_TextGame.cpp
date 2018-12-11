#include <iostream>
#include <time.h>

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum PLAYER
{
	NAME_SIZE = 32,
	JOB_SIZE = 32
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};
class Player
{
public:
	void setName(char *name);
	void setJob(char *job);
	void InitCommonStatus();
	void InitIndividualStatus(int AttackMin, int AttackMax, int ArmorMin, int ArmorMax, int iHPMax, int iMPMax);
	void ShowPlayerStatus();

private:
	char	strName[NAME_SIZE];
	char	strJobName[JOB_SIZE];
	JOB		eJob;

	// Player Status
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;

};

void Player::setName(char* name)
{
	strcpy_s(strName, name);
}

void Player::setJob(char* job)
{
	strcpy_s(strJobName, job);
}

void Player::InitCommonStatus()
{
	iExp = 0;
	iLevel = 1;
}

void Player::InitIndividualStatus(int AttackMin, int AttackMax, int ArmorMin, int ArmorMax, int HPMax, int MPMax)
{
	iAttackMin = AttackMin;
	iAttackMax = AttackMax;
	iArmorMin = ArmorMin;
	iArmorMax = ArmorMax;
	iHPMax = HPMax;
	iHP = HPMax;
	iMPMax = MPMax;
	iMP = MPMax;
}

void Player::ShowPlayerStatus()
{
	cout << "이름 : " << strName << endl;
	cout << "직업 : " << strJobName << endl;
	cout << "공격력 : " << iAttackMin << " ~ " << iAttackMax << endl;
	cout << "방어력 : " << iArmorMin << " ~ " << iArmorMax << endl;
	cout << "체력 : " << iHPMax << "/" << iHP << endl;
	cout << "마나 : " << iMPMax << "/" << iMP << endl;
}



class Monster
{
public:
	void setName(char* name);
	void Status(int AttackMin, int AttackMax, int ArmorMin, int ArmorMax, int HPMax, int MPMax, int Level, int Exp, int GoldMin, int GoldMax);
	void ShowMonsterStatus();
private:
	char	strName[NAME_SIZE];

	// Monster Status
	int		iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;


};

void Monster::setName(char* name)
{
	strcpy_s(strName, name);
}

void Monster::Status(int AttackMin, int AttackMax, int ArmorMin, int ArmorMax, int HPMax, int MPMax, int Level, int Exp, int GoldMin, int GoldMax)
{
	iAttackMin = AttackMin;
	iAttackMax = AttackMax;
	iArmorMin = ArmorMin;
	iArmorMax = ArmorMax;
	iHPMax = HPMax;
	iHP = HPMax;
	iMPMax = MPMax;
	iMP = MPMax;
	iLevel = Level;
	iExp = Exp;
	iGoldMin = GoldMin;
	iGoldMax = GoldMax;
}

void Monster::ShowMonsterStatus()
{
	cout << "이름 : " << strName << endl;
	cout << "공격력 : " << iAttackMin << " ~ " << iAttackMax << endl;
	cout << "방어력 : " << iArmorMin << " ~ " << iArmorMax << endl;
	cout << "체력 : " << iHPMax << "/" << iHP << endl;
	cout << "마나 : " << iMPMax << "/" << iMP << endl;
	cout << "레벨 : " << iLevel << endl;
	cout << "처치 시 경험치 : " << iExp << endl;
	cout << "처치 시 획득골드 : " << iGoldMin << " ~ " << iGoldMax << endl;
}

int main()
{
	srand((unsigned int)time(0));

	// Player Create
	Player player;
	cout << "이름 : ";
	char tempName[NAME_SIZE];
	cin.getline(tempName, NAME_SIZE - 1);
	player.setName(tempName);

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 :";
		cin >> iJob;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}

	player.InitCommonStatus();
	switch (iJob)
	{
	case JOB_KNIGHT :
		player.setJob("기사");
		player.InitIndividualStatus(5, 35, 15, 20, 500, 100);
		break;
	case JOB_ARCHER :
		player.setJob("궁수");
		player.InitIndividualStatus(10, 20, 5, 10, 300, 300);
		break;
	case JOB_WIZARD :
		player.setJob("마법사");
		player.InitIndividualStatus(0, 100, 0, 10, 200, 400);
		break;
	default:
		break;
	}


	// Monster Create
	Monster monster[3];

	monster[0].setName("고블린");
	monster[0].Status(5, 10, 2, 5, 100, 0, 1, 50, 500, 1000);

	monster[1].setName("트롤");
	monster[1].Status(15, 30, 10, 30, 300, 100, 5, 300, 1500, 3000);

	monster[2].setName("오우거");
	monster[2].Status(50, 100, 30, 50, 1000, 300, 10, 1000, 5000, 10000);


	// 메인 로비
	while (true)
	{
		system("cls");
		cout << "------------------------로비------------------------" << endl;
		player.ShowPlayerStatus();
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MAIN_MENU::MM_EXIT)
		{
			cout << "종료합니다" << endl;
			break;
		}
		
		switch (iMenu)
		{
		case MAIN_MENU::MM_MAP :
			while (true)
			{
				system("cls");
				cout << "------------------------ 맵 ------------------------" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로" << endl;
				cout << "맵을 선택하세요" << endl;
				cin >> iMenu;
				
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
				}

				if (iMenu == MAP_TYPE::MT_BACK)
				{
					break;
				}

				Monster enemy = monster[iMenu - 1];

				switch (iMenu)
				{
				case MT_EASY :
					cout << "-------------------------쉬움-------------------------" << endl;
					enemy.ShowMonsterStatus();
					cin.clear();
					cin.ignore(1024, '\n');
					getchar();
					break;
				case MT_NORMAL :
					cout << "-------------------------중간-------------------------" << endl;
					enemy.ShowMonsterStatus();
					cin.clear();
					cin.ignore(1024, '\n');
					getchar();
					break;
				case MT_HARD :
					cout << "------------------------어려움------------------------" << endl;
					enemy.ShowMonsterStatus();
					cin.clear();
					cin.ignore(1024, '\n');
					getchar();
					break;
				default:
					break;
				}

			}
			break;

		case MAIN_MENU::MM_STORE :
			break;

		case MAIN_MENU::MM_INVENTORY:
			break;

		default:
			cout << "잘못된 선택" << endl;
			break;
		}

		
	}
	return 0;
}