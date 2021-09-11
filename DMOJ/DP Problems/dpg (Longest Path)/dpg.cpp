#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, longest[100001];
vector<int> adj[100001];

void addEdge(int u, int v) {
	adj[u].push_back(v);
}

void dfs(int u) {
	if(longest[u] != -1) return;
	longest[u] = 0;
	for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
		dfs(*it);
		longest[u] = max(longest[u], longest[*it] + 1);
	}
}

int main() {
	int x, y, ans = 0;
	cin >> n >> m;
	for(int i = 0; i <= n; i++) longest[i] = -1;
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		addEdge(x, y);
	}
	for(int i = 1; i <= n; i++) {
		dfs(i);
	}
	for(int i = 1; i <= n; i++) {
		ans = max(ans, longest[i]);
	}
	cout << ans;
//	cout << endl;
//	for(int i = 1; i <= n; i++) cout << i << ": " << longest[i] << '\n';
}
// The reason why the code does not run on N^2 (or MN) time is because for every iteration fo the loop on line 30, the dfs would not run if a node already has its current max length computed
