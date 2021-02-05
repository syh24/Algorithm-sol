/**
 *    author:  syh1
 *    created: 02.05.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;


const int Max_N = 2e5 + 1;
const int mod = 1e9 + 7;

vector<int> g[20001];
queue<int> q;
int v, e, n, m, tt;
int vst[20001];

bool bfs(int k) {
    vst[k] = 1;
    q.push(k);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto x : g[cur]) {
            if (!vst[x]) {
                vst[x] = (vst[cur] == 1 ? 2 : 1);
                q.push(x);
            }
            else if(vst[x] == vst[cur]){
                while (!q.empty()) q.pop();
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tt;
    while (tt--) {
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2; tmp1--; tmp2--;
            g[tmp1].push_back(tmp2);
            g[tmp2].push_back(tmp1);
        }
        bool flag = true;
        for (int i = 0; i < v; i++) {
            if (!vst[i]) {
                if (!bfs(i)) {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
        memset(vst, 0, sizeof(vst));
        memset(g, 0, sizeof(g));
    }
    return 0;
}