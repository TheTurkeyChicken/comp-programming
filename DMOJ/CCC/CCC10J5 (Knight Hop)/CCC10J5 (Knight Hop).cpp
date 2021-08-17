#include <iostream>
#include <queue>
using namespace std;

struct Data {
	int r, c, moves;
}start, stop;

queue <Data> Q;
int arr[8][8];
bool vist[8][8];
int rmove[] = {1, 2, 2, 1, -1, -2, -2, -1};
int cmove[] = {2, 1, -1, -2, -2, -1, 1, 2};

inline bool isValid(Data rc) {
	if(rc.r >= 0 && rc.r < 8 && rc.c >= 0 && rc.c < 8 && !vist[rc.r][rc.c])
		return 1;
	return 0;
}

void BFS() {
	while(!Q.empty()) {
		Data cur = Q.front(); Q.pop();
		vist[cur.r][cur.c] = 1;
		if(cur.r == stop.r && cur.c == stop.c) {
			cout << cur.moves;
			return;
		}
		for(int i = 0; i < 8; i++) {
			Data tcur;
			tcur.r = cur.r + rmove[i];
			tcur.c = cur.c + cmove[i];
			tcur.moves = cur.moves + 1;
			if(isValid(tcur))
				Q.push(tcur);
		}
	}
}

int main() {
	cin >> start.r >> start.c >> stop.r >> stop.c;
	Q.push(start);
	vist[start.r][start.c] = true;
	BFS();
	return 0;
}
