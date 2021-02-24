/**
 *    author:  syh1
 *    created: 02.24.2021
**/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;
int n, m, a[100][100];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1,0,-1,0 };


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    int re = (m <= n) ? (m-1) * 2 : (n-1) * 2 + 1;
    cout << re;
    return 0;
}