#include <iostream>
#include <vector>
using namespace std;

int arr[6][4];	// 퍼즐 판
int visit[6][4];	// 놓은 블록 (방문)
int full;	// 채워야 하는 칸 수
int max_score;
vector<int> ans;
int puzzle[37][5][2] = { {{0,0},{0,1},{0,2},{1,2},{0,0}},{{0,0},{1,0},{1,1},{1,2},{0,0}},{{0,0},{0,1},{1,0},{2,0},{0,0}},{{0,0},{1,0},{2,0},{2,-1},{0,0}},
{{0,0},{1,0},{1,-1},{1,-2},{0,0}},{{0,0},{1,0},{0,1},{0,2},{0,0}},{{0,0},{1,0},{2,0},{2,1},{0,0}},{{0,0},{0,1},{1,1},{2,1},{0,0}},
{{0,0},{0,1},{1,0},{2,0},{2,-1}},{{0,0},{0,1},{1,1},{2,1},{2,2}},{{0,0},{1,0},{1,-1},{1,-2},{2,-2}},{{0,0},{1,0},{1,1},{1,2},{2,2}},
{{0,0},{1,0},{1,-1},{1,1},{0,0}},{{0,0},{0,1},{1,1},{0,2},{0,0}},{{0,0},{1,0},{1,1},{2,0},{0,0}},{{0,0},{1,0},{1,-1},{2,0},{0,0}},
{{0,0},{1,0},{2,0},{2,-1},{2,1}},{{0,0},{0,1},{0,2},{1,1},{2,1}},{{0,0},{1,0},{2,0},{1,1},{1,2}},{{0,0},{1,0},{2,0},{1,-1},{1,-2}},
{{0,0},{0,1},{1,1},{1,2},{0,0}},{{0,0},{0,1},{1,0},{1,-1},{0,0}},{{0,0},{1,0},{1,1},{2,1},{0,0}},{{0,0},{1,0},{1,-1},{2,-1},{0,0}},
{{0,0},{0,1},{1,0},{1,1},{1,2}},{{0,0},{1,0},{1,1},{2,0},{2,1}},{{0,0},{0,1},{1,1},{1,0},{1,-1}},{{0,0},{0,1},{1,0},{1,1},{2,1}},
{{0,0},{0,1},{0,2},{1,0},{1,1}},{{0,0},{1,-1},{1,0},{2,0},{2,-1}},{{0,0},{0,1},{0,2},{1,1},{1,2}},{{0,0},{0,1},{1,0},{1,1},{2,0}},
{{0,0},{0,1},{1,0},{1,1},{0,0}},{{0,0},{1,0},{2,0},{2,1},{2,2}},{{0,0},{0,1},{0,2},{1,2},{2,2}},{{0,0},{1,0},{2,0},{2,-1},{2,-2}},{{0,0},{1,0},{2,0},{0,1},{0,2}}
};		//배열 디버깅 ok

bool check(int row, int col, int puz) {
	for (int i = 0; i < 5; ++i) {
		int next_row = row + puzzle[puz][i][0];
		int next_col = col + puzzle[puz][i][1];
		if (next_row < 0 || next_col < 0 || next_row >= 6 || next_col >= 4) return false;
		if (visit[next_row][next_col] != 0 || arr[next_row][next_col] == 0) return false;
	}
	return true;
}

void DFS(int row, int col, int cur) {

	if (cur == full) {
		int score = 0;
		
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (arr[i][j] == visit[i][j] && arr[i][j] != 0) score++;
			}
		}
		
		if (score > max_score) max_score = score;
		return;
	}

	for (int puz = 0; puz < 37; ++puz) {
		if (check(row,col,puz)) {
			for (int k = 0; k < 5; ++k) {
				int next_row = row + puzzle[puz][k][0];
				int next_col = col + puzzle[puz][k][1];
				if(puz < 8) visit[next_row][next_col] = 1;
				else if(puz < 12) visit[next_row][next_col] = 5;
				else if (puz < 16) visit[next_row][next_col] = 2;
				else if (puz < 20) visit[next_row][next_col] = 6;
				else if (puz < 24) visit[next_row][next_col] = 3;
				else if (puz < 32) visit[next_row][next_col] = 7;
				else if (puz < 33) visit[next_row][next_col] = 4;
				else if (puz < 37) visit[next_row][next_col] = 8;
			}

			int b = col;
			int visit_row = 0, visit_col = 0;
			bool sw = false;
			for (int i = row; i < 6; ++i) {
				for (int j = b; j < 4; ++j) {
					if (arr[i][j] != 0 && visit[i][j] == 0) {
						visit_row = i;
						visit_col = j;
						sw = true;
						break;
					}
				}
				if (sw) break;
				b = 0;
			}

			if (puz < 8) DFS(visit_row, visit_col, cur + 4);
			else if (puz < 12) DFS(visit_row, visit_col, cur + 5);
			else if (puz < 16) DFS(visit_row, visit_col, cur + 4);
			else if (puz < 20) DFS(visit_row, visit_col, cur + 5);
			else if (puz < 24) DFS(visit_row, visit_col, cur + 4);
			else if (puz < 32) DFS(visit_row, visit_col, cur + 5);
			else if (puz < 33) DFS(visit_row, visit_col, cur + 4);
			else if (puz < 37) DFS(visit_row, visit_col, cur + 5);

			for (int k = 0; k < 5; ++k) {
				int next_row = row + puzzle[puz][k][0];
				int next_col = col + puzzle[puz][k][1];
				visit[next_row][next_col] = 0;
			}
		}
	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	int t;

	cin >> t;

	for (int tc = 0; tc < t; tc++) {

		full = 0;
		max_score = 0;

		int go_row = 0, go_col = 0;
		bool sw = false;
		for (int row = 0; row < 6; ++row) {
			for (int col = 0; col < 4; ++col) {
				cin >> arr[row][col];
				if (!sw && arr[row][col] != 0) {
					sw = true;
					go_row = row;
					go_col = col;
				}
				if (arr[row][col] != 0) full++;
			}
		}

		DFS(go_row, go_col, 0);

		ans.push_back(max_score);
	}

	for (int tc = 0; tc < t; ++tc) cout << "#" << tc + 1 << " " << ans[tc] << '\n';

	return 0; 
}