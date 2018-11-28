#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#define MAX 8
using namespace std;

int k, n, t, max_;
int mount[MAX][MAX];
int origin_mount[MAX][MAX];
bool D[MAX][MAX];
int d_row[4] = { 1,0,-1,0 };
int d_col[4] = { 0,1,0,-1 };
vector<pair<int,int>> pos;
vector<int> ans;

bool check(int row, int col, int dep) {

	if (row < 0 || col < 0 || row >= n || col >= n) return false;
	if (D[row][col]) return false;
	if (mount[row][col] >= dep) return false;
	return true;
}

void DFS(int row, int col, int dep, int level) {

	if (max_ < level) {
		max_ = level;
		/*cout << level << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << D[i][j] << ' ';
			}
			cout << '\n';
		}*/
	}

	for (int i = 0; i < 4; i++) {
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		
		if (check(next_row, next_col, dep)) {
			int next_dep = mount[next_row][next_col];
			D[next_row][next_col] = true;
			DFS(next_row, next_col, next_dep, level + 1);
			D[next_row][next_col] = false;
		}
	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;
	for (int tc = 0; tc < t; tc++) {

		cin >> n >> k;
		int max = 0;
		max_ = 0;
		pos.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> origin_mount[i][j];
				max = max < origin_mount[i][j] ? origin_mount[i][j] : max;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (origin_mount[i][j] == max) {
					pos.push_back(make_pair(i, j));
				}
				
			}
		}

		/*for (int i = 0; i < pos.size(); i++) {
			int row = pos[i].first;
			int col = pos[i].second;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					D[j][k] = false;
				}
			}
			D[row][col] = true;
			DFS(row, col, max, 1);

		}*/
		
		for (int i = 0; i < pos.size(); i++) {

			int row = pos[i].first;
			int col = pos[i].second;

			for (int j = 0; j < n; j++) {
				for (int jj = 0; jj < n; jj++) {
					for (int jjj = 1; jjj <= k; jjj++) {
						memcpy(mount, origin_mount, sizeof(origin_mount));
						mount[j][jj] -= jjj;
						for (int j = 0; j < n; j++) {
							for (int k = 0; k < n; k++) {
								D[j][k] = false;
							}
						}
						D[row][col] = true;
						DFS(row, col, max, 1);

					}

				}
			}

		}
		ans.push_back(max_);

	}

	for (int i = 0; i < ans.size(); i++) {
		cout << "#" << i + 1 << " " << ans[i] << '\n';
	}
	
	return 0;
}