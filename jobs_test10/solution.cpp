#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char arr[27];
bool d[27];
int n, r;

void DFS(int cnt) {

	if (cnt == r) {
		for (int i = 0; i < r; i++) {
				cout << arr[i];
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!d[i]) {
			d[i] = true;
			arr[cnt] = i + 'a';
			DFS(cnt + 1);
			d[i] = false;
		}
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> r;

	DFS(0);

	return 0;
}