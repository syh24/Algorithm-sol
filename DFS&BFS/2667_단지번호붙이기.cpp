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

const int Max_N = 2e5 + 1;
const int dd = 1e9;
const int mod = 1e9 + 7;

int n, m;

bool visited[25][25];
int maps[26][26];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int l[25], cnt = 0;

vector<int> v;

void dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int a = dx[i] + x;
        int b = dy[i] + y;
        if (0 <= a && a < n && 0 <= b && b < n) {
            if (maps[a][b] && !visited[a][b]) {
                dfs(a, b);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            char c;
            cin >> c;
            maps[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maps[i][j] && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
    return 0;
}