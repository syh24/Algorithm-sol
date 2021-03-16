/**
 *    author:  syh1
 *    created: 03.16.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;

int n, k, a[1001];


int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        set<int> s;
        int r1 = 0;
        pii p = { 10, 0 };
        int best = 0;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int tmp; cin >> tmp;
            s.insert(tmp);
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            if (y == -1 && z == -1) continue;
            if (s.count(x) == 1) {
                if (y < 6 || (y == 6 && z == 0)) r1++;
                if (y < p.first || (y == p.first && z < p.second)) {
                    best = x;
                    p.first = y; p.second = z;
                }
            }
        }
        cout << best << " " << r1 << "\n";
    }
    return 0;
}
           