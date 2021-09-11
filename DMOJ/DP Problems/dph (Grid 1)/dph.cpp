#include <iostream>
using namespace std;

int h, w, dp[1001][1001];
char arr[1001][1001];

int main() {
	cin >> h >> w;
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) cin >> arr[i][j];
	}
	dp[1][1] = 1;
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			if(arr[i][j] == '.') {
				dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % (1000000007);
			}
		}
	}
	cout << dp[h][w];
//	cout << endl;
//	for(int i = 1; i <= h; i++) {
//		cout << '\n';
//		for(int j = 1; j <= w; j++) {
//			cout << dp[i][j];
//		}
//	}
}
