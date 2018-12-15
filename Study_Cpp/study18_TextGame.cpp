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
	JOB_SIZE = 32,
	INIT_GOLD = 10000
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_ESCAPE
};

class _tagInventory
{
private:
	int iGold;
public:
	void InitGold(int gold);
	void AddGold(int gold);
	int  GetGold();
};

void _tagInventory::InitGold(int gold)
{
	iGold = gold;
}
void _tagInventory::AddGold(int gold)
{
	iGold += gold;
}
int _tagInventory::GetGold()
{
	return iGold;
}


class Player
{
public:
	void	setName(char *name);
	char*	getName();
	void	setJob(char *job);
	char*	getJob();
	int		getAttackMin();
	int		getAttackMax();
	int		getArmorMin();
	int		getArmorMax();
	int		getHP();
	void	setHP(int hp);
	void	addExp(int exp);
	void	addGold(int gold);
	void	Lose();
	void	regen();
	

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
	_tagInventory tInventory;

};


void Player::setName(char* name)
{
	strcpy_s(strName, name);
}

char* Player::getName()
{
	return strName;
}

void Player::setJob(char* job)
{
	strcpy_s(strJobName, job);
}

char* Player::getJob()
{
	return strJobName;
}

int Player::getAttackMin()
{
	return iAttackMin;
}
int	Player::getAttackMax()
{
	return iAttackMax;
}
int	Player::getArmorMin()
{
	return iArmorMin;
}
int	Player::getArmorMax()
{
	return iArmorMax;
}
int	Player::getHP()
{
	return iHP;
}
void Player::setHP(int hp)
{
	if (hp < 0)
		iHP = 0;
	else
		iHP = hp;
}
void Player::addExp(int exp)
{
	iExp += exp;
}
void Player::addGold(int gold)
{
	tInventory.AddGold(gold);
}
void Player::regen()
{
	iHP = iHPMax;
	iMP = iMPMax;
}
void Player::Lose()
{
	cout << iExp * 0.1 << "의 경험치와 " << tInventory.GetGold()*0.1 << "의 골드를 잃었습니다." << endl;
	iExp = iExp*0.9;
	tInventory.AddGold(tInventory.GetGold()*0.1*(-1));
}

void Player::InitCommonStatus()
{
	iExp = 0;
	iLevel = 1;
	tInventory.InitGold(PLAYER::INIT_GOLD);
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
	cout << "=========================플레이어=========================" << endl;
	cout << "이름 : " << strName << endl;
	cout << "직업 : " << strJobName << endl;
	cout << "레벨 : " << iLevel << endl;
	cout << "경험치 : " << iExp << endl;
	cout << "공격력 : " << iAttackMin << " ~ " << iAttackMax << endl;
	cout << "방어력 : " << iArmorMin << " ~ " << iArmorMax << endl;
	cout << "체력 : " << iHPMax << "/" << iHP << endl;
	cout << "마나 : " << iMPMax << "/" << iMP << endl;
	cout << "보유 골드 :" << tInventory.GetGold() << endl;
}





