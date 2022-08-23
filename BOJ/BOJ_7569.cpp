#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int dy[6] = { 0,1,0,-1,0,0 };
int dx[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int board[100][100][100];
bool isVisit[100][100][100] = { false, };

int main() {

	int M, N, H;
	cin >> M >> N >> H;

	queue<tuple<int, int, int>> Q;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> board[j][k][i];
			}			
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (board[j][k][i] == 1 && !isVisit[j][k][i]) {
					Q.push({ j,k,i });
					isVisit[j][k][i] = true;
				}
			}
		}
	}
	while (!Q.empty()) {
		tuple<int, int, int> t = Q.front();
		int ty = get<0>(t);
		int tx = get<1>(t);
		int tz = get<2>(t);
		Q.pop();
		for (int l = 0; l < 6; l++) {
			int y = ty + dy[l];
			int x = tx + dx[l];
			int z = tz + dz[l];
			if (y >= 0 && x >= 0 && z >= 0 &&
				z < H && y < N && x < M &&
				!isVisit[y][x][z] && board[y][x][z] == 0) {
				Q.push({ y,x,z });
				isVisit[y][x][z] = true;
				board[y][x][z] = board[ty][tx][tz] + 1;
			}
		}
	}

	int max = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (board[j][k][i] == 0) {
					cout << "-1";
					return 0;
				}
				else if (board[j][k][i] > max) max = board[j][k][i];
			}			
		}
	}
	cout << max-1;
}