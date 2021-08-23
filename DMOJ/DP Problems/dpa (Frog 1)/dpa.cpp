#include <iostream>
using namespace std;

int n, h[100001], dp[100001];

inline int abs(int a) {
	if(a < 0) return -a;
	return a;
}

void sol(int u) {
	if(u < 3 || dp[u] != -1) return;
	sol(u - 1); sol(u - 2);
	dp[u] = min(abs(h[u - 1] - h[u]) + dp[u - 1], abs(h[u - 2] - h[u]) + dp[u - 2]);
}

int main() {
	cin >> n;
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
