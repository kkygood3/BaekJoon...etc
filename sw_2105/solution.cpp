#include <iostream>
#include <vector>
#include <utility>
#define MAX 20
using namespace std;

int t, n;
vector<int> ans;
int arr[MAX][MAX];
bool visit[MAX][MAX];
bool eat[101];
int max_;

int go;
int end_row, end_col;
int d_row[4] = { -1,-1,1,1 };
int d_col[4] = { 1,-1,-1,1 }; // 오른쪽위, 왼쪽위, 왼쪽아래, 오른쪽아래

bool check(int row, int col, int cur, int go) {
	
	if (row < 0 || col < 0 || row >= n || col >= n || go > 3) return false;
	if (go == 3 && cur >= 3 && row == end_row && col == end_col) {
		if (max_ < cur) max_ = cur;
		/*for (register int i = 0; i < n; i++) {
			for (register int j = 0; j < n; j++) {
				cout << visit[i][j] << " ";
			}
			cout << '\n';
		}*/
		return false;
	}// 도착지점일때
	if (eat[arr[row][col]]) return false;
	if (visit[row][col]) return false;

	return true;
}

void DFS(int row, int col, int cur, int go) {

	/*if (cur >= 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << visit[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}*/
	for (int i = 0; i < 2; i++) {
		int next_row = row + d_row[go];
		int next_col = col + d_col[go];
		if (check(next_row, next_col, cur, go) && i == 0) {

			visit[next_row][next_col] = true;
			eat[arr[next_row][next_col]] = true;

			DFS(next_row, next_col, cur + 1, go);

			visit[next_row][next_col] = false;
			eat[arr[next_row][next_col]] = false;
		}
		else if (check(next_row, next_col, cur, go + 1) && i == 1) {
			visit[next_row][next_col] = true;
			eat[arr[next_row][next_col]] = true;
			go += 1;

			DFS(next_row, next_col, cur + 1, go);

			go -= 1;
			visit[next_row][next_col] = false;
			eat[arr[next_row][next_col]] = false;
		}
	}
	
}

void init(int n) {

	for (register int i = 0; i < n; i++) {
		for (register int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}

	for (register int i = 1; i <= 100; i++) {
		eat[i] = false;
	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> n;
		max_ = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				end_row = row;
				end_col = col;
				go = 0;

				visit[row][col] = true;
				eat[arr[row][col]] = true;

				DFS(row, col, 1, go);

				init(n);
			}
		}
		ans.push_back(max_);
	}

	for (int i = 0; i < t; i++) cout << "#" << i + 1 << " " << ans[i] << '\n';

	return 0;
}
