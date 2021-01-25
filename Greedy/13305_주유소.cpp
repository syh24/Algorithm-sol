/**
 *    author:  syh1
 *    created: 01.25.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll>;

const int MAXN = 1e5 + 1;

ll dist[MAXN], price[MAXN], N, sum, greedy;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	
	cin >> N;

	for (int i = 1; i <= N - 1; i++)
		cin >> dist[i];

	for (int i = 1; i <= N; i++)
		cin >> price[i];

	greedy = MAXN;

	for (int i = 1; i <= N - 1; i++)
	{
		if (price[i] < greedy)
			greedy = price[i];
		sum += greedy * dist[i];
	}

	cout << sum;

	return 0;
}