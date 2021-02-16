/**
 *    author:  syh1
 *    created: 02.16.2021
**/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 2e6 + 1;
const int mod = 1e9 + 7;

int a[MAXN], n, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    sort(a, a + n);
    int start = 0, end = n-1;
    
    int cnt = 0;
    while (start < end) {
        if (a[start] + a[end] > x) end--;
        else if (a[start] + a[end] < x) start++;
        else if (a[start] + a[end] == x) {
            end--;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}