class Monster
{
public:
	void	setName(char* name);
	char*	getName();
	int		getAttackMin();
	int		getAttackMax();
	int		getArmorMin();
	int		getArmorMax();
	int		getHP();
	void	setHP(int hp);
	int		getExp();
	int		getGold();
	void	regen();

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
char* Monster::getName()
{
	return strName;
}
int Monster::getAttackMin()
{
	return iAttackMin;
}
int	Monster::getAttackMax()
{
	return iAttackMax;
}
int	Monster::getArmorMin()
{
	return iArmorMin;
}
int	Monster::getArmorMax()
{
	return iArmorMax;
}
int	Monster::getHP()
{
	return iHP;
}
void Monster::setHP(int hp)
{
	if (hp < 0)
		iHP = 0;
	else
		iHP = hp;
}
int Monster::getExp()
{
	return iExp;
}
int Monster::getGold()
{
	return rand() % (iGoldMax - iGoldMin + 1) + iGoldMin;
}
void Monster::regen()
{
	iHP = iHPMax;
	iMP = iMPMax;
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
	cout << "========================= 몬스터 =========================" << endl;
	cout << "이름 : " << strName << endl;
	cout << "공격력 : " << iAttackMin << " ~ " << iAttackMax << endl;
	cout << "방어력 : " << iArmorMin << " ~ " << iArmorMax << endl;
	cout << "체력 : " << iHPMax << "/" << iHP << endl;
	cout << "마나 : " << iMPMax << "/" << iMP << endl;
	cout << "레벨 : " << iLevel << endl;
	cout << "처치 시 경험치 : " << iExp << endl;
	cout << "처치 시 획득골드 : " << iGoldMin << " ~ " << iGoldMax << endl;
}


void PlayerDamageStep(Player& player, Monster& enemy , int damage)
{
	cout << "플레이어의 공격!" << endl;
	cout << player.getName() << "은(는)" << enemy.getName() << "에게" << damage << "의 피해를 입혔다" << endl;
	enemy.setHP(enemy.getHP() - damage);
}

void EnemyDamageStep(Player& player, Monster& enemy, int damage)
{
	cout << "몬스터의 공격!" << endl;
	cout << enemy.getName() << "은(는)" << player.getName() << "에게" << damage << "의 피해를 입혔다" << endl;
	player.setHP(player.getHP() - damage);
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
		player.InitIndividualStatus(5, 75, 15, 20, 500, 100);
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

				system("cls");
				switch (iMenu)
				{
				case MT_EASY :
					cout << "--쉬움--" << endl;
					break;
				case MT_NORMAL :
					cout << "--중간--" << endl;
					break;
				case MT_HARD :
					cout << "--어려움--" << endl;
					break;
				default:
					break;
				}
				bool battleFlag = true;

				while (battleFlag)
				{
					system("cls");
					enemy.ShowMonsterStatus();
					player.ShowPlayerStatus();

					// BATTLE
					cout << "------------------------------------------------------" << endl;
					cout << "1. 공격" << endl;
					cout << "2. 퇴각" << endl;
					cout << "메뉴를 선택하세요 : ";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iMenu == BATTLE_ESCAPE)
					{
						cout << "퇴각합니다." << endl;
						battleFlag = false;
						_sleep(1000);
						break;
					}

					switch (iMenu)
					{
					case BATTLE_ATTACK:
					{
						int iAttack = rand() % (player.getAttackMax() - player.getAttackMin() + 1) + player.getAttackMin();
						int eArmor = rand() % (enemy.getArmorMax() - enemy.getArmorMin() + 1) + enemy.getArmorMin();

						int iDamage = iAttack - eArmor;
						iDamage = iDamage < 0 ? 0 : iDamage;

						PlayerDamageStep(player, enemy, iDamage);
						_sleep(1000);
						if (enemy.getHP() <= 0)
						{
							cout << "적이 쓰러졌습니다." << endl;
							player.addExp(enemy.getExp());
							cout << enemy.getExp() << "의 경험치를 획득했습니다." << endl;
							int gold = enemy.getGold();
							player.addGold(gold);
							cout << gold << "골드를 획득했습니다." << endl;
							battleFlag = false;

							// monster regen
							enemy.regen();
							system("pause");
							break;
						}
							

						iAttack = rand() % (enemy.getAttackMax() - enemy.getAttackMin() + 1) + enemy.getAttackMin();
						eArmor = rand() % (player.getArmorMax() - player.getArmorMin() + 1) + player.getArmorMin();

						iDamage = iAttack - eArmor;
						iDamage = iDamage < 0 ? 0 : iDamage;

						EnemyDamageStep(player, enemy, iDamage);
						if (player.getHP() <= 0)
						{
							cout << "플레이어가 쓰러졌습니다." << endl;
							player.Lose();

							// moster & player regen
							enemy.regen();
							player.regen();

							battleFlag = false;
							system("pause");
							break;
						}
						_sleep(2000);
					}
					break;
					default:
						break;
					}
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