#include<bits/stdc++.h>

using namespace std;

int a[1000];

string solution(string new_id) {
	string answer = "";

	// 1�ܰ�: �ҹ��ڷ� ��ȯ
	for (char& c : new_id)
		c = tolower(c);

	// 2�ܰ�: Ư�� ���ڸ� �����ϰ� ��� ����
	for (char c : new_id) {
		if (c != '-' && c != '_' && c != '.' && !('a' <= c && c <= 'z') && !('0' <= c && c <= '9'))
			continue;
		answer.push_back(c);
	}

	// 3�ܰ�: ���ӵǴ� ��ħǥ ġȯ
	string new_id = answer;
	answer.clear();
	for (char& c : new_id) {
		if (!answer.empty() && answer.back() == '.' && c == '.') continue;
		answer += c;
	}

	// 4�ܰ�: �� �� ��ħǥ ����
	if (answer.front() == '.') answer.erase(answer.begin());
	if (answer.back() == '.') answer.pop_back();

	// 5�ܰ�: �� ���ڿ��� ��� "a" �� ġȯ
	if (answer.empty()) answer = "a";

	// 6�ܰ�: ���ڿ� 15�ڷ� �ڸ��� �� ������ ��ħǥ ����
	if (answer.size() > 15) answer = answer.substr(0, 15);
	if (answer.back() == '.') answer.pop_back();

	// 7�ܰ�: 2�� ������ ��� �� ���� �ø���
	while (answer.size() <= 2) answer += answer.back();

	return answer;
}