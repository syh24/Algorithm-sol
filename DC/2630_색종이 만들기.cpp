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

int N, K, a[128][128], w =0 , b=0;

void dc(int x, int y, int N) {
    

    int cnt = 0;
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (a[i][j]) {
                cnt++;
            }
        }
    }
    if (!cnt) w++;
    else if (cnt == N * N) b++;
    else {
        dc(x, y, N / 2);
        dc(x, y + N / 2, N / 2);
        dc(x + N / 2, y, N / 2);
        dc(x + N / 2, y+ N / 2, N / 2);
    }
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    
    dc(0, 0, N);
    cout << w << "\n" << b;
    return 0;
}