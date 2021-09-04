#include <iostream>
#include <string>
using namespace std;

int dp[3001][3001];
string s, t, ans = "";

int main() {
	cin >> s >> t;
	for(int i = 1; i <= s.size(); i++) {
		for(int j = 1; j <= t.size(); j++) {
			if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int i = s.size(), j = t.size();
	while(i > 0 && j > 0) {
		if(s[i - 1] == t[j - 1]) {
			ans = s[i - 1] + ans;
			i--; j--;
		}
		else if(dp[i - 1][j] > dp[i][j - 1]) i--;
		else j--;
	}
	cout << ans;
}
