/**
 *    author:  syh1
 *    created: 02.23.2021
**/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

int n, m, a[501][501];
bool vst[501][501];
int cnt;
int dp[501][501];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int dfs(int x, int y) {

    if (x == n - 1 && y == m - 1) {
        return 1;
    }

    if (dp[x][y] == -1) {
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] < a[x][y]) {
                    dp[x][y] += dfs(nx, ny);
                }
            }
        }
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            dp[i][j] = -1;
        }
    }
    vst[0][0] = true;
    cout << dfs(0, 0);
    return 0;
}