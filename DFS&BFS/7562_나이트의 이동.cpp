/**
 *    author:  syh1
 *    created: 02.03.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int Max_N = 2e5 + 1;
const int mod = 1e9 + 7;

int dx[] = { 1,2,-1,-2,1,2,-1,-2 };
int dy[] = { 2,1,2,1,-2,-1,-2,-1 };
bool vst[301][301];
int cnt[301][301];
queue<pii> q;
int tt, l;

int bfs(int x, int y) {

    while (!q.empty()) {

        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        
        if (qx == x && qy == y) {
            while (!q.empty()) q.pop();
            return cnt[x][y];
        }
        for (int i = 0; i < 8; i++) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if (0 <= nx && nx < l && 0 <= ny && ny < l) {
                if (!vst[nx][ny]) {
                    vst[nx][ny] = true;
                    cnt[nx][ny] = cnt[qx][qy] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tt;
    while (tt--) {
        cin >> l;
        int a, b;
        cin >> a >> b;
        vst[a][b] = true;
        q.push(make_pair(a, b));
        int x, y;
        cin >> x >> y;
        cout << bfs(x, y) << "\n";
        memset(vst, 0, sizeof(vst));
        memset(cnt, 0, sizeof(cnt));
    }
    return 0;
}