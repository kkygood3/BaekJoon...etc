#include <iostream>
#include <queue>
using namespace std;

int r, c;
char arr[30][30];
int fail_row;
int fail_col;
int fail[4] = { 0, };	// µ¿ ¼­ ³² ºÏ
char fail_block;

void check(int row, int col, char block) {
	if (block == '|') {
		if (arr[row - 1][col] == '.') {
			fail_row = row - 1;
			fail_col = col;
			fail[2] = 1;		// ³²
			return;
		}
		if (arr[row + 1][col] == '.') {
			fail_row = row + 1;
			fail_col = col;
			fail[3] = 1;		// ºÏ
			return;
		}
	}
	if (block == '-') {
		if (arr[row][col + 1] == '.') {
			fail_row = row;
			fail_col = col + 1;
			fail[1] = 1;		// ¼­
			return;
		}
		if (arr[row ][col - 1] == '.') {
			fail_row = row ;
			fail_col = col - 1;
			fail[0] = 1;		// µ¿
			return;
		}
	}
	if (block == '+') {
		if (arr[row - 1][col] == '.') {
			fail_row = row - 1;
			fail_col = col;
			fail[2] = 1;
			return;
		}
		if (arr[row + 1][col] == '.') {
			fail_row = row + 1;
			fail_col = col;
			fail[3] = 1;
			return;
		}
		if (arr[row][col + 1] == '.') {
			fail_row = row;
			fail_col = col + 1;
			fail[1] = true;
			return;
		}
		if (arr[row][col - 1] == '.') {
			fail_row = row;
			fail_col = col - 1;
			fail[0] = true;
			return;
		}
	}
	if (block == '1') {
		if (arr[row][col + 1] == '.') {
			fail_row = row;
			fail_col = col + 1;
			fail[1] = 1;
			return;
		}
		if (arr[row + 1][col] == '.') {
			fail_row = row + 1;
			fail_col = col;
			fail[3] = true;
			return;
		}
	}
	if (block == '2') {
		if (arr[row][col + 1] == '.') {
			fail_row = row;
			fail_col = col + 1;
			fail[1] = 1;
			return;
		}
		if (arr[row - 1][col] == '.') {
			fail_row = row - 1;
			fail_col = col;
			fail[2] = true;
			return;
		}
	}
	if (block == '3') {
		if (arr[row][col - 1] == '.') {
			fail_row = row;
			fail_col = col - 1;
			fail[0] = true;
			return;
		}
		if (arr[row - 1][col] == '.') {
			fail_row = row - 1;
			fail_col = col;
			fail[2] = true;
			return;
		}
	}
	if (block == '4') {
		if (arr[row][col - 1] == '.') {
			fail_row = row;
			fail_col = col - 1;
			fail[0] = true;
			return;
		}
		if (arr[row + 1][col] == '.') {
			fail_row = row + 1;
			fail_col = col;
			fail[3] = true;
			return;
		}
	}
}

int main() {

	cin >> r >> c;

	for (int row = 1; row <= r; ++row) {
		for (int col = 1; col <= c; ++col) {
			cin >> arr[row][col];
		}
	}

	for (int row = 1; row <= r; ++row) {
		for (int col = 1; col <= c; ++col) {
			if(arr[row][col] != '.') check(row, col, arr[row][col]);
		}
	}
	if (fail[0] && fail[1] && fail[2] && fail[3]) fail_block = '+';
	else if (!fail[0] && !fail[1] && fail[2] && fail[3]) fail_block = '|';
	else if (fail[0] && fail[1] && !fail[2] && !fail[3]) fail_block = '-';
	else if (fail[0] && !fail[1] && fail[2] && !fail[3]) fail_block = '1';
	else if (fail[0] && !fail[1] && !fail[2] && fail[3]) fail_block = '2';
	else if (!fail[0] && fail[1] && !fail[2] && fail[3]) fail_block = '3';
	else if (!fail[0] && fail[1] && fail[2] && !fail[3]) fail_block = '4';
	cout << fail_row << ' ' << fail_col << ' ' << fail_block << '\n';
	return 0;
}