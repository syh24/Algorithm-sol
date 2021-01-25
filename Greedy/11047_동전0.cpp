/**
 *    author:  syh1
 *    created: 01.25.2021
**/


#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;


const int MAXN = 1e9 + 1;
const int mod = 1e9 + 7;


int N, W, K, ar[10];

int main() {
	
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> ar[i];
	}

	int cnt = 0;
	for(int i = N - 1; i >= 0; i--) {

		if (ar[i] > K) continue;
		while (K / ar[i]) {
			cnt++;
			K -= ar[i];
		}
	}
	cout << cnt << "\n";


	return 0;
}