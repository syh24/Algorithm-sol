/**
 *    author:  syh1
 *    created: 01.28.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int mod = 1e9 + 7;
const int p = 1000;

ll N, B;

matrix operator * (const matrix& a, const matrix& b) {
    ll size = a.size();
    matrix ret(size, vector<ll>(size));
    for (ll i = 0; i < size; i++) {
        for (ll j = 0; j < size; j++) {
            for (ll k = 0; k < size; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= mod;
        }
    }
    return ret;
}



matrix dc(matrix a, ll b) {
    ll size = a.size();
    matrix ret(size, vector<ll>(size));

    for (ll i = 0; i < size; i++) {
        ret[i][i] = 1;
    }

    while (b > 0) {
        if (b % 2) {
            ret = ret * a;
        }
        a = a * a;
        b /= 2;
    }
    return ret;
}



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    matrix a = { {1,1},{1,0} };

    matrix c = dc(a, N-1);

    cout << (c[1][0] + c[1][1]) % mod;
    

    return 0;
}