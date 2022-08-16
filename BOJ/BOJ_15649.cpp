#include<iostream>
using namespace std;

int N, M;
int arr[10];
int isUsed[10];

void BT(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!isUsed[i]) {
			arr[k] = i;
			isUsed[i] = 1;
			BT(k + 1);
			isUsed[i] = 0;
		}
	}
}
int main() {

	cin >> N >> M;
	BT(0);
}