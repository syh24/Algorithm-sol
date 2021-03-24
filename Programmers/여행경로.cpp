#include<bits/stdc++.h>

using namespace std;

int vst[100001];
stack<string> s;

bool dfs(vector<vector<string>> t, string now, int k, int depth) {
    if (depth == t.size()) {
        s.push(t[k][1]);
        return true;
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i][0] == now && !vst[i]) {
            vst[i] = true;
            bool f = dfs(t, t[i][1], i, depth + 1);
            if (f) {
                s.push(t[i][0]);
                return true;
            }
            vst[i] = false;
        }
    }
    return false;
}

bool compare(vector<string> v1, vector<string> v2) {
    return v1[1] < v2[1];
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), compare);
    dfs(tickets, "ICN", 0, 0);
    while (!s.empty()) {
        answer.push_back(s.top()); s.pop();
    }
    return answer;
}