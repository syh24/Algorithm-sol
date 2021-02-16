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

const int MAXN = 1e5 + 1;
const int mod = 1e9 + 7;

ll a[MAXN], n, x, ph = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    int start = 0, end = n-1;
    int r1 = 0, r2 = 0;
    while (start < end) {

        if (a[start] + a[end] == 0) {
            r1 = a[start];
            r2 = a[end];
            break;
        }

        if (a[start] + a[end] > 0) {
            if (abs(a[start] + a[end]) < ph) {
                r1 = a[start];
                r2 = a[end];
                ph = abs(a[start] + a[end]);
            }
            end--;
        }
        else if (a[start] + a[end] < 0) {
            if (abs(a[start] + a[end]) < ph) {
                r1 = a[start];
                r2 = a[end];
                ph = abs(a[start] + a[end]);
            }
            start++;
        }
    }
    cout << r1 << " " << r2;
    return 0;
}