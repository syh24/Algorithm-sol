/**
 *    author:  syh1
 *    created: 01.25.2021
**/
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair < ll, ll> ;

const int MAXN = 1e3 + 1;


bool negative = false;
char ch;


int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(0);
	int sum = 0;
	scanf("%d", &sum);

	int nx;
	while (true) {
		scanf("%c", &ch);
		scanf("%d", &nx);


		if (ch == '-') negative = true;
		else if (ch != '+')	break;
		
		if (negative) sum -= nx;
		else sum += nx;

	}
	cout << sum << "\n";

	return 0;
}