#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<string> words) 
{
	vector<int> answer;
	vector<string> chat;
	string last_word;
	string now_word;
	int count = 1;
	int cycle = 1;

	last_word = words[0];				// ù��°�� �����н�
	chat.push_back(last_word);
	count++;
	for (int i=1; i < words.size() ; i++)
	{
		now_word = words[i];

		for (int j = 0; j < chat.size(); j++)	// �ߺ� �ܾ� �˻�
		{
			if (now_word == chat[j])
			{
				//cout << "�ߺ� �ܾ� �߻�" << endl;
				answer.push_back(count);
				answer.push_back(cycle);
				return answer;
			}
		}

		int end_index = last_word.size()-1;	// ���ڿ� �� �ε��� ã��
		//cout << "���� �ܾ� ���κ� : " << last_word[end_index] << endl;
		//cout << "���� �ܾ� ù�κ� : " << now_word[0] << endl;
		if (last_word[end_index] != now_word[0])	// �����ձ� Ȯ��
		{
			//cout << "�����ձ� ����" << endl;
			answer.push_back(count);
			answer.push_back(cycle);
			return answer;
		}

		last_word = words[i];

		chat.push_back(now_word);			// ����ҿ� �ܾ� �߰�
		count++;

		if (count > n)						// n�� ���� �ѻ���Ŭ �߰�, n �ʱ�ȭ
		{
			cycle++;
			count = 1;
		}
		//cout << "cycle : " << cycle << " count : " << count << endl;
	}

	answer.push_back(0);
	answer.push_back(0);
	return answer;
}

int main(void)
{
	vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	vector<int> answer; 

	for (int i = 0; i < words.size(); i++)
		cout << words[i] << ", ";
	cout << endl;

	answer = solution(3, words);
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] ;
	cout << endl;
	return 0;
}