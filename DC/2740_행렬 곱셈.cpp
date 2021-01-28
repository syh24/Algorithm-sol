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

int n1, n2, m1, m2;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n1 >> m1;

    matrix a(n1, vector<ll>(m1));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cin >> a[i][j];
        }
    }

    cin >> n2 >> m2;

    matrix b(n2, vector<ll>(m2));
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            cin >> b[i][j];
        }
    }
    matrix c(n1, vector<ll>(m2));

    for (ll i = 0; i < n1; i++) {
        for (ll j = 0; j < m2; j++) {
            for (ll k = 0; k < m1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}