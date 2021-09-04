#include <iostream>
using namespace std;

int n, w, val[101], wgt[101];
long long dp[2][100001];
 
int mod2(int a) {
	return ((a % 2) + 2) % 2;
}

int main() {
	cin >> n >> w;
	for(int i = 1; i <= n; i++) 
		cin >> wgt[i] >> val[i];
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= w; j++) {
			if(j >= wgt[i]) {
				dp[mod2(i)][j] = max(val[i] + dp[mod2(i - 1)][j - wgt[i]], dp[mod2(i - 1)][j]);
			}
			else dp[mod2(i)][j] = dp[mod2(i - 1)][j];
		}
	}
	cout << dp[mod2(n)][w];
}
