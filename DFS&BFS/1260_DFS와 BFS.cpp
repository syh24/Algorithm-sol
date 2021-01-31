/**
 *    author:  syh1
 *    created: 01.31.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int Max_N = 1e5 + 1;
const int mod = 1e9 + 7;

bool visits[1001];
queue<int> q;
vector<int> v[1001];
int n, m, v1;

int dfs(int s) {

    cout << s << " ";
    for (int i = 0; i < v[s].size(); i++) {
        if (!visits[v[s][i]]) {
            visits[v[s][i]] = true;
            dfs(v[s][i]);
        }
    }
    return 0;
}

int bfs(int s){
    
    for (int i = 0; i < 1001; i++) {
        visits[i] = false;
    }
    int a = 0;
    visits[s] = true;
    while (!q.empty()) {
        a = q.front();
        q.pop();
        for (int i = 0; i < v[a].size(); i++) {
            if (!visits[v[a][i]]) {
                visits[v[a][i]] = true;
                q.push(v[a][i]);
            }
        }
        cout << a << " ";
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> v1;
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    for (int i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    q.push(v1);
    visits[v1] = true;
    dfs(v1);
    cout << "\n";
    bfs(v1);
    return 0;
}