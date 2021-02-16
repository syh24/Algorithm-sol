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

int n;
pii p[MAXN];

void dp() {
    p[1] = { 0,0 };
    for (int i = 2; i <= n; i++) {
        p[i] = { p[i - 1].first + 1, i - 1 };
        if (i % 2 == 0) {
            if (p[i / 2].first + 1 < p[i].first) {
                p[i] = { p[i / 2].first + 1,i / 2 };
            }
        }
        if (i % 3 == 0) {
            if (p[i / 3].first + 1 < p[i].first) {
                p[i] = { p[i / 3].first + 1,i / 3 };
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dp();
    cout << p[n].first << "\n";
    cout << n << " ";
    int r = n;
    while (p[r].second != 0) {
        cout << p[r].second << " ";
        r = p[r].second;
    }
    return 0;
}