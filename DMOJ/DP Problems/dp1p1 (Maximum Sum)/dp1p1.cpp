#include <iostream>
using namespace std;

int n, arr[100001], dp[100001];

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for(int i = 2; i <= n; i++) {
		dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
	}
	cout << dp[n];
}
