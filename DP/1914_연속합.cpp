/**
 *    author:  syh1
 *    created: 01.24.2021
**/


#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int MAXN = 1e2 + 1;
const int mod = 1e9 + 7;


int dp[MAXN];

int t, mx;
int ar[MAXN];

int main() {

	cin >> t;
	int i = 0;
	
	for (int i = 0; i < t; ++i) {
		cin >> ar[i];
		dp[i] = ar[i];
	}
	mx = dp[0];
	for (int i = 1; i < t; i++) {
		dp[i] = max(dp[i], dp[i - 1] + ar[i]);
		if (dp[i] > mx) mx = dp[i];
	}

	cout << mx << "\n";
	return 0;
}