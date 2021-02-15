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

int a, b;
queue<int> q;
int cnt[MAXN], dist[MAXN];
bool vst[MAXN];

void sol() {  
    int res = 0; bool f = false;
    int c = 0;
    vst[a] = true;
    cnt[a] = 1;
    q.push(a);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int nx : {cur - 1, cur + 1, cur * 2}) {
            if (nx >= 0 && nx <= MAXN - 1) {
                if (!vst[nx]) {
                    vst[nx] = true;
                    dist[nx] = dist[cur] + 1;
                    q.push(nx);
                    cnt[nx] = cnt[cur];
                }
                else if (dist[nx] == dist[cur] + 1) {
                    cnt[nx] += cnt[cur];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    sol();
    cout << dist[b] << "\n" << cnt[b];
    return 0;
}