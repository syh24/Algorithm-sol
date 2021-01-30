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

const int Max_N = 1e7 + 1;
const int mod = 1e9 + 7;

ll a[Max_N], n, m;

bool ps(ll len) {
    int cnt = 0;
    for (int i=1, j=0; i < n; i++) {
        if ((a[i] - a[j]) >= len) {
            cnt++;
            j = i;
     }
    }

    if (cnt >= m-1) return true;
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
   
    cin >> n >> m;
    ll left = 1, right = 0, mid;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        right = max(right, a[i]);
    }
    sort(a, a + n);
    ll res = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (ps(mid)) {
            if (res < mid) res = mid;
            left = mid + 1;
        }
        else right = mid-1;
    }
    
    cout << res << "\n";
    return 0;
}