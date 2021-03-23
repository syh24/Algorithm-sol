#include<bits/stdc++.h>

using namespace std;

int test1[5] = { 1, 2, 3, 4, 5 };
int test2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int test3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {

    vector<int> answer;
    int score[3] = { 0, };
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == test1[i % 5]) score[0] += 1;
        if (answers[i] == test2[i % 8]) score[1] += 1;
        if (answers[i] == test3[i % 10]) score[2] += 1;
    }

    int mx = 0;

    for (int i = 0; i < 3; i++) {
        if (mx < score[i]) {
            mx = score[i];
            answer.clear();
            answer.push_back(i + 1);
        }
        else if (mx == score[i]) answer.push_back(i + 1);
    }

    return answer;
}