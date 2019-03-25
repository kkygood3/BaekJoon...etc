#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

char arr[12][6];
char test[12][6];
char visit[12][6];
queue<pair<int, int>> q;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 };

bool check_BFS_dot(int row, int col, char color) {

	if (row < 0 || col < 0 || row >= 12 || col >= 6) return false;
	if (arr[row][col] != color) return false;
	if (arr[row][col] == '.') return false;
	//if (visit[row][col]) return false;

	return true;
}

bool check_BFS(int row, int col, char color) {

	if (row < 0 || col < 0 || row >= 12 || col >= 6) return false;
	if (arr[row][col] != color) return false;
	if (arr[row][col] == '.') return false;
	if (visit[row][col]) return false;

	return true;
}

void BFS_dot(int row, int col, char color) {

	arr[row][col] = '.';
	q.push(make_pair(row, col));
	while (!q.empty()) {

		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (check_BFS_dot(next_row, next_col, color)) {
				arr[next_row][next_col] = '.';
				q.push(make_pair(next_row, next_col));
			}
		}

	}
}

bool BFS(int row, int col, char color) {

	int count = 1;
	visit[row][col] = true;
	q.push(make_pair(row, col));
	while (!q.empty()) {

		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int next_row = cur_row + d_row[i];
			int next_col = cur_col + d_col[i];
			if (check_BFS(next_row, next_col, color)) {
				count++;
				visit[next_row][next_col] = true;
				q.push(make_pair(next_row, next_col));
			}
		}
	}
	if (count >= 4) return true;
	else return false;
}

void map_change() {

	for (int i = 0; i < 6; ++i) {
		int count = 0;
		char temp[13];
		for (int j = 0; j < 12; ++j) {
			if (arr[j][i] != '.') {
				count++;
				temp[count] = arr[j][i];
			}
		}
		int tmp = 0;
		for (int j = 0; j < 12 - count; ++j) {
			arr[j][i] = '.';
		}
		for (int j = 12 - count; j < 12; ++j) {
			arr[j][i] = temp[++tmp];
		}
	}

}

void init() {
	
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			visit[i][j] = false;
		}
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);

	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 6; ++j) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	while(true){
		bool sw = false;

		for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				if (arr[i][j] != '.') {

					if (BFS(i, j, arr[i][j])) {
						BFS_dot(i, j, arr[i][j]);
						sw = true;
					}
					init();
				}
			}
		}

		if (sw) ans++;

		/*for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				cout << arr[i][j];
			}
			cout << '\n';
		}*/
		memcpy(test, arr, sizeof(arr));
		map_change();
		if (!memcmp(test, arr, sizeof(arr))) break;

		/*for (int i = 0; i < 12; ++i) {
			for (int j = 0; j < 6; ++j) {
				cout << arr[i][j];
			}
			cout << '\n';

		}*/
}
	cout << ans << '\n';
	return 0;
}