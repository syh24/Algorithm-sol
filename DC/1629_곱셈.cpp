/**
 *    author:  syh1
 *    created: 01.28.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;

const int MAXN = 4e7 +1;
const int mod = 1e9 + 7;

int N, K, M;

ll dc(ll a, ll b) {
    ll ret = 1;
    while (b > 0) {
        if (b % 2) {
            ret *= a;
            ret %= M;
        }
        a *= a;
        a %= M;
        b /= 2;
    }
    return ret;
}



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K >> M;
    ll x = dc(N, K);

    cout << x % M;
    
    return 0;
}