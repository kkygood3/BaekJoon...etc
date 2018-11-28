#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> //memcpy
using namespace std;

int c, r;
int arr[21][21];
bool d[21];
int score = 0, idx = 0;

int check(int row, int col) {

	int tmp = 0;
	if (row < 3) return 0;

	int temp[21][21];
	memcpy(temp, arr, sizeof(arr));

	temp[row][col] = 1;
	temp[row - 1][col] = 1;
	temp[row - 2][col] = 1;
	temp[row - 3][col] = 1;

	for (int row = 0; row < r; row++) {
		int cnt = 0;
		for (int col = 0; col < c; col++) {
			if (temp[row][col] == 1) cnt++;
		}
		if (cnt == c) tmp++;
	}
	return tmp;
}

int main() {

	cin.tie(0);  ios::sync_with_stdio(0);
	cin >> c >> r;

	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			cin >> arr[row][col];
		}
	}


	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			if (!d[col]) {
				if (arr[row][col] == 1) {
					d[col] = true;
					if (row - 1 < 0) arr[row][col] = 2;
					else arr[row - 1][col] = 2;
				}
			}
		}
	}

	for (int i = 0; i < c; i++) {
		if (!d[i]) {
			d[i] = true;
			arr[r - 1][i] = 2;
		}
	}

	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			if (arr[row][col] == 2) {
				int temp;
				temp = check(row, col);
				if (score < temp) {
					score = temp;
					idx = col + 1;
				}
			}
		}
	}

	cout << idx << ' ' << score << '\n';

	return 0;
}