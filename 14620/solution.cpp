#include <iostream>
#define MAX 15
using namespace std;

int n;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int min_cost = 9999;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };

bool check(int row, int col) {
	
	if (visit[row][col]) return false;
	for (int i = 0; i < 4; ++i) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= n || visit[next_row][next_col]) return false;
	}
	return true;
}

void DFS(int cur, int cost) {

	if (cost >= min_cost) return;

	if (cur == 3) {
		
		min_cost = cost;

		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << visit[i][j] << ' ';
			}
			cout << '\n';
		}
		
		cout << cost << '\n';*/

		return;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (check(i,j)) {
				visit[i][j] = true;
				cost += arr[i][j];
				for (int ii = 0; ii < 4; ++ii) {
					int next_row = i + d_row[ii];
					int next_col = j + d_col[ii];
					visit[next_row][next_col] = true;
					cost += arr[next_row][next_col];
				}
				DFS(cur + 1, cost);
				visit[i][j] = false;
				cost -= arr[i][j];
				for (int ii = 0; ii < 4; ++ii) {
					int next_row = i + d_row[ii];
					int next_col = j + d_col[ii];
					visit[next_row][next_col] = false;
					cost -= arr[next_row][next_col];
				}
			}
		}
	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	DFS(0, 0);

	cout << min_cost << '\n';

	return 0;
}