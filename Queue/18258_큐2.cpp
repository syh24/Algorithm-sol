/**
 *    author:  syh1
 *    created: 01.27.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;

const int MAXN = 1e6 +1;


queue<int> q;

int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    cin >> N;
    string str;
    int a;
    while (N--) {
        cin >> str;
        
        if (str == "push") {
            cin >> a;
            q.push(a);
        }
        else if (str == "front") {
            if (q.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << q.front() << "\n";
        }
        else if (str == "back") {
            if (q.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << q.back() << "\n";
        }
        else if (str == "pop") {
            if (q.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }
        else if (str == "size") {
            cout << q.size() << "\n";
        }
        else {
            if (q.empty()) {
                cout << 1 << "\n";
                continue;
            }
            else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}