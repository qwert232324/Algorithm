#include<iostream>
#include<queue>

using namespace std;

int board[300][300] = { 0, };
int isVisit[300][300] = { false, };

int dy[8] = { 1,-1,1,-1,2,-2,2,-2 };
int dx[8] = { 2,2,-2,-2,1,1,-1,-1 };

int main() {

	int T;
	cin >> T;
	queue<pair<int, int>> Q;

	while (T != 0) {
		int l, sy, sx, ey, ex;
		cin >> l >> sy >> sx >> ey >> ex;

		Q.push({ sy,sx });
		isVisit[sy][sx] = true;
		while (!Q.empty()) {
			pair<int, int> p = Q.front();
			Q.pop();
			for (int i = 0; i < 8; i++) {
				int y = p.first + dy[i];
				int x = p.second + dx[i];
				if (y >= 0 && x >= 0 && y < l && x < l && !isVisit[y][x]) {
					Q.push({ y,x });
					isVisit[y][x] = true;
					board[y][x] = board[p.first][p.second] + 1;
				}
			}
		}
		cout << board[ey][ex] << endl;
		memset(board, 0, sizeof(board));
		memset(isVisit, false, sizeof(isVisit));
		T--;
	}
}