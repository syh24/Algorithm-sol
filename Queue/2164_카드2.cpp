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


deque<int> q;

int N;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    cin >> N;
  
    for (int i = 1; i <= N; i++) {
        q.push_back(i);
    }

    while (true) {
        if (q.size() == 1) break;
        q.pop_front();
        if (q.size() == 1) break;
        int k = q.front();
        q.pop_front();
        q.push_back(k);
    }

    cout << q.front() << "\n";  
    return 0;
}