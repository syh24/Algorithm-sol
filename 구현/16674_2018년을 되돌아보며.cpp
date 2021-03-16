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

int n, a[10];


int main() {
    ios_base::sync_with_stdio(false);
    string s; bool f = false;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        int tmp = s[i] - '0';
        if (tmp != 0 && tmp != 1 && tmp != 2 && tmp != 8) {
            cout << 0; f = true;
            break;
        }
        a[tmp]++;        
    }
    if (!f) {
        if (a[0] == a[2] && a[0] == a[1] && a[0] == a[8]) cout << 8;
        else {
            if (a[0] > 0 && a[1] > 0 && a[2] > 0 && a[8] > 0) cout << 2;
            else cout << 1;
        }
    }
    return 0;
}
           