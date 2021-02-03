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

int n, m;
bool vst[2][1001][1001];
int a[1001][1001];
int dx[] = { 0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };
int cnt[1001][1001];

class crash {
public:
    int nx;
    int ny;
    int crs = 0;
};

queue<crash> q;


int bfs() {
    //0,0에서 출발
    int crs =0;
    while (!q.empty()) {

        int x = q.front().nx;
        int y = q.front().ny;
        int u = q.front().crs;


        if (x == n - 1 && y == m - 1) {
            return cnt[x][y];
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            crs = u;
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (!vst[crs][nx][ny]) {
                    if (!crs && a[nx][ny] == 1) {
                        crs = 1;
                        vst[crs][nx][ny] = true;
                        cnt[nx][ny] = cnt[x][y] + 1;
                        q.push(crash{ nx,ny,crs });
                    }
                    else if(!a[nx][ny]){
                        vst[crs][nx][ny] = true;
                        cnt[nx][ny] = cnt[x][y] + 1;
                        q.push(crash{ nx,ny,crs });
                    }                   
                }
            }
        }
    }    
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    crash zz = { 0,0,0 };
    q.push(zz);
    vst[0][0][0] = true;
    vst[1][0][0] = true;
    cnt[0][0] = 1;
    cout << bfs();

    return 0;
}