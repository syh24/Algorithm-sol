/**
 *    author:  syh1
 *    created: 01.28.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;

const int MAXN = 4e7 +1;
const int mod = 1e9 + 7;

int N, K, M, a[2187][2187], pa1=0, pa2=0, pa3 =0;

void dc(int x, int y, int n){
    int p = 0, q =0,r = 0;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (a[i][j] == -1) p++;
            else if (!a[i][j]) q++;
            else r++;
        }
    }

    if (p == n * n) pa1++;  // full with -1
    else if (q == n * n) pa2++; // full with 0
    else if (r == n * n) pa3++; // full with 1
    else {
        dc(x, y, n / 3);
        dc(x, y + n / 3, n / 3);
        dc(x, y + n * 2 / 3, n / 3);
        dc(x + n / 3, y , n / 3);
        dc(x + n / 3, y + n / 3, n / 3);
        dc(x + n / 3, y + n * 2 / 3, n / 3);
        dc(x + n * 2 / 3, y, n / 3);
        dc(x + n * 2 / 3, y + n / 3, n / 3);
        dc(x + n * 2 / 3, y + n * 2 / 3, n / 3);
    }
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
    cout << pa1 << "\n" << pa2 << "\n" << pa3;
    return 0;
}