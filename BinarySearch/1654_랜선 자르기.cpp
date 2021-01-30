/**
 *    author:  syh1
 *    created: 01.30.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int Max_N = 1e6 + 1;
const int mod = 1e9 + 7;

ll a[Max_N], n, m, k;
ll mx = 0;

bool ps(ll len) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += a[i] / len;
    }

    if (cnt >= k) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll pa = 0;
    ll left = 1;
    ll right = 0;
    ll mid = 0;
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        right = max(right, a[i]);
    }

    while (left <= right) {
        mid = (left + right) / 2;
        if (ps(mid)) {
            if (pa < mid) pa = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    
    cout << pa;

    return 0;
}