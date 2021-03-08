/**
 *    author:  syh1
 *    created: 03.07.2021
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
int v, n;
bool vst[10001];
int cnt[10001];

void preOrder(int x) {

    cout << (char)(x + 'A');
    if (t[x][0].first != '.') {
        preOrder(t[x][0].first);
    }
    if (t[x][0].second != '.') {
        preOrder(t[x][0].second);
    }
}

void inOrder(int x) {
    
    if (t[x][0].first != '.') {
        inOrder(t[x][0].first);
    }
    cout << (char)(x + 'A');
    if (t[x][0].second != '.') {
        inOrder(t[x][0].second);
    }
}

void postOrder(int x) {
    if (t[x][0].first != '.') {
        postOrder(t[x][0].first);
    }
    if (t[x][0].second != '.') {
        postOrder(t[x][0].second);
    }
    cout << (char)(x + 'A');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char ch,left, right; cin >> ch;
        cin >> left >> right;
        left = (left != '.') ? left - 'A' : '.';
        right = (right != '.') ? right - 'A' : '.';
        t[ch - 'A'].push_back({ left, right});
    }

    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);
    return 0;
}
           