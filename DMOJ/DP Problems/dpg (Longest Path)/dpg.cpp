#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, longest[100000];
vector<int> adj[100000];

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
	int x, y;
	cin >> n >> m;
	for(int i = 0; i < n; i++) longest[i] = -1;
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		addEdge(x, y);
	}
//	dfs(3);
	for(int i = 0; i < n; i++) {
		dfs(i);
	}
	cout << endl;
//	sort(longest, longest + n);
//	cout << longest[n - 1];
	cout << endl;
	for(int i = 0; i < n; i++) cout << longest[i] << '\n';
}
