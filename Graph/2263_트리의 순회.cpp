/**
 *    author:  syh1
 *    created: 03.10.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

vector<pii> t[10001];
queue<pii> q;
int v, n, in[MAXN], pre[MAXN], post[MAXN], idx[MAXN];
bool vst[10001];

void preOrder(int is, int ie, int ps, int pe) {
    if (is > ie || ps > pe) {
        return;
    }
    int r = post[pe];
    cout << r << " ";

    preOrder(is, idx[r] - 1, ps, ps + idx[r] - is - 1);

    preOrder(idx[r] + 1, ie, ps + idx[r] - is, pe - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> in[i];
        idx[in[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    preOrder(0, n - 1, 0, n - 1);

    return 0;
}
           