/**
 *    author:  syh1
 *    created: 02.02.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int Max_N = 2e5 + 1;
const int mod = 1e9 + 7;

int n, m;
int vst[100001];
int cnt[100001];

queue<int> q;

void bfs() {

    while (!q.empty()) {
        int k = q.front();       
        if (k == m) break;
        q.pop();
        if (k - 1 >= 0 && !vst[k - 1]) {
            q.push(k - 1);
            vst[k - 1] = true;
            cnt[k - 1] = cnt[k] + 1;
        }
        if (k + 1 < 100001 && !vst[k + 1]) {
            q.push(k + 1);
            vst[k + 1] = true;
            cnt[k + 1] = cnt[k] + 1;
        }
        if (k * 2 < 100001 && !vst[k * 2]) {
            q.push(k * 2);
            vst[k * 2] = true;
            cnt[k * 2] = cnt[k] + 1;
        }
    }
    cout << cnt[m]-1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    q.push(n);
    vst[n] = true;
    cnt[n] = 1;
    bfs();
    return 0;
}