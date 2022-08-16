#include<iostream>
using namespace std;

int N, S, cnt = 0;
int arr[20];
int isused[20];
void BT(int k) {

	if (k == N) {
		int sum = 0;
		for (int i = 0; i < k; i++) {
			if (isused[i]) sum += arr[i];
		}
		if (sum == S) cnt++;
		return;
	}
	isused[k] = true;
	BT(k + 1);
	isused[k] = false;
	BT(k + 1);

}
int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
	BT(0);
	if (S == 0) cnt--;
	cout << cnt;
}