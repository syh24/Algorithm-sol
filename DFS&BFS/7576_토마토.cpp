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

int n, m, cx = 1, k;
bool flag = false;
bool visited[1001][1001];
int maps[1001][1001];
int cnt[1001][1001];
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };

queue<pii> q;

void bfs() {

    int nx, ny;
    while (!q.empty()) {
        int aa = q.front().first;
        int bb = q.front().second;
        q.pop();
        visited[aa][bb] = true;
        for (int i = 0; i < 4; i++) {
            nx = aa + dx[i];
            ny = bb + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                if (!visited[nx][ny] && maps[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    cnt[nx][ny] = cnt[aa][bb] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }   

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int lg = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 1) {
                q.push(make_pair(i, j));
            }
            else if (maps[i][j] == -1) lg++;
        }
    }
    bfs();
    int mx = 0;
    int s = 0;
    for (int i = 0; i < m; i++) {
       for (int j = 0; j < n; j++) {
            mx = max(mx, cnt[i][j]);
            if (!visited[i][j]) s++;
        }
    }
    if (s == lg) cout << mx;
    else cout << -1;
    return 0;
}