#include <iostream>
#include <cstring>
#define MAX 25
using namespace std;

int arr[MAX][MAX];
int origin[MAX][MAX];
int test_case[5];
bool change[MAX][MAX];
int n;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 }; // 위 아래 왼 오른
int ans = 0;

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			change[i][j] = false;
		}
	}
}

bool check(int row, int col){
	if (row < 0 || col < 0 || row >= n || col >=n) return false;
	return true;
}

void UP() {
	for (int col = 0; col < n; ++col) {
		for (int i = 0; i < n; ++i) {  // n번 반복
			for (int row = 1; row < n; ++row) {
				int next_row = row + d_row[0];
				int next_col = col + d_col[0];
				if (check(next_row, next_col)) {
					if (!change[row][col] && !change[next_row][next_col] && arr[row][col] == arr[next_row][next_col] && arr[row][col] != 0) {
						change[next_row][next_col] = true;
						arr[next_row][next_col] *= 2;
						arr[row][col] = 0;
						
					}
					if (arr[row][col] != 0 && arr[next_row][next_col] == 0) {
						if (change[row][col] == true) {
							change[row][col] = false;
							change[next_row][next_col] = true;
						}
						arr[next_row][next_col] = arr[row][col];
						arr[row][col] = 0;
					}
				}
			}
		}

	}
	init();
}

void DOWN() {
	for (int col = 0; col < n; ++col) {
		for (int i = 0; i < n; ++i) {  // n번 반복
			for (int row = n - 2; row >= 0; --row) {
				int next_row = row + d_row[1];
				int next_col = col + d_col[1];
				if (check(next_row, next_col)) {
					if (!change[row][col] && !change[next_row][next_col] && arr[row][col] == arr[next_row][next_col] && arr[row][col] != 0) {
						change[next_row][next_col] = true;
						arr[next_row][next_col] *= 2;
						arr[row][col] = 0;
					}
					if (arr[row][col] != 0 && arr[next_row][next_col] == 0) {
						if (change[row][col] == true) {
							change[row][col] = false;
							change[next_row][next_col] = true;
						}
						arr[next_row][next_col] = arr[row][col];
						arr[row][col] = 0;
					}
				}
			}
		}

	}
	init();
}

void LEFT() {
	for (int row = 0; row < n; ++row) {
		for (int i = 0; i < n; ++i) {  // n번 반복
			for (int col = 1; col < n; ++col) {
				int next_row = row + d_row[2];
				int next_col = col + d_col[2];
				if (check(next_row, next_col)) {
					if (!change[row][col] && !change[next_row][next_col] && arr[row][col] == arr[next_row][next_col] && arr[row][col] != 0) {
						change[next_row][next_col] = true;
						arr[next_row][next_col] *= 2;
						arr[row][col] = 0;
					}
					if (arr[row][col] != 0 && arr[next_row][next_col] == 0) {
						if (change[row][col] == true) {
							change[row][col] = false;
							change[next_row][next_col] = true;
						}
						arr[next_row][next_col] = arr[row][col];
						arr[row][col] = 0;
					}
				}
			}
		}

	}
	init();
}

void RIGHT() {
	for (int row = 0; row < n; ++row) {
		for (int i = 0; i < n; ++i) {  // n번 반복
			for (int col = n - 2; col >= 0; --col) {
				int next_row = row + d_row[3];
				int next_col = col + d_col[3];
				if (check(next_row, next_col)) {
					if (!change[row][col] && !change[next_row][next_col] && arr[row][col] == arr[next_row][next_col] && arr[row][col] != 0) {
						change[next_row][next_col] = true;
						arr[next_row][next_col] *= 2;
						arr[row][col] = 0;
					}
					if (arr[row][col] != 0 && arr[next_row][next_col] == 0) {
						if (change[row][col] == true) {
							change[row][col] = false;
							change[next_row][next_col] = true;
						}
						arr[next_row][next_col] = arr[row][col];
						arr[row][col] = 0;
					}
				}
			}
		}

	}
	init();
}

void DFS(int cur) {

	if (cur == 0) {
		memcpy(arr, origin, sizeof(origin));
		for (int i = 0; i < 5; ++i) {
			if (test_case[i] == 0) UP();
			if (test_case[i] == 1) DOWN();
			if (test_case[i] == 2) LEFT();
			if (test_case[i] == 3) RIGHT();
		}
/*
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}*/

		for (int row = 0; row < n; ++row) {
			for (int col = 0; col < n; ++col) {
				if (ans < arr[row][col]) ans = arr[row][col];
			}
		}
		return;
	}

	for (int i = 0; i < 4; ++i) {
		test_case[cur - 1] = i;
		DFS(cur - 1);
	}

}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> origin[i][j];
			arr[i][j] = origin[i][j];
		}
	}

	DFS(5);

	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}*/

	cout << ans << '\n';

	return 0;
}