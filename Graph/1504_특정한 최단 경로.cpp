/**
 *    author:  syh1
 *    created: 02.06.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e5 + 1;
const int mod = 1e9 + 7;


int n, m, t, s, g, h, e;
vector<pii> v[2001];
priority_queue<pii, vector<pii>, greater<pii>> q;

int p[101], dist[2001];
bool f1, f2, f3;

vector<int> dij(int s) {
    vector<int> dist(n + 1, 0x3f3f3f3f);
    dist[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int cost = q.top().first;
        int cur = q.top().second;
        q.pop();
        for (auto k : v[cur]) {
            int ncost = k.second;
            int nx = k.first;
            if (dist[nx] > ncost + cost) {
                dist[nx] = ncost + cost;
                q.push(make_pair(dist[nx], nx));
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> e; n--;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    cin >> g >> h; g--; h--;
    bool f1 = false, f2 = false;
    vector<int> dp1 = dij(0);
    vector<int> dp2 = dij(g);
    vector<int> dp3 = dij(h);
    vector<int> dp4 = dij(0);
    vector<int> dp5 = dij(h);
    vector<int> dp6 = dij(g);
    if (dp1[g] < 0x3f3f3f3f && dp2[h] < 0x3f3f3f3f && dp3[n] < 0x3f3f3f3f) f1 = true;
    if (dp4[h] < 0x3f3f3f3f && dp5[g] < 0x3f3f3f3f && dp6[n] < 0x3f3f3f3f) f2 = true;
    if (f1 && f2) {
        cout << min(dp1[g] + dp2[h] + dp3[n], dp4[h] + dp5[g] + dp6[n]);
    }
    else if (f1) cout << dp1[g] + dp2[h] + dp3[n];
    else if (f2) cout << dp4[h] + dp5[g] + dp6[n];
    else cout << -1;
    return 0;
}