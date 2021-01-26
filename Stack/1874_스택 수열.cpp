/**
 *    author:  syh1
 *    created: 01.26.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;

const int MAXN = 1e5 +1;

int ar[MAXN];

stack<int> s;
vector<char> v;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0); 


    int n, i, j = 0;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (i = 1; i <= n; i++) {
        s.push(i);
        v.push_back('+');

        while (!s.empty() && s.top() == ar[j]) {
            s.pop();
            v.push_back('-');
            j++;
        }
    }
    
    if (!s.empty()) cout << "NO" << "\n";
    else {
        for (i = 0; i < v.size(); i++) {
            cout << v[i] << endl;
        }
    }
  

    return 0;
}