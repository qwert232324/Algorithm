#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int dist[1000001] = { 0, };

int main() {

	memset(dist, -1, sizeof(dist));
	queue<int> Q;

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	Q.push(S);
	dist[S] = 0;
	while (!Q.empty()) {
		int num = Q.front();
		Q.pop();
		if (num - D >= 1 && dist[num - D] == -1) {
			Q.push(num - D);
			dist[num - D] = dist[num] + 1;
		}
		if (num + U <= F && dist[num + U] == -1) {
			Q.push(num + U);
			dist[num + U] = dist[num] + 1;
		}
	}
	if (dist[G] == -1) cout << "use the stairs";
	else cout << dist[G];
}