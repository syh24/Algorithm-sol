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


int n, m, t, s, g, h,dmid, ddd;
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
    if (!f1) {
        f1 = true;
        if (dist[g] < dist[h]) {
            f2 = true;
            ddd = dist[g];
        }
        else {
            f3 = true;
            ddd = dist[h];
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T = 0; 
    cin >> T;
    while (T--) {
        f1 = false; f2 = false; f3 = false;
        int result = 0;
        cin >> n >> m >> t;
        cin >> s >> g >> h; s--; g--; h--;
        for (int i = 0; i < m; i++) {
            int a, b, d; 
            cin >> a >> b >> d; a--; b--;
            v[a].push_back(make_pair(b, d));
            v[b].push_back(make_pair(a, d));
            if ((a == g && b == h) || (a == h && b == g)) dmid = d;
        }
        for (int i = 0; i < t; i++) {
            int k;
            cin >> k; k--;
            p[i] = k;
        }
        sort(p, p + t);
        vector<int> dp1 = dij(s);
        if (f2) {
            vector<int> dp2 = dij(h);
            for (int i = 0; i < t; i++) {
                if (dp1[p[i]] >= ddd + dmid + dp2[p[i]]) cout << p[i] + 1 << " ";
            }
        }
        else if(f3){
            vector<int> dp2 = dij(g);
            for (int i = 0; i < t; i++) {
                if (dp1[p[i]] >= ddd + dmid + dp2[p[i]]) cout << p[i] + 1 << " ";
            }
        } 
        for (int i = 0; i < n; i++) v[i].clear();
    }
    return 0;
}