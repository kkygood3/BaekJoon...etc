#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> //memcpy
#include <queue>
#define MAX 250
using namespace std;

int r, c;
char arr[MAX][MAX];
bool D[MAX][MAX];
int v = 0;
int o = 0;
int last_v = 0, last_o = 0;
void check(int row, int col) {
	D[row][col] = true;
	if (arr[row][col] == 'v') {
		arr[row][col] = '.';
		v++;
	}
	if (arr[row][col] == 'o') {
		arr[row][col] = '.';
		o++;
	}
	if (row - 1 >= 0 && arr[row - 1][col] != '#' && !D[row - 1][col]) {
		check(row - 1, col);
	}
	if (col - 1 >= 0 && arr[row][col - 1] != '#' && !D[row][col - 1]) {
		check(row, col - 1);
	}
	if (row + 1 < r && arr[row + 1][col] != '#' && !D[row + 1][col]) {
		check(row + 1, col);
	}
	if (col + 1 < c && arr[row][col + 1] != '#' && !D[row][col + 1]) {
		check(row, col + 1);
	}


}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);

	cin >> r >> c;

	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			cin >> arr[row][col];
			if (arr[row][col] == '#') D[row][col] = true;
		}
	}

	for (int row = 0; row < r; row++) {
		for (int col = 0; col < c; col++) {
			if (arr[row][col] == 'v')
			{
				v = 0; o = 0;
				check(row, col);
				if (v >= o) last_v += v;
				else last_o += o;
			}
			else if (arr[row][col] == 'o')
			{
				v = 0; o = 0;	
				check(row, col);
				if (v >= o) last_v += v;
				else last_o += o;
			}
		}
	}

	cout << last_o << ' ' << last_v << '\n';

	return 0;
}