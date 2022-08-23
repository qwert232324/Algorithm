#include<iostream>
#include<queue>
using namespace std;

int dy[4] = { 0,1, 0,-1 };
int dx[4] = { 1,0,-1,0 };

char board[100][100];
bool isVisit[100][100] = { false, };
bool isVisit2[100][100] = { false, };

int main() {

	int N, cnt = 0, cnt2 = 0;
	cin >> N;

	queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isVisit[i][j]) {
				Q.push({ i,j });
				isVisit[i][j] = true;
				while (!Q.empty()) {
					pair<int, int> p = Q.front();
					int py = p.first;
					int px = p.second;
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int y = py + dy[k];
						int x = px + dx[k];
						if (y >= 0 && x >= 0 && y < 100 && x < 100 && board[y][x] == board[py][px] && !isVisit[y][x]) {
							Q.push({ y,x });
							isVisit[y][x] = true;
						}
					}
				}
				cnt++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'R') board[i][j] = 'G';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isVisit2[i][j]) {
				Q.push({ i,j });
				isVisit[i][j] = true;
				while (!Q.empty()) {
					pair<int, int> p = Q.front();
					int py = p.first;
					int px = p.second;
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int y = py + dy[k];
						int x = px + dx[k];
						if (y >= 0 && x >= 0 && y < 100 && x < 100 && board[y][x] == board[py][px] && !isVisit2[y][x]) {
							Q.push({ y,x });
							isVisit2[y][x] = true;
						}
					}
				}
				cnt2++;
			}
		}
	}
	cout << cnt << ' ' << cnt2;
}