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

bool visited[101][101];
int maps[101][101];
int cnt[101][101];
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

queue<pii> q;


void bfs(int x, int y) {

    q.push(make_pair(x, y));
    visited[x][y] = true;
    cnt[x][y] = 1;
    int nx, ny;
    while (!q.empty()) {
        int aa = q.front().first;
        int bb = q.front().second;
        q.pop();
        if (aa == n - 1 && bb == m - 1) break;
        for (int i = 0; i < 4; i++) {
            nx = aa + dx[i];
            ny = bb + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (!visited[nx][ny] && maps[nx][ny]) {
                    visited[nx][ny] = true; 
                    cnt[nx][ny] = cnt[aa][bb] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    cout << cnt[n - 1][m - 1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            maps[i][j] = c - '0';
        }
    }
    bfs(0, 0);
    return 0;
}