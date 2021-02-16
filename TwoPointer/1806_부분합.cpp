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

ll a[MAXN], n, x, s, pre[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            pre[x] = a[i];
        }
        else {
            pre[x] = pre[x - 1] + a[i];
        }
        x++;
    }
    int start = 0, end = 1;
    int mn = MAXN;
    bool f = false;
    while (end < n) {
        ll sum = (start == 0) ? pre[end] : pre[end] - pre[start - 1];
        if (sum < s) {
           end++;
        }
        else if (sum >= s) {
            f = true;
            mn = min(mn, end - start + 1);
            start++;
        }
    }
    if (!f) cout << 0;
    else cout << mn;
    return 0;
}