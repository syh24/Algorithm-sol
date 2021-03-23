#include<bits/stdc++.h>

using namespace std;

int a[1000];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    memset(a, 0, sizeof(a));
    int mx = 0;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            mx = max(mx, numbers[i] + numbers[j]);
            a[numbers[i] + numbers[j]]++;
        }
    }

    for (int i = 0; i <= mx; i++) {
        if (a[i] > 0) answer.push_back(i);
    }
    return answer;
}