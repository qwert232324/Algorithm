#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int board[500][500] = { 0, };
bool isVisit[500][500] = { false, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int best = 0;
	int r = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && !isVisit[i][j]) {
				Q.push({ i,j });
				isVisit[i][j] = true;
				cnt++;
				r = 1;
			}
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int k = 0; k < 4; k++) {
					int cx = cur.first + dx[k];
					int cy = cur.second + dy[k];
					if (cx >= 0 && cy >= 0 && cx < n && cy < m &&
						board[cx][cy] == 1 && !isVisit[cx][cy]) {
						Q.push({ cx,cy });
						isVisit[cx][cy] = true;
						r++;
					}
				}
			}

			if (r > best) best = r;

		}
	}
	cout << cnt << endl << best;
}