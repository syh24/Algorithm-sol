/**
 *    author:  syh1
 *    created: 03.14.2021
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;
using matrix = vector<vector<ll>>;

const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;

float n, m;
vector<pii> v;


int main() {
    ios_base::sync_with_stdio(false);

	v.resize(26);
	string s; cin >> s;
	for (int i = 0; i < 52; i++) {
		int now = s[i] - 'A';
		if (v[now].first == 0) v[now].first = i + 1;
		else v[now].second = i + 1;
	}

	int ans = 0;
	int n = 26;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int s1 = v[i].first;
			int e1 = v[i].second;
			int s2 = v[j].first;
			int e2 = v[j].second;
			if (s1 < s2 && s2 < e1 && e1 < e2) ans++;
		}
	}
	cout << ans;
    return 0;
}
           