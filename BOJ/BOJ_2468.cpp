#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int board[100][100] = { 0, };
bool isVisit[100][100] = { false, };

int main() {

	queue<pair<int,int>> Q;
	int N, max = 0, cnt = 0, result =0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] > max) max = board[i][j];
		}
	}

	for (int n = 1; n <= max; n++) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] > n && !isVisit[i][j]) {
					Q.push({ i,j });
					isVisit[i][j] = true;
					while (!Q.empty()) {
						pair<int,int> p = Q.front();
						Q.pop();
						for (int k = 0; k < 4; k++) {
							int py = p.first + dy[k];
							int px = p.second + dx[k];
							if (py >= 0 && px >= 0 && py < N && px < N &&
								board[py][px] > n && !isVisit[py][px]) {
								Q.push({ py,px });
								isVisit[py][px] = true;
							}
						}
					}
					cnt++;
				}
			}
		}
		if (cnt > result) result = cnt;
		cnt = 0;
		memset(isVisit, false, sizeof(bool) * 100 * 100);
	}
	if (result == 0) result = 1;
	cout << result;
}