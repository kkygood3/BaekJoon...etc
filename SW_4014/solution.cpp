#include <iostream>
#include <vector>
#define MAX 20
using namespace std;

int t, n, x;
int arr[MAX][MAX];
bool check[MAX];
bool D[MAX];
int cnt = 0;
vector<int> ans;

void check_row(int row, int col) {

	if (col == n - 1) {
		cnt++;
		return;
	}

	if (col + 1 >= 0 && col + 1 < n) {
		if (arr[row][col + 1] == arr[row][col]) {
			check_row(row, col + 1);
		}
		else if (arr[row][col + 1] == arr[row][col] + 1) // 지금보다 다음이 경사가 1 높을 때
		{
			for (int i = 0; i < x; i++) {
				if (col - i < 0 || col - i >= n) return;
				if (arr[row][col] != arr[row][col - i]) return;
				if (D[col - i]) return;
			}

			for (int i = 0; i < x; i++) {
				D[col - i] = true;
			}
			check_row(row, col + 1);

		}
		else if (arr[row][col + 1] == arr[row][col] - 1) // 지금보다 다음이 경사가 1 낮을 때
		{
			for (int i = 0; i < x; i++) {
				if (col + 1 + i < 0 || col + 1 + i >= n) return;
				if (arr[row][col + 1] != arr[row][col + 1 + i]) return;
				if (D[col + 1 + i]) return;
			}

			for (int i = 0; i < x; i++) {
				D[col + 1 + i] = true;
			}
			check_row(row, col + 1);
		}
		else return; // 지금보다 경사가 2이상 차이날 때
	}
}

void check_col(int col, int row) {

	if (row == n - 1) {
		cnt++;
		return;
	}

	if (row + 1 >= 0 && row + 1 < n) {
		if (arr[row + 1][col] == arr[row][col]) {
			check_col(col, row + 1);
		}
		else if (arr[row + 1][col] == arr[row][col] + 1) // 지금보다 다음이 경사가 1 높을 때
		{
			for (int i = 0; i < x; i++) {
				if (row - i < 0 || row - i >= n) return;
				if (arr[row - i][col] != arr[row][col]) return;
				if (D[row - i]) return;
			}

			for (int i = 0; i < x; i++) {
				D[row - i] = true;
			}
			check_col(col, row + 1);

		}
		else if (arr[row + 1][col] == arr[row][col] - 1) // 지금보다 다음이 경사가 1 낮을 때
		{
			for (int i = 0; i < x; i++) {
				if (row + 1 + i < 0 || row + 1 + i >= n) return;
				if (arr[row + 1][col] != arr[row + 1 + i][col]) return;
				if (D[row + 1 + i]) return;
			}

			for (int i = 0; i < x; i++) {
				D[row + 1 + i] = true;
			}
			check_col(col, row + 1);
		}
		else return; // 지금보다 경사가 2이상 차이날 때
	}
}

void init() {

	for (int i = 0; i < n; i++) {
		D[i] = false;
	}
}

int main() {

	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> n >> x;
		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			check_row(i, 0);

			init();
		}

		for (int i = 0; i < n; i++) {
			check_col(i, 0);

			init();
		}

		ans.push_back(cnt);

	}

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << ' ' << ans[i] << '\n';
	}

	return 0;
}