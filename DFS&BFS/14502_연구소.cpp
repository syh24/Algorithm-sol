/**
 *    author:  syh1
 *    created: 02.15.2021
**/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e5 + 1;
const int mod = 1e9 + 7;

int ar[8][8];
int n, m, res;
vector<pii> v;
bool vst[8][8];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int sol() {  
    int tmp[8][8];
    queue<pii> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) tmp[i][j] = ar[i][j];
    for (int i = 0; i < v.size(); i++) {
        q.push({ v[i].first, v[i].second });
    }
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (tmp[nx][ny] == 0) {
                    tmp[nx][ny] = 2;
                    q.push({ nx,ny });
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void dfs(int depth) {

    if (depth == 3) {
        res = max(res, sol());
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ar[i][j] == 0) {
                ar[i][j] = 1;
                dfs(depth + 1);
                ar[i][j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ar[i][j];
            if (ar[i][j] == 1) vst[i][j] = true;
            if (ar[i][j] == 2) {
                v.push_back({ i, j });
            }
        }
    }
    dfs(0);
    cout << res;
    return 0;
}