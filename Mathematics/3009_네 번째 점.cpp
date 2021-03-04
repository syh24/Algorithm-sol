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

    //xor 연산 사용
    int x = 0, y = 0;
    for (int i = 0; i < 3; i++) {
        cin >> n >> m;
        x ^= n;
        y ^= m;
    }
    cout << x << " " << y;
    return 0;
}
           