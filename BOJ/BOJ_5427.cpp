#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

char board[1000][1000] = { NULL, };
int distF[1000][1000] = { 0, };
int distS[1000][1000] = { 0, };

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int main() {

	int T, num = -1;
	cin >> T;
	queue<pair<int, int>> Q;

	while (T != 0) {
		int m, n;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '*') {
					Q.push({ i,j });
					distF[i][j] = 0;
				}
				else distF[i][j] = -1;
			}
		}
		while (!Q.empty()) {
			pair<int, int> p = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int y = p.first + dy[i];
				int x = p.second + dx[i];
				if (y >= 0 && x >= 0 && y < m && x < n && board[y][x] != '#' && distF[y][x] == -1) {
					Q.push({ y,x });
					distF[y][x] = distF[p.first][p.second] + 1;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '@') {
					Q.push({ i,j });
					distS[i][j] = 0;
				}
				else distS[i][j] = -1;
			}
		}
		while (!Q.empty()) {
			pair<int, int> p = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int y = p.first + dy[i];
				int x = p.second + dx[i];
				if (y < 0 || x < 0 || y >= m || x >= n) {
					num = distS[p.first][p.second] + 1;
				}
				else if (board[y][x] != '#' && distS[y][x] == -1 && (distF[y][x] > distS[p.first][p.second] + 1 || distF[y][x] == -1)) {
					Q.push({ y,x });
					distS[y][x] = distS[p.first][p.second] + 1;
				}
				if (num != -1) {
					while (!Q.empty()) Q.pop();
					i = 4;
				}
			}
		}
		if (num != -1) cout << num << endl;
		else cout << "IMPOSSIBLE" << endl;

		memset(board, NULL, sizeof(board));
		memset(distF, 0, sizeof(distF));
		memset(distS, 0, sizeof(distS));
		T--;
		num = -1;
	}
}