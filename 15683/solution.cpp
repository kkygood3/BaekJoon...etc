#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 8
using namespace std;

int n, m;
int map[MAX][MAX];
bool cctv[MAX][MAX];
int d_row[4] = { 0,0,1,-1 };
int d_col[4] = { 1,-1,0,0 }; // µ¿ ¼­ ³² ºÏ
int cctv_num = 0;
int D[MAX];
int arr[MAX];
vector<int> cctv_kind;
vector<pair<int, int>> cctv_pos;
queue<pair<int, int>> q;
int min_num = 999;

bool isOK(int row, int col) {

	if (row < 0 || col < 0 || row >= n || col >= m) return false;
	if (map[row][col] == 6) return false;
	
	return true;
}

void BFS(int row, int col, int kind, int deg) {
	int r, c;
	if (kind == 1 && deg == 0) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c++;
		}
	}else if (kind == 1 && deg == 1) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r--;
		}
	}
	else if (kind == 1 && deg == 2) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c--;
		}
	}
	else if (kind == 1 && deg == 3) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r++;
		}
	}else if (kind == 2 && deg == 0) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c--;
		}
	}else if (kind == 2 && deg == 1) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r--;
		}
	}
	else if (kind == 3 && deg == 0) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r--;
		}
	}
	else if (kind == 3 && deg == 1) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c--;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r--;
		}
	}
	else if (kind == 3 && deg == 2) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c--;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r++;
		}
	}
	else if (kind == 3 && deg == 3) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r++;
		}
	}
	else if (kind == 4 && deg == 0) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r--;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c--;
		}
	}
	else if (kind == 4 && deg == 1) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r--;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c--;
		}
	}
	else if (kind == 4 && deg == 2) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c--;
		}
	}
	else if (kind == 4 && deg == 3) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r--;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c++;
		}
	}
	else if (kind == 5 && deg == 0) {
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c++;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r--;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			c--;
		}
		r = row, c = col;
		while (isOK(r, c)) {
			cctv[r][c] = true;
			r++;
		}
	}

}

void check() {

	for (int i = 0; i < cctv_num; i++) {
		BFS(cctv_pos[i].first, cctv_pos[i].second, cctv_kind[i], arr[i]);
	}
}

void DFS(int cur) {

	if (cur == cctv_num) {
		check();
		int cnt_ = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//cout << cctv[i][j] << ' ';
				if (cctv[i][j] == false) cnt_++;

				if (map[i][j] == 0) cctv[i][j] = false;
				else cctv[i][j] = true;
			}
			//cout << '\n';
		}
		if (cnt_ < min_num) min_num = cnt_;

		return;
	}


	for (int i = 0; i < 4; i++) {
		D[cur] = true;
		arr[cur] = i;
		DFS(cur + 1);
		D[cur] = false;
	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv[i][j] = true;
				cctv_num++;
				cctv_kind.push_back(map[i][j]);
				cctv_pos.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 6) cctv[i][j] = true;
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << cctv[i][j] << ' ';
		}
		cout << '\n';
	}*/

	DFS(0);

	cout << min_num << '\n';

	return 0;
}