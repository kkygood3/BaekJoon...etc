#include <iostream>
#include <queue>
#include <utility>
#define MAX 30
using namespace std;

int n, m, h;

queue<pair<int, int>> q;
int arr[MAX + 1][MAX + 1];
int visit[MAX + 1][MAX + 1];
int D[MAX];
bool sw;

bool check_line() {
	
	for (int i = 1; i <= n; i++) {
		int row = 1;
		int col = i;
		while (row < h + 1) {
			if (visit[row][col] == 1) {
				col += 1;
			}
			else if (visit[row][col] == -1) {
				col -= 1;
			}
			row++;
		}
		//cout << i << ' ';
		if (col != i) return false;
	}
	return true;
}

bool check(int row, int col, int cur) {

	if (row < 1 || col < 1 || row > h || col >= n) return false;
	if (D[cur]) return false;
	if (visit[row][col] || visit[row][col + 1]) return false;

	return true;
}

void DFS(int row, int col,int cur) {

	if (sw) return;
	if (cur == 0) {
		if (check_line()) {
			sw = true;
		}
		return;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
		
			if (check(i, j, cur)) {
				D[cur] = true;
				visit[i][j] = 1;
				visit[i][j + 1] = -1;
				DFS(i , j, cur - 1);
				D[cur] = false;
				visit[i][j] = 0;
				visit[i][j + 1] = 0;
			}
		}

	}
	

}

int main() {

	cin >> n >> m >> h;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[a][b + 1] = -1;
		visit[a][b] = 1;
		visit[a][b + 1] = -1;
	}

	
	for (int i = 0; i <= 3; i++) {
		DFS(1, 1, i);
		if (sw) {
			cout << i;
			return 0;
		}
	}
	cout << -1;

	return 0;
}