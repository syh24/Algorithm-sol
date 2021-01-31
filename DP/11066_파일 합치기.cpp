/**
 *    author:  syh1
 *    created: 01.31.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int Max_N = 1e5 + 1;
const int mod = 1e9 + 7;

int n, tt, a[501], d[501][501], sum[501];


int dc(int start, int end) {
    
    // 이미 저장되어 있는 경우
    if (d[start][end] != 0x3f3f3f3f) return d[start][end];
    // 페이지가 1개인 경우
    if (start == end) return d[start][end] = 0;
    // 1차이인 경우
    if (start + 1 == end) return d[start][end] = a[start] + a[end];
    int ret = sum[end] - sum[start - 1];
    for (int i = start; i < end; i++) {
        int left = dc(start, i);
        int right = dc(i+1, end);
        d[start][end] = min(d[start][end], left + right);
    }
    return d[start][end] += ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> tt;
    while (tt--) {
        memset(d, 0x3f, sizeof(d));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i-1] + a[i];
        }
        cout << dc(1, n) << "\n";        
    }
    
    return 0;
}