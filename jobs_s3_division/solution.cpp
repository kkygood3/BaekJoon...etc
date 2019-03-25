#include <iostream>
#include <string>
using namespace std;

int n, cnt = 0;
int D[20];
int arr[20];

void DFS(int cur) {

	
	if (cur > n) return;

	if (cur >= 2 && cur <= n) {
		int sum = 0;
		
		for (int i = 0; i < cur; i++) {
			sum += arr[i];
			if (i == cur - 2 && sum >= n) return;
		}
		if (sum == n) {
			++cnt;
			for (int i = 0; i < cur; i++) {
				if (i == cur - 1) cout << arr[i] << '\n';
				else cout << arr[i] << "+";

			}
		}
	}

	for (int i = n - 1; i >= 1; i--) {
		if (cur >= 1 && arr[cur - 1] < i) continue;
		else if (!D[cur]) {
			D[cur] = 1;
			arr[cur] = i;
			DFS(cur + 1);
			D[cur] = 0;

		}
	}
}

int main() {

	cin >> n;
	DFS(0);
	cout << cnt << '\n';
	return 0;
}