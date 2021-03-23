#include<bits/stdc++.h>

using namespace std;

string solution(vector<string> seoul) {
    string answer;
    string key = "Kim";
    for (int i = 0; i < seoul.size(); i++) {
        if (key == seoul[i]) {
            answer += "김서방은 ";
            answer += to_string(i);
            answer += "에 있다";
            return answer;
        }
    }
}