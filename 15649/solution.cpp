#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int arr[9];
int D[9];
int n, m;

void DFS(int cnt) {
	if (cnt > m) return;
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] + 1 << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		if (!D[i]) {
			D[i] = 1;
			arr[cnt] = i;
			DFS(cnt + 1);
			D[i] = 0;
		}
	}
}

// 이건 순열
//void DFS(int cur, int select) {
//	if (cur > n) return;
//	if (select == m) {
//		for (int i = 0; i < n; i++) {
//			if (D[i]) cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//	D[cur] = 1; // 확인
//	DFS(cur + 1, select + 1);
//	D[cur] = 0; // 초기화
//	DFS(cur + 1, select);
//}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	
	DFS(0);

	return 0;
}