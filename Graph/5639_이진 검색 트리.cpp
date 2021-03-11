/**
 *    author:  syh1
 *    created: 03.11.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;

vector<pii> t[10001];
vector<int> v;
int n, k;
bool vst[10001];

void post(int start, int end) {
    if (start >= end) {
        cout << v[start] << "\n"; return;
    }
    int root = v[start];
    int cnt = 0;
    for (int i = start; i <= end; i++) {
        if (root < v[i]) cnt++;
    }
    int ls = end - start - cnt;
    int rs = cnt;

    if (ls != 0) {
        post(start + 1, start + ls);
    }
    if (cnt != 0) {
        post(end - cnt + 1, end);
    }
    cout << v[start] << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);

    while (cin >> k) {
        v.push_back(k);
    }

    post(0, v.size()-1);

    return 0;
}
           