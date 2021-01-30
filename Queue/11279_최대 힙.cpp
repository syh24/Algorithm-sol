/**
 *    author:  syh1
 *    created: 01.30.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int Max_N = 1e5 + 1;
const int mod = 1e9 + 7;

int n;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    priority_queue<int> q;

    cin >> n;

    int a;
    while (n--) {
        cin >> a;
        if (!a) {
            if (q.empty()) cout << 0 << "\n";
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else {
            q.push(a);
        }
    }

    return 0;
}