#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;

int dy[6] = { 0,1,0,-1,0,0 };
int dx[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

char board[30][30][30] = { NULL, };
int dist[30][30][30] = { 0, };


queue<tuple<int, int, int>> Q;
int L = -1, R = -1, C = -1, result = -1;


int BFS() {
	while (!Q.empty()) {
		tuple<int, int, int> t = Q.front();
		int tz = get<0>(t);
		int ty = get<1>(t);
		int tx = get<2>(t);
		Q.pop();
		for (int i = 0; i < 6; i++) {
			int z = tz + dz[i];
			int y = ty + dy[i];
			int x = tx + dx[i];
			if (board[z][y][x] == 'E') {
				return dist[tz][ty][tx] + 1;
			}
			if (z >= 0 && y >= 0 && x >= 0 && z < L && y < R && x < C &&
				dist[z][y][x] == -1 && board[z][y][x] != '#') {
				Q.push({ z,y,x });
				dist[z][y][x] = dist[tz][ty][tx] + 1;
			}
		}
	}
	return -1;
}



int main() {
	
	cin >> L >> R >> C;
	while (!(L == 0 && R == 0 && C == 0)) {			

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						Q.push({ i,j,k });
						dist[i][j][k] = 0;
					}
					else dist[i][j][k] = -1;
				}
			}
		}		
		int result = BFS();
		if (result != -1) cout << "Escaped in " << result << " minute(s)." << endl;
		else cout << "Trapped!" << endl;
		
		result = -1;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					board[i][j][k] = NULL;
					dist[i][j][k] = 0;
				}
			}
		}
		while (!Q.empty()) Q.pop();
		cin >> L >> R >> C;
	}
	

}