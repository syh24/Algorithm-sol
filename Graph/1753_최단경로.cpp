/**
 *    author:  syh1
 *    created: 02.05.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int Max_N = 2e4 + 1;
const int mod = 1e9 + 7;

vector<pii> g[20001];
int v, e, n, m, tt;
int dist[20001],s;
priority_queue<pii,vector<pii>,greater<pii>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int ds = 0;
    cin >> v >> e;
    cin >> s; s--;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < e; i++) {
        int x, y, z;
        cin >> x >> y >> z; x--; y--;
        g[x].push_back(make_pair(y, z));
    }
    q.push(make_pair(0, s));
    dist[s] = 0;
    while (!q.empty()) {
        //현재 점의 위치와 비용
        int cost = q.top().first;
        int cur = q.top().second; q.pop();
        //연결된 vertex 탐색
        for (auto k : g[cur]) {
            int nx = k.first;
            int nc = k.second;
            //비용이 더 작으면 갱신
            if (dist[nx] > cost + nc) {
                dist[nx] = cost + nc;
                q.push(make_pair(dist[nx], nx));
            }
        }
    }
    for (int i = 0; i < v; i++) {
        if (dist[i] == 0x3f3f3f3f) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}