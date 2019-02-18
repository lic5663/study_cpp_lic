#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
	int answer = 0;
	int preskill_index = 0;
	int postskill_index = 0;
	bool skillOK = true;

	for (int i = 0; i < skill_trees.size(); i++)
	{
		skillOK = true;

		for (int j = 0 ; j < skill.size()-1 ; j++)
		{
			preskill_index = skill_trees[i].find(skill[j]);
			postskill_index = skill_trees[i].find(skill[j+1]);
			
			cout << "pre : " << skill[j] << " " << preskill_index << endl;
			cout << "post : " << skill[j + 1] << " " << postskill_index << endl;
			cout << endl;

			if (preskill_index < 0 && postskill_index >= 0)
			{
				cout << skill_trees[i] << "는 안됨" << endl;
				skillOK = false;
				break;
			}

			if (postskill_index < 0 || preskill_index < 0)
				continue;

			if (postskill_index < preskill_index)
			{
				cout << skill_trees[i] << "는 안됨" << endl;
				skillOK = false;
				break;
			}
		}
		if (skillOK)
		{
			cout << skill_trees[i] << "는 가능" << endl;
			answer++;
		}
			
	}

	return answer;
}

int main(void)
{
	string skill = "CBD";
	vector<string> skill_tree = { "BACDE", "CBADF", "AECB", "BDA" };

	cout << "skill : " << skill << endl;
	for (int i = 0; i < skill_tree.size(); i++)
		cout << skill_tree[i] << ", ";
	cout << endl;
	cout << "가능 스킬트리 수 : " << solution(skill, skill_tree) << endl;


	return 0;
}