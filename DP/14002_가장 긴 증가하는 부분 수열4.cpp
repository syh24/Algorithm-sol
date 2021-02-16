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

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

int n, dp[1001][2], a[1001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int k = 0, s = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] < a[j] && dp[i][0] == dp[j][0]) {
                dp[j][0] = dp[i][0] + 1;
                dp[j][1] = i;
                if (k < dp[j][0]) {
                    k = dp[j][0];
                    s = j;
                }
            }
        }
    }
    vector<int> v;
    cout << k + 1 << "\n";
    v.push_back(a[s]);
    while (true) {
        if (!dp[s][0]) break;
        v.push_back(a[dp[s][1]]);
        s = dp[s][1];
    }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
    return 0;
}