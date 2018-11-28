#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
#include <string>
#define MAX 10
using namespace std;

int arr[MAX][MAX];
int arr_BFS[MAX][MAX];
int n, m;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };
int ans = 0;
vector<pair<int, int>> v;
queue<pair<int, int>> q;


bool check(int row, int col) {

	if (arr[row][col] != 0) return false;
	
	return true;

}

bool check_BFS(int row, int col) {

	if (row < 0 || col < 0 || row >= n || col >= m) return false;
	if (arr_BFS[row][col] != 0) return false;
	
	return true;
}

void BFS() {

	for (int i = 0; i < v.size(); ++i) {
		q.push(make_pair(v[i].first, v[i].second));
	}

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int next_row = row + d_row[i];
			int next_col = col + d_col[i];
			if (check_BFS(next_row, next_col)) {
				arr_BFS[next_row][next_col] = 2;
				q.push(make_pair(next_row, next_col));
			}
		}

	}
	//cout << "BFS" << '\n';
}

void DFS(int cur) {

	if (cur == 3) {

		//cout << "DFS" << '\n';
		memcpy(arr_BFS, arr, sizeof(arr));
		BFS();
		int count = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (arr_BFS[i][j] == 0) count++;
			}
		}
		/*cout << '\n';
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}*/
		if (count > ans) {
			ans = count;
			
		}
		return;
	}

	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < m; ++col) {
			if (check(row, col)) {
				arr[row][col] = 1;
				DFS(cur + 1);
				arr[row][col] = 0;
			}
		}
	}

}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) v.push_back(make_pair(i, j));
		}
	}

	DFS(0);

	cout << ans << '\n';

	return 0;

}