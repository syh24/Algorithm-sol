/**
 *    author:  syh1
 *    created: 01.29.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int Max_N = 1e6 + 1;
const int mod = 1e9 + 7;

int a[Max_N], n, m;

void binary_search(int k) {
    bool flag = false;
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (k > a[mid]) {
            left = mid + 1;
        }
        else if (k < a[mid]) {
            right = mid - 1;
        }
        else {
            flag = true;
            break;
        }
    }
    if (flag) cout << 1 << "\n";
    else cout << 0 << "\n";  
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        binary_search(x);
    }

    return 0;
}