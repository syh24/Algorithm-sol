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

int N, K, a[1001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    cin >> N >> K;
  
    for (int i = 1; i <= N; i++) {
        q.push_back(i);
    }

    int j = 0;
    while (true) {
        if (q.empty()) break;
        for (int i = 0; i < K-1; i++) {
            int x = q.front();
            q.pop_front();
            q.push_back(x);
        }
        a[j] = q.front();
        q.pop_front();
        j++;
    }

    cout << "<";
    for (int i = 0; i < N-1; i++) {
        cout << a[i] << ", ";
    }
    cout << a[N - 1] << ">";

    return 0;
}