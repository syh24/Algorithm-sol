/**
 *    author:  syh1
 *    created: 02.02.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int Max_N = 2e5 + 1;
const int mod = 1e9 + 7;

int n, m, tt, k;

bool visited[50][50];
int maps[51][51];
int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int l[25];

void dfs(int x, int y) {

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nX = x + dx[i];
        int nY = y + dy[i];
        if (0 <= nX && nX < n && 0 <= nY && nY < m) {
            if (!visited[nX][nY] && maps[nX][nY]) {
                dfs(nX, nY);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   
    cin >> tt;
    while (tt--) {
        int aa, bb;
        int cnt = 0;
        cin >> n >> m >> k;

        for (int i = 0; i < k; i++) {
            cin >> aa >> bb;s
            maps[aa][bb] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && maps[i][j]) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << "\n";
        memset(visited, 0, sizeof(visited));
        memset(maps, 0, sizeof(maps));
    }
    return 0;
}