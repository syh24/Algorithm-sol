/**
 *    author:  syh1
 *    created: 02.16.2021
**/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e5 + 1;
const int mod = 1e9 + 7;

bool vst[301][301];
int n, m;
int a[301][301];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
priority_queue<pair<int, pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> q;
void sol(int x2, int y2) {
    
    while (!q.empty()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        int cnt = q.top().first;
        //cout << cnt;
        q.pop();
        if (x == x2 && y == y2) {
            cout << cnt + 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 1 && !vst[nx][ny]) {
                    q.push(make_pair(cnt+1, make_pair(nx, ny)));
                    a[nx][ny] = 0;
                    vst[nx][ny] = true;
                }
                else if (!vst[nx][ny] && a[nx][ny] == 0) {
                    q.push(make_pair(cnt, make_pair(nx, ny)));
                    vst[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x1, x2, y1, y2;
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char k; cin >> k;
            if (k == '#') a[i][j] = 0;
            else a[i][j] = k - '0';
        }
    }
    q.push(make_pair(0, make_pair(x1,y1)));
    vst[x1][y1] = true;
    sol(x2, y2);
    return 0;
}