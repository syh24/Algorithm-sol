/**
 *    author:  syh1
 *    created: 01.24.2021
**/


#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;
using pdd = pair<double, ll>;

const int MAXN = 1e2 + 1;
const int MAXW = 1e6 + 3;
const int mod = 1e9 + 7;


double a[MAXN][2];
int N, W, dp[102][MAXW];

int main() {
	
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> W;
	int i = 0;

	//W is max weight
	//[0] is weight, [1] is value
	for (int i = 1; i <= N; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	

	//case i is not include : dp[i][j] = dp[i-1][j];
	//case i is include : dp[i][j] --> dp[i-1][j] or dp[i-1[j-w] + val;
	for (int i = 1; i <= N; i++) {
		int w = a[i][0], val = a[i][1];
		for (int j = 0; j <= W; j++) {

			if (j < a[i][0]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + val);

		}
	}

	cout << dp[N][W] << "\n";

	return 0;
}