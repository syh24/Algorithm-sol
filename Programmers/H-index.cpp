#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for (int i = citations.size() - 1; i >= 0; i--) {
        if (citations[i] <= answer) {
            break;
        }
        answer++;
    }
    return answer;
}