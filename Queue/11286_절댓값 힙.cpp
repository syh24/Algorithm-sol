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



// function oprator overloading
struct T {
    int val;
    bool operator()(T x, T y) {
        if (abs(x.val) == abs(y.val)) return x.val > y.val;
        return abs(x.val) > abs(y.val);
    }
};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    priority_queue<T, vector<T>, T> q;

    cin >> n;

    T a;

    while (n--) {
        cin >> a.val;
        if (!a.val) {
            if (q.empty()) cout << 0 << "\n";
            else {
                cout << q.top().val << "\n";
                q.pop();
            }
        }
        else {
            q.push(a);
        }
    }

    return 0;
}