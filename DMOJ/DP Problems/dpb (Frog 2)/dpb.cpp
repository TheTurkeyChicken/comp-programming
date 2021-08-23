#include <iostream>
using namespace std;

int n, k, h[100001], dp[100001];

inline int abs(int a) {
	if(a < 0) return -a;
	return a;
}

void sol(int u) {
	if(u < 3 || dp[u] != -1) return;
	for(int i = 1; i < k; i++) {
		if(u - i < 3) break;
		sol(u - i);
	}
	dp[u] = 10000 * 100000;
	for(int i = 1; i <= k; i++) {
		if(u - i >= 1) dp[u] = min(abs(h[u - i] - h[u]) + dp[u - i], dp[u]);
	}
}

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
		dp[i] = -1;
	}
	dp[1] = 0; dp[2] = abs(h[1] - h[2]);
	sol(n);
	cout << dp[n];
	
//	cout << endl;
//	for(int i = 1; i <= n; i++) {
//		cout << dp[i] << endl;
//	}
}
