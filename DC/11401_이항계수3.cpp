/**
 *    author:  syh1
 *    created: 01.27.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;

const int MAXN = 4e7 +1;
const int mod = 1e9 + 7;

int N, K, dp[MAXN];

// divide&conquer
ll dc(ll x, ll y) {
    ll ret = 1;
    while (y > 0) {
        if (y % 2) {
            ret *= x;
            ret %= mod;
        }
        x *= x;
        x %= mod;
        y /= 2;
    }
    return ret;
}

//fermat's little theorem
ll bino(ll n, ll k) {
    ll nf = 1, a = 1;
    for (ll i = n; i >= 1; i--) {
        nf *= i;
        nf %= mod;
    }
    for (ll i = k; i >= 1; i--) {
        a *= i;
        a %= mod;
    }
    for (ll i = n - k; i >= 1; i--) {
        a *= i;
        a %= mod;
    }

    return (nf * dc(a, mod - 2)) % mod;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    cin >> N >> K;
    
    cout << bino(N, K);
    
    return 0;
}