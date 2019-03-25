#include <iostream>
using namespace std;

int score[130];
int d[11][11]; // [선수][포지션]
int D[11]; // 포지션 방문
int max_ = 0;

void DFS(int cur, int sum) { // sum을 넘겨준다.
	if (cur == 11) {
		max_ = max_ < sum ? sum : max_;
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (!D[i] && d[cur][i] > 0) {
			D[i] = 1;
			DFS(cur + 1, sum + d[cur][i]);
			D[i] = 0;
		}
	}

}

int main() {

	int t;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;

	for (int i = 0; i < t; i++) {
		max_ = 0;
		for (int j = 0; j < 11; j++) {
			for (int k = 0; k < 11; k++) {
				cin >> d[j][k];
			}
		}

		DFS(0, 0);
		cout << max_ << '\n';
	}

	return 0;
}