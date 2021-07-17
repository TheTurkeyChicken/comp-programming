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

void BFS() {
	while(!Q.empty()) {
		Data cur = Q.front(); Q.pop();
		if(cur.r == stop.r && cur.c == stop.c) {
			cout << cur.moves;
			return;
		}
		for(int i = 0; i < 8; i++) {
			Data tcur;
			tcur.r = cur.r + rmove[i];
			tcur.c = cur.c + cmove[i];
			tcur.moves = cur.moves + 1;
			if(!vist[tcur.r][tcur.c])
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
