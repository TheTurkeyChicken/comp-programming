#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Data {
	int r, c, hour;
}countries[3000];

int n, x, q, queries[1000000];
queue <Data> Q;

bool cmp(Data a, Data b) {return a.hour < b.hour;}

int getDist(Data a, Data b) {
	int dr = abs(a.r - b.r), dc = abs(a.c - b.c);
	return dr * dr + dc * dc;
}

void dijk() {
	for(int oi = x; oi < x + n; oi++) {
		int i = oi % n;
		for(int j = 0; j < n; j++) {
			int inft = getDist(countries[i], countries[j]) + countries[i].hour;
			if(inft < countries[j].hour) {
				countries[j].hour = inft;
			}
		}
	}
}

int bs(int target) {
	int l = 0, r = n - 1, m;
	while(l < r) {
		m = (l + r) / 2;
		if(countries[m].hour == target)
			m += 1;
		if(countries[m].hour > target)
			r = m - 1;
		else
			l = m + 1;
	}
	if(r <= l) {
		if(target >= countries[l].hour) return l + 1;
		return l;
	}
	return l;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> countries[i].c >> countries[i].r;
		countries[i].hour = INT_MAX;
	}	
	cin >> x; x -= 1;
	cin >> q;
	for(int i = 0; i < q; i++)
		cin >> queries[i];
	countries[x].hour = 0;
	dijk();
//	cout << "\n-----\n";
	sort(countries, countries + n, cmp);
	for(int i = 0; i < q; i++) {
		cout << bs(queries[i]) << '\n';
	}
//	for(int i = 0; i < n; i++) {
//		cout << '\n' << i << ": " << countries[i].r << ", " << countries[i].c << ", " << countries[i].hour; 
//	}
}
