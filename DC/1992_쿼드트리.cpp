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

int N, K, ar[64][64];

void dc(int x, int y, int N) {
   
    int cnt = 0;

    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (ar[i][j]) {
                cnt++;
            }
        }
    }
    
    if (!cnt) cout << 0;
    else if (cnt == N * N) cout << 1;
    else {
        cout << "(";
        dc(x, y, N / 2);    //left up
        dc(x, y + N / 2, N / 2);   //left down
        dc(x + N / 2, y, N / 2);    //right up
        dc(x + N / 2, y + N / 2, N / 2); // right down
        cout << ")";
    }
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    cin >> N;

    char a;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a;
            ar[i][j] = a - '0';
        }
    }
    
    dc(0, 0, N);
    cout << "\n";
    return 0;
}