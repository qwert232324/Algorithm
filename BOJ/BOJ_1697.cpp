#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int dist[100001];;
queue<int> Q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(dist, dist + 100001, -1);

	int N, M;
	cin >> N >> M;
	Q.push(N);
	dist[N] = 0;

	while (!Q.empty()) {
		int num = Q.front();
		Q.pop();
		if (num == M) {
			cout << dist[num];
			return 0;
		}
		if (dist[num - 1]==-1) {
			Q.push(num - 1);
			dist[num - 1] = dist[num] + 1;
		}
		if (dist[num + 1] == -1) {
			Q.push(num + 1);
			dist[num + 1] = dist[num] + 1;
		}
		if (num * 2 <= 100000 && dist[num * 2] == -1) {
			Q.push(num * 2);
			dist[num * 2] = dist[num] + 1;
		}
	}
}
