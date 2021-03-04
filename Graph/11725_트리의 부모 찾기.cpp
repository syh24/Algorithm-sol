/**
 *    author:  syh1
 *    created: 03.04.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;

vector<int> tree[MAXN];
int n, m;
bool vst[MAXN];
int parent[MAXN];

void dfs(int x) {
    vst[x] = true;

    for (int i = 0; i < tree[x].size(); i++) {
        int nx = tree[x][i];
        if (!vst[nx]) {
            parent[nx] = x;
            dfs(nx);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tree[tmp1].push_back(tmp2);
        tree[tmp2].push_back(tmp1);
    }

    dfs(1);
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}
           