#include <iostream>
using namespace std;

int n, k;
int D[31];

void DFS(int cur, int select) {

	if (cur > n) return;
	if (select == k) {
		for (int i = 0; i < n; i++) {
			cout << D[i];
		}
		cout << '\n';
		return;
	}

		D[cur] = 1;
		DFS(cur + 1, select + 1);
		D[cur] = 0;
		DFS(cur + 1, select);

}

int main() {

	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n >> k;

	DFS(0, 0);

	return 0;
}