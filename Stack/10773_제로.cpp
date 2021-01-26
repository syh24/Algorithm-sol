/**
 *    author:  syh1
 *    created: 01.26.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;

const int MAXN = 2e5 + 1;


int N, K;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    stack<int> s;


    cin >> K;
    while (K--) {
        int a;
        cin >> a;
        
        if (a == 0) {
            s.pop();
            continue;
        }

        s.push(a);
    }
    ll ans = 0;
   
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }

    cout << ans << "\n";

    return 0;
}