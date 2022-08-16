#include<iostream>
using namespace std;

int N, cnt = 0;
//int arr[14];
int isUsed1[14] = { 0, };
int isUsed2[27] = { 0, };
int isUsed3[27] = { 0, };

void BT(int k) {
	if (k == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!isUsed1[i] && !isUsed2[k+i] && !isUsed3[k-i+N-1]) {
			isUsed1[i] = 1;
			isUsed2[k+i] = 1;
			isUsed3[k-i+N-1] = 1;
			BT(k + 1);
			isUsed1[i] = 0;
			isUsed2[k + i] = 0;
			isUsed3[k - i + N - 1] = 0;
		}
	}
}
int main() {

	cin >> N;
	BT(0);
	cout << cnt;
}