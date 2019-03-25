#include <iostream>
#include <utility>
#define MAX 52
using namespace std;

char arr[MAX][MAX];
int n;
int ans = 0;
int d_row[2] = { 1,0 };
int d_col[2] = { 0,1 };

void calcul() {
	int sum = 0;
	char ch;
	for (int row = 0; row < n; ++row) {
		ch = 'X';
		for (int col = 0; col < n; ++col) {
			if (ch == arr[row][col]) sum++;
			else {
				ch = arr[row][col];
				sum = 1;
			}
			if (sum > ans) ans = sum;
		}
	}

	for (int col = 0; col < n; ++col) {
		ch = 'X';
		for (int row = 0; row < n; ++row) {
			if (ch == arr[row][col]) sum++;
			else {
				ch = arr[row][col];
				sum = 1;
			}
			if (sum > ans) ans = sum;
		}
	}

}

void swap(int row, int col, int next_row, int next_col) {

	char tmp = arr[row][col];
	arr[row][col] = arr[next_row][next_col];
	arr[next_row][next_col] = tmp;

}

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= n || col >= n) return false;
	return true;
}

void change(int row, int col) {

	for (int i = 0; i < 2; ++i) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		if (check(next_row, next_col)) {
			swap(row, col, next_row, next_col);
			calcul();
			swap(next_row, next_col, row, col);
		}
	}

}

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			change(i,j);
		}
	}

	cout << ans;
	
	return 0;
}