/**
 *    author:  syh1
 *    created: 02.23.2021
**/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

int n, a[MAXN];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    v.push_back(INT_MIN);
    int k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (v.back() < k) {
            v.push_back(k);
            cnt++;
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), k) - v.begin();
            v[idx] = k;
        }
    }
    cout << cnt;
    return 0;
}