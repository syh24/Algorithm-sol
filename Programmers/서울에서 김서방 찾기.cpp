#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> seoul) {
    string answer;
    string key = "Kim";
    for (int i = 0; i < seoul.size(); i++) {
        if (key == seoul[i]) {
            answer += "�輭���� ";
            answer += to_string(i);
            answer += "�� �ִ�";
            return answer;
        }
    }
}