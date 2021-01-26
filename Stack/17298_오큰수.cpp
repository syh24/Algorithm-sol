/**
 *    author:  syh1
 *    created: 01.26.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;

const int MAXN = 1e6 +1;

int ar[MAXN];

stack<int> s;
stack<int> p;

int a[MAXN], N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    cin >> N;

    for (int i = 0; i < N; i++) {
        int m;
        cin >> m;
        s.push(m);
    }

    int j = 1;
    a[0] = -1;
    p.push(s.top());
    s.pop();
    while (!s.empty()) {
        
        if (s.top() >= p.top()) {

            while (true) {
                if (p.empty()) break;
                if (s.top() < p.top()) break;
                p.pop();
            }
            if (p.empty()) a[j] = -1;            
            else a[j] = p.top();
        }
        else {
            a[j] = p.top();
        }

        p.push(s.top());
        s.pop();
        j++;
    }
    for (int i = N - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

    return 0;
}