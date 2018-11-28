#include <iostream>
using namespace std;

int n, m;
int arr[9];
int D[9];

void DFS(int cnt) {

	if (cnt > n) return;
	if (cnt == m) {
		int temp;
		for (int i = 0; i < m; i++) {
			if (i == 0) temp = arr[i];
			else {
				if (arr[i] < temp) return;
				else temp = arr[i];
			}
		}
		for (int i = 0; i < m; i++) {
			cout << arr[i] + 1 << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[cnt] = i;
		DFS(cnt + 1);
	}

}

int main() {

	cin >> n >> m;
	DFS(0);
	return 0;
}