#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> //memcpy
using namespace std;

int c, r, k;
int arr[1002][1002];
int state = 0;


int main() {

	cin.tie(0);  ios::sync_with_stdio(0);
	cin >> c >> r >> k;
	if (k > c * r) {
		cout << 0;
		return 0;
	}

	int cnt = 1;
	int row = 1;
	int col = 1;

	arr[1][1] = 1;

	while (1) {
		if (cnt == k) {
			cout << col << ' ' << row;
			break;
		}
		if (state == 0) {
			row++;
			if (arr[row][col] != 0 || row > r) {
				state = 1;
				row--;
				col++;
				arr[row][col] = ++cnt;
			}
			else arr[row][col] = ++cnt;
		}
		else if (state == 1) {
			col++;
			if (arr[row][col] != 0 || col > c) {
				state = 2;
				col--;
				row--;
				arr[row][col] = ++cnt;
			}
			else arr[row][col] = ++cnt;
		}
		else if (state == 2) {
			row--;
			if (arr[row][col] != 0 || row <= 0) {
				state = 3;
				row++;
				col--;
				arr[row][col] = ++cnt;
			}
			else arr[row][col] = ++cnt;
		}
		else if (state == 3) {
			col--;
			if (arr[row][col] != 0 || col <= 0) {
				state = 0;
				col++;
				row++;
				arr[row][col] = ++cnt;
			}
			else arr[row][col] = ++cnt;
		}
	}
	
	/*for (int row = 1; row <= r; row++) {
		for (int col = 1; col <= c; col++) {
			cout << arr[row][col] << ' ';
		}
		cout << endl;
	}*/

	return 0;
}