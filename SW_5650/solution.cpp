#include <iostream>
#include <utility>
#include <vector>
#define MAX 102
using namespace std;

int map[MAX][MAX];
bool visit[MAX][MAX][4];
int t, n;
int d_row[4] = { 0,0,1,-1 };
int d_col[4] = { 1,-1,0,0 }; // µ¿ ¼­ ³² ºÏ
int max_point;
int block[6][4] = { {0,1,2,3},{1,3,0,2},{1,2,3,0},{2,0,3,1},{3,0,1,2},{1,0,3,2} };
pair<int, int> hole[MAX][MAX];
pair<int, int> hole_pos[11];
int start_row;
int start_col;
vector<int> ans;
int g = 0;

bool check(int row, int col) {

	if (row < 0 || col < 0 || row >= n || col >= n) return false;

	return true;

}

void DFS(int r, int c, int d, int p) {
	int next_row = r;
	int next_col = c;
	int dir = d;
	int point = p;
	while (1) {

		cout << next_row << " , " << next_col << " , " << dir << '\n';

		next_row = next_row + d_row[dir];
		next_col = next_col + d_col[dir];
		if (next_row == start_row && next_col == start_col) {
			if (max_point < point) max_point = point;
			return;
		}
		else if (map[next_row][next_col] == -1) {
			if (max_point < point) max_point = point;
			return;
		}
		else if (map[next_row][next_col] == 0) {

		}
		else if (map[next_row][next_col] >= 1 && map[next_row][next_col] <= 5) {
			dir = block[map[next_row][next_col]][dir];
			point += 1;
		}
		else if (map[next_row][next_col] >= 6 && map[next_row][next_col] <= 10) {
			next_row = hole[next_row][next_col].first;
			next_col = hole[next_row][next_col].second;
		}
		
	}
}


int main() {
	
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		cin >> n;
		max_point = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10) {
					if (hole_pos[map[i][j]].first == 0) {
						hole_pos[map[i][j]] = make_pair(i, j);
					}
					else {

						hole[i][j].first = hole_pos[map[i][j]].first;
						hole[i][j].second = hole_pos[map[i][j]].second;
						hole[hole_pos[map[i][j]].first][hole_pos[map[i][j]].second].first = i;
						hole[hole_pos[map[i][j]].first][hole_pos[map[i][j]].second].second = j;

					}
				}
			}
		}


		for (int i = 0; i <= n + 1; i++) {
			map[0][i] = 5;
			map[i][0] = 5;
			map[n + 1][i] = 5;
			map[i][n + 1] = 5;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						start_row = i;
						start_col = j;
						DFS(i, j, k, 0);
					}
				}
			}
		}

		ans.push_back(max_point);

	}

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << " " << ans[i] << '\n';
	}

	return 0;
}