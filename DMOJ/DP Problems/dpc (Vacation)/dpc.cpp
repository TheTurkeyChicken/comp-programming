#include <iostream>
using namespace std;

const int MAX = 1e5 + 1;
int n, a[MAX], b[MAX], c[MAX], dpa[MAX], dpb[MAX], dpc[MAX];

void dp(int u) {
	if(u == 0) return;
	dp(u - 1);
	dpa[u] = a[u] + max(dpb[u - 1], dpc[u - 1]);
	dpb[u] = b[u] + max(dpa[u - 1], dpc[u - 1]);
	dpc[u] = c[u] + max(dpa[u - 1], dpb[u - 1]);
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	dp(n);
	cout << max(dpa[n], max(dpb[n], dpc[n]));
	
//	cout << endl;
//	for(int i = 1; i <= n; i++) {
//		cout << dpa[i] << '\t' << dpb[i] << '\t' << dpc[i] << '\n';
//	}
}
