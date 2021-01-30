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
    

    priority_queue<int, vector<int>, less<int>> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    cin >> n;

    int a;
    //q1 is maxheap, q2 is minheap
    while(n--) {
        int sz1, sz2;
        cin >> a;

        if (q1.size() == q2.size()) q1.push(a);
        else q2.push(a);

        if (!q1.empty() && !q2.empty() && !(q1.top() <= q2.top())) {
            int x = q1.top();
            int y = q2.top();
            q1.pop();
            q2.pop();
            q1.push(y);
            q2.push(x);
        }
        cout << q1.top() << "\n";
    }
    return 0;
}