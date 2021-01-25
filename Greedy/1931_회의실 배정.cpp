/**
 *    author:  syh1
 *    created: 01.25.2021
**/


#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long, long>;

const int MAXN = 1e6 + 1;
const int mod = 1e9 + 7;



vector<pii> v;
int N, W, K, ar[10];


//if end time is same sort the fast start time
int cmp(const pii &a, const pii &b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}


int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	
	int ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	int end = -1;
	for (int i = 0; i < N; i++) {
		if (v[i].first >= end) {
			ans++;
			end = v[i].second;
		}
	}
	cout << ans << "\n";

	return 0;
}