#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

queue<pair<int, int>> Q;
queue<pair<int, int>> Q2;
char board[1001][1001] = { NULL, };
int FDist[1001][1001];
int JDist[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&FDist[0][0], &FDist[1000][1001], -1);
	fill(&JDist[0][0], &JDist[1000][1001], -1);

	int R, C;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				FDist[i][j] = 0;
				Q.push({ i,j });
			}
			if (board[i][j] == 'J') {
				JDist[i][j] = 0;
				Q2.push({ i,j });
			}
			
		}
	}

	while (!Q.empty()) {
		pair<int, int> num = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int y = num.first + dy[i];
			int x = num.second + dx[i];
			if (y >= 0 && x >= 0 && y < R && x < C && board[y][x] != '#' && FDist[y][x] == -1){
				Q.push({ y,x });
				FDist[y][x] = FDist[num.first][num.second] + 1;
			}
		}
	}


	while (!Q2.empty()) {
		pair<int, int> num = Q2.front();
		Q2.pop();
		for (int i = 0; i < 4; i++) {
			int y = num.first + dy[i];
			int x = num.second + dx[i];
			if (y < 0 || x < 0 || y >= R || x >= C) {
				cout << JDist[num.first][num.second] + 1;
				return 0;
			}
			if (JDist[y][x] == -1 && board[y][x] != '#' && (FDist[y][x] == -1 || FDist[y][x] > JDist[num.first][num.second] + 1))
			{
				Q2.push({ y,x });
				JDist[y][x] = JDist[num.first][num.second] + 1;
			}
		}
	}
	cout << "IMPOSSIBLE";
}
