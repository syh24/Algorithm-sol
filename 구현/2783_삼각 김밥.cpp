/**
 *    author:  syh1
 *    created: 03.14.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;

float n, m;
vector<pii> v;


int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> n >> m;
    float min = n / m * 1000;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        float tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if ((tmp1 / tmp2) * 1000 < min) {
            min = (tmp1 / tmp2) * 1000;
        }
    }
    printf("%.2lf", min);

    return 0;
}
           