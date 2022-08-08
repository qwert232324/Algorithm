#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

queue<pair<int, int>> Q;
int board[1001][1001] = { 0, };
bool isVisit[1001][1001] = { false, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && !isVisit[i][j]) {
				Q.push({ i,j });
				isVisit[i][j] = true;
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int> num = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int y = num.first + dy[i];
			int x = num.second + dx[i];
			if (y >= 0 && x >= 0 && y < N&& x < M && !isVisit[y][x] && board[y][x] != -1) {
				Q.push({ y,x });
				isVisit[y][x] = true;
				board[y][x] = board[num.first][num.second] + 1;
			}
		}
	}

	int max = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			else if (board[i][j] > max) max = board[i][j];
		}
	}

	cout << max;
}
