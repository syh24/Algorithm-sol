#include<bits/stdc++.h>

using namespace std;

bool isOk(vector<char> v, string s) {
    if (!v.empty()) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != s[i]) return false;
        }
        return true;
    }
    else return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (auto x : skill_trees) {
        vector<char> v;
        for (auto y : x) {
            for (auto z : skill) {
                if (y == z) {
                    v.push_back(y);
                }
            }
        }
        if (isOk(v, skill)) answer++;
    }

    return answer;
}