/**
 *    author:  syh1
 *    created: 03.05.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

vector<pii> t[10001];
queue<pii> q;
int v, a, b, c;
bool vst[10001];
int cnt[10001];

void bfs(int start) {

    vst[start] = true;
    q.push({ start, 0 });
    while (!q.empty()) {
        int x = q.front().first;
        int cost = q.front().second; q.pop();
        for (auto &k : t[x]) {
            int nx = k.first;
            int ncost = k.second;
            if (!vst[nx]) {
                cnt[nx] = cost + ncost;
                vst[nx] = true;
                q.push({ nx, cost + ncost });
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> v;
    // 트리 완성
    for (int i = 0; i < v-1; i++) {
        cin >> a >> b >> c; a--; b--;
        t[a].push_back({ b, c });
        t[b].push_back({ a,c });
    }
    bfs(0);
    int mx = -1;
    int tmp = 0;
    for (int i = 0; i < v; i++) {
        if (mx < cnt[i]) {
            tmp = i;
            mx = cnt[i];
        }
    }

    for (int i = 0; i < v; i++) vst[i] = false;
    memset(cnt, 0, sizeof(cnt));
    bfs(tmp);
    mx = -1;
    for (int i = 0; i < v; i++) mx = max(mx, cnt[i]);
    cout << mx;

    return 0;
}
           