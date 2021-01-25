/**
 *    author:  syh1
 *    created: 01.25.2021
**/


#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int MAXN = 1e3 + 1;

vector<int> v;
int N, W, K, ar[MAXN];



int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	
	ll ans = 0;
	
	cin >> N;


	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());


	for (int i = 0; i < N; i++) {
		ans += (ll)v[i] * (N - i);
	}


	cout << ans << "\n";

	return 0;
}