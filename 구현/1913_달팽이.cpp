/**
 *    author:  syh1
 *    created: 02.24.2021
**/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;
int n, m, a[1000][1000];

void sol() {
    int tmp = 1;
    int nx = n / 2, ny = n / 2;
    a[nx][ny] = 1;
    int cnt = 1;

    while (true) {
        if (tmp == n) break;
        tmp += 2;

        a[--nx][ny] = ++cnt;
        for (int i = 0; i < tmp - 2; i++) {
            a[nx][++ny] = ++cnt;
        }
        for (int i = 0; i < tmp - 1; i++) {
            a[++nx][ny] = ++cnt;
        }
        for (int i = 0; i < tmp - 1; i++) {
            a[nx][--ny] = ++cnt;
        }
        for (int i = 0; i < tmp - 1; i++) {
            a[--nx][ny] = ++cnt;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    sol();

    int t1 = 0, t2 = 0;

    for (int i = 0; i < n; i++) {
        for(int j=0;j<n;j++){
            if (a[i][j] == m) {
                t1 = i;
                t2 = j;
            }
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << t1+1 << " " << t2+1;

    return 0;
}