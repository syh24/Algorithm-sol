/**
 *    author:  syh1
 *    created: 03.04.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        if (m % n == 0) puts("factor");
        else if (n % m == 0) puts("multiple");
        else puts("neither");
    }
    return 0;
}
           