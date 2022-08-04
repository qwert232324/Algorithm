#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

queue<pair<int, int>> Q;
int board[101][101] = { 0, };
bool isVisit[101][101] = { false, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string temp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < M; j++) {
			board[i][j] = temp.at(j) - 48;
		}
	}

	isVisit[0][0] = true;
	Q.push({ 0,0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int a = cur.first + dy[i];
			int b = cur.second + dx[i];
			if (a >= 0 && b >= 0 && board[a][b] != 0 && !isVisit[a][b]) {
				Q.push({ a,b });
				board[a][b] += board[cur.first][cur.second];
				isVisit[a][b] = true;
			}
		}
	}

	cout << board[N-1][M-1];
}
