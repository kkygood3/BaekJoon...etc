#include <vector>
using namespace std;

int bingo(vector<vector<int>> board, int n) {

	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		int row = 0;
		int col = 0;
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == 0) row++;
			if (board[j][i] == 0) col++;
		}
		if (row == n) cnt++;
		if (col == n) cnt++;
	}

	int cross1 = 0;
	int cross2 = 0;
	for (int i = 0; i < n; ++i) {
		if (board[i][i] == 0) cross1++;
		if (board[n - 1 - i][i] == 0) cross2++;
	}
	if (cross1 == n) cnt++;
	if (cross2 == n) cnt++;

	return cnt;
}

int solution(vector<vector<int>> board, vector<int> nums) {
	int answer = 0;
	bool erase[250001];

	for (int i = 1; i <= 250000; ++i) erase[i] = false;

	int sz = nums.size();
	int n = board.size();

	for (int i = 0; i < sz; ++i) erase[nums[i]] = true;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (erase[board[i][j]]) board[i][j] = 0;
		}
	}

	answer = bingo(board, n);

	return answer;
}