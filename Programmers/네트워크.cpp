#include<bits/stdc++.h>


using namespace std;

int vst[201];
int cnt = 0;


void dfs(vector<vector<int>> c, vector<int> v, int now) {
    vst[now] = true;
    for (int i = 0; i < v.size(); i++) {
        if (i != now && !vst[i] && v[i]) {
            dfs(c, c[i], i);
        }
    }
}

int solution(int n, vector<vector<int>> c) {
    int cnt = 0;
    for (int i = 0; i < c.size(); i++) {
        if (!vst[i]) {
            dfs(c, c[i], i);
            cnt++;
        }
    }
    return cnt;
}