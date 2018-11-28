#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define MAX 10
using namespace std;

queue<pair<int, int>> q;
int arr[MAX][MAX];
int AP[8][MAX][MAX];
bool visit[MAX][MAX];
int t, m, a;
queue<int> A_move;
queue<int> B_move;
int d_row[5] = { 0,-1,0,1,0 };
int d_col[5] = { 0,0,1,0,-1 };
int p_max;
vector<int> ans;

bool check(int row, int col) {

	if (row < 0 || col < 0 || row >= 10 || col >= 10) return false;
	if (visit[row][col]) return false;
	return true;
}

void BFS(int row, int col, int c, int p, int AP_num) {

	q.push(make_pair(row, col));
	AP[AP_num][row][col] = p;
	visit[row][col] = true;
	int cnt = 0;
	
	while (cnt < c) {
		int sz = q.size();

		for (int qs = 0; qs < sz; qs++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();

			for (int i = 1; i <= 4; i++) {
				int next_row = cur_row + d_row[i];
				int next_col = cur_col + d_col[i];

				if (check(next_row,next_col)) {
					visit[next_row][next_col] = true;
					AP[AP_num][next_row][next_col] = p;
					q.push(make_pair(next_row, next_col));
				}
			}


		}
		cnt++;
	}

}

void init() {
	while (!q.empty())q.pop();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			visit[i][j] = false;
		}
	}
}

void BFS_move() {

	int A_row = 0;
	int A_col = 0;

	int B_row = 9;
	int B_col = 9;
	int A_p = 0;
	int B_p = 0;

	while (!A_move.empty()) {
		A_row = A_row + d_row[A_move.front()];
		A_col = A_col + d_col[A_move.front()];
		A_move.pop();

		B_row = B_row + d_row[B_move.front()];
		B_col = B_col + d_col[B_move.front()];
		B_move.pop();

		if (A_row == B_row && A_col == B_col) {

			vector<int> AP_vector;

			for (int i = 0; i < a; i++) {
				if (AP[i][A_row][A_col] != 0) {
					AP_vector.push_back(AP[i][A_row][A_col]);
				}
			}
			if (AP_vector.size() == 1) {
				A_p += AP_vector[0] / 2;
				B_p += AP_vector[0] / 2;
			}
			else if (AP_vector.size() >= 2) {

				sort(AP_vector.begin(), AP_vector.end());
				int max_idx = AP_vector.size() - 1;
				A_p += AP_vector[max_idx];
				B_p += AP_vector[max_idx - 1];
			}

		}
		else {

			int A_max = 0;
			int B_max = 0;
			vector<int> A_cnt;
			vector<int> B_cnt;

			for (int i = 0; i < a; i++) {

				if (AP[i][A_row][A_col] > 0) A_cnt.push_back(AP[i][A_row][A_col]);
				if (AP[i][B_row][B_col] > 0) B_cnt.push_back(AP[i][B_row][B_col]);

				if (A_max < AP[i][A_row][A_col]) {
					A_max = AP[i][A_row][A_col];
				}
				if (B_max < AP[i][B_row][B_col]) {
					B_max = AP[i][B_row][B_col];
				}
				sort(A_cnt.begin(), A_cnt.end());
				sort(B_cnt.begin(), B_cnt.end());
			}

			if (A_cnt.size() == 0 || B_cnt.size() == 0) {

				A_p += A_max;
				B_p += B_max;

			}
			else if (A_cnt.size() == 1 && B_cnt.size() == 1) {
				if (A_cnt[0] == B_cnt[0]) {
					A_p += A_max / 2;
					B_p += B_max / 2;
				}
				else {
					A_p += A_max;
					B_p += B_max;
				}
			}
			else if (A_cnt.size() >= 2 && B_cnt.size() == 1) {
				if (A_max == B_max) {
					A_p += A_cnt[A_cnt.size() - 2];
					B_p += B_max;
				}
				else {
					A_p += A_max;
					B_p += B_max;
				}

			}
			else if (B_cnt.size() >= 2 && A_cnt.size() == 1) {
				if (A_max == B_max) {
					B_p += B_cnt[B_cnt.size() - 2];
					A_p += A_max;
				}

				else {
					A_p += A_max;
					B_p += B_max;
				}
			}

			else if (A_cnt.size() >= 2 && B_cnt.size() >= 2) {
				if (A_max == B_max) {

					if (A_cnt[A_cnt.size() - 2] > B_cnt[B_cnt.size() - 2]) {
						A_p += A_cnt[A_cnt.size() - 2];
						B_p += B_cnt[B_cnt.size() - 1];
					}
					else {
						A_p += A_cnt[A_cnt.size() - 1];
						B_p += B_cnt[B_cnt.size() - 2];
					}
				}

				else {
					A_p += A_max;
					B_p += B_max;
				}
			}

		}



		/*for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if(A_row == i && A_col == j) cout << 'a' << ' ';
				else if (B_row == i && B_col == j) cout << 'b' << ' ';
				else cout << 0 << ' ';
			}
			cout << endl;
		}


		cout << endl;
		cout << "³¡" << A_p << " , " << B_p <<  endl;*/
	}

	p_max += A_p + B_p;
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);

	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> m >> a;

		p_max = 0;
		A_move.push(0);
		B_move.push(0);

		for (int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			A_move.push(temp);
		}

		for (int i = 0; i < m; i++) {
			int temp;
			cin >> temp;
			B_move.push(temp);
		}

		for (int i = 0; i < a; i++) {
			int row, col, c, p;

			cin >> row >> col >> c >> p;

			BFS(col - 1, row - 1, c, p, i);
			init();

		}

		/*for (int u = 0; u < a; u++) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (AP[u][i][j]) cout << u + 1 << ' ';
					else cout << 0 << ' ';
				}
				cout << '\n';
			}
			cout << '\n';
		}*/

		BFS_move();

		ans.push_back(p_max);

	}

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << ' ' << ans[i] << '\n';
	}
	return 0;
}