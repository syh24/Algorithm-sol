/**
 *    author:  syh1
 *    created: 02.08.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

#define INF 200000000000000000
const int MAXN = 1e5 + 1;
const int mod = 1e9 + 7;

int n, m, dp[101][101];
vector<pii> a[101];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3; t1--; t2--;
        a[t1].push_back(make_pair(t2, t3));
    }
    
    memset(dp, 0x3f, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (auto x : a[i]) {
            int cur = x.first;
            int cost = x.second;
            if (i == cur) continue;
            dp[i][cur] = min(dp[i][cur], cost);
        }
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j];
            }
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 0x3f3f3f3f) cout << 0 << " ";
            else cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}