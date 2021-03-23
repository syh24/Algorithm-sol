#include<bits/stdc++.h>

using namespace std;

int a[1000];

string solution(string new_id) {
	string answer = "";

	// 1단계: 소문자로 변환
	for (char& c : new_id)
		c = tolower(c);

	// 2단계: 특정 문자를 제외하고 모두 삭제
	for (char c : new_id) {
		if (c != '-' && c != '_' && c != '.' && !('a' <= c && c <= 'z') && !('0' <= c && c <= '9'))
			continue;
		answer.push_back(c);
	}

	// 3단계: 연속되는 마침표 치환
	string new_id = answer;
	answer.clear();
	for (char& c : new_id) {
		if (!answer.empty() && answer.back() == '.' && c == '.') continue;
		answer += c;
	}

	// 4단계: 양 끝 마침표 제거
	if (answer.front() == '.') answer.erase(answer.begin());
	if (answer.back() == '.') answer.pop_back();

	// 5단계: 빈 문자열일 경우 "a" 로 치환
	if (answer.empty()) answer = "a";

	// 6단계: 문자열 15자로 자르기 및 마지막 마침표 제거
	if (answer.size() > 15) answer = answer.substr(0, 15);
	if (answer.back() == '.') answer.pop_back();

	// 7단계: 2자 이하일 경우 끝 글자 늘리기
	while (answer.size() <= 2) answer += answer.back();

	return answer;
}