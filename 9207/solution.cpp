#include <iostream>
#include <vector>
#include <utility>
using namespace std;

char arr[5][9];
vector<pair<int,int>> ans;
int t;
int d_row[4] = { -1,1,0,0 };
int d_col[4] = { 0,0,-1,1 }; // ºÏ, ³², ¼­, µ¿
int pin = 0;
int min_cur;
int min_pin;

bool check(int row, int col, int dir) {
	int next_row = row + d_row[dir];
	int next_col = col + d_col[dir];

	if (row < 0 || col < 0 || row >= 5 || col >= 9) return false;
	if (next_row < 0 || next_col < 0 || next_row >= 5 || next_col >= 9) return false;
	if (arr[row][col] == 'o') {
		if (arr[next_row][next_col] == '.') return true;
	}

	return false;
}

void DFS(int cur) {

	/*for (int row = 0; row < 5; ++row) {
		for (int col = 0; col < 9; ++col) {
			cout << arr[row][col];
		}
		cout << '\n';
	}*/
	
	if (pin - cur <= min_pin) {
		min_pin = pin - cur;
		min_cur = cur;
		/*cout << "min_pin : " << min_pin << "min_cur : " << min_cur << '\n';
		for (int row = 0; row < 5; ++row) {
			for (int col = 0; col < 9; ++col) {
				cout << arr[row][col];
			}
			cout << '\n';
		}*/
	}

	if (cur == pin - 1) {
		min_pin = 1;
		if (cur < min_cur) min_cur = cur;
		return;
	}

	for (int row = 0; row < 5; ++row) {
		for (int col = 0; col < 9; ++col) {
			for (int i = 0; i < 4; ++i) {
					int next_row = row + d_row[i];
					int next_col = col + d_col[i];
					int nn_row = next_row + d_row[i];
					int nn_col = next_col + d_col[i];
					if (arr[row][col] == 'o') {
						if (check(next_row, next_col, i)) {

							arr[next_row][next_col] = '.';
							arr[row][col] = '.';
							arr[nn_row][nn_col] = 'o';

							DFS(cur + 1);

							arr[next_row][next_col] = 'o';
							arr[row][col] = 'o';
							arr[nn_row][nn_col] = '.';
						}
					}
			}
		}
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);

	cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		pin = 0;
		min_cur = 9999;
		for (int row = 0; row < 5; ++row) {
			for (int col = 0; col < 9; ++col) {
				cin >> arr[row][col];
				if (arr[row][col] == 'o') pin++;
			}
		}

		min_pin = pin;
		
		DFS(0);

		ans.push_back(make_pair(min_pin, min_cur));
	}

	int sz = ans.size();

	for (int i = 0; i < sz; ++i) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}


	return 0;
}