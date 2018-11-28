#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

int t, k;
int arr[4][8];
int score[4]; // ²ÀÁþÁ¡
vector<int> ans;
int sum;
int good(int n) {

	if (n >= 0 && n < 8) return n;
	else if (n < 0) return n + 8;
	else if (n >= 8) return n - 8;

}

void spin(int num, int i) {

	if (num == 0 && arr[0][good(score[0] + 2)] != arr[1][good(score[1] - 2)] 
		&& arr[1][good(score[1] + 2)] != arr[2][good(score[2] - 2)] && arr[2][good(score[2] +2)] != arr[3][good(score[3] -2)]) {
		score[0] = good(score[0] - i);
		score[1] = good(score[1] + i);
		score[2] = good(score[2] - i);
		score[3] = good(score[3] + i);
	}
	else if (num == 0 && arr[0][good(score[0] + 2)] != arr[1][good(score[1] - 2)]
		&& arr[1][good(score[1] + 2)] != arr[2][good(score[2] - 2)]) {
		score[0] = good(score[0] - i);
		score[1] = good(score[1] + i);
		score[2] = good(score[2] - i);
	}
	else if (num == 0 && arr[0][good(score[0] + 2)] != arr[1][good(score[1] - 2)]) {
		score[0] = good(score[0] - i);
		score[1] = good(score[1] + i);
	}
	else if (num == 0) score[0] = good(score[0] - i);

	if (num == 1) {
		if (arr[1][good(score[1] - 2)] != arr[0][good(score[0] + 2)] && arr[1][good(score[1] + 2)] != arr[2][good(score[2] - 2)]
			&& arr[2][good(score[2] + 2)] != arr[3][good(score[3] - 2)]) {
			score[0] = good(score[0] + i);
			score[1] = good(score[1] - i);
			score[2] = good(score[2] + i);
			score[3] = good(score[3] - i);
		}
		else if (arr[1][good(score[1] + 2)] != arr[2][good(score[2] - 2)] && arr[2][good(score[2] + 2)] != arr[3][good(score[3] - 2)]) {
			score[1] = good(score[1] - i);
			score[2] = good(score[2] + i);
			score[3] = good(score[3] - i);
		}
		else if (arr[1][good(score[1] - 2)] != arr[0][good(score[0] + 2)] && arr[1][good(score[1] + 2)] != arr[2][good(score[2] - 2)]) {
			score[0] = good(score[0] + i);
			score[1] = good(score[1] - i);
			score[2] = good(score[2] + i);
		}
		else if (arr[1][good(score[1] - 2)] != arr[0][good(score[0] + 2)]) {
			score[0] = good(score[0] + i);
			score[1] = good(score[1] - i);
		}
		else if (arr[1][good(score[1] + 2)] != arr[2][good(score[2] - 2)]) {
			score[1] = good(score[1] - i);
			score[2] = good(score[2] + i);
		}
		else {
			score[1] = good(score[1] - i);
		}
	}

	if (num == 2) {
		if (arr[2][good(score[2] - 2)] != arr[1][good(score[1] + 2)] && arr[2][good(score[2] + 2)] != arr[3][good(score[3] - 2)]
			&& arr[1][good(score[1] - 2)] != arr[0][good(score[0] + 2)]) {
			score[0] = good(score[0] - i);
			score[1] = good(score[1] + i);
			score[2] = good(score[2] - i);
			score[3] = good(score[3] + i);
		}
		else if (arr[2][good(score[2] - 2)] != arr[1][good(score[1] + 2)] && arr[1][good(score[1] - 2)] != arr[0][good(score[0] + 2)]) {
			score[0] = good(score[0] - i);
			score[1] = good(score[1] + i);
			score[2] = good(score[2] - i);
		}
		else if (arr[2][good(score[2] - 2)] != arr[1][good(score[1] + 2)] && arr[2][good(score[2] + 2)] != arr[3][good(score[3] - 2)]) {
			score[1] = good(score[1] + i);
			score[2] = good(score[2] - i);
			score[3] = good(score[3] + i);
		}
		else if (arr[2][good(score[2] - 2)] != arr[1][good(score[1] + 2)]) {
			score[1] = good(score[1] + i);
			score[2] = good(score[2] - i);
		}
		else if (arr[2][good(score[2] + 2)] != arr[3][good(score[3] - 2)]) {
			score[2] = good(score[2] - i);
			score[3] = good(score[3] + i);
		}
		else {
			score[2] = good(score[2] - i);
		}
	}

	if (num == 3) {
		if (arr[3][good(score[3] - 2)] != arr[2][good(score[2] + 2)] && arr[2][good(score[2] - 2)] != arr[1][good(score[1] + 2)]
			&& arr[1][good(score[1] - 2)] != arr[0][good(score[0] + 2)]) {
			score[0] = good(score[0] + i);
			score[1] = good(score[1] - i);
			score[2] = good(score[2] + i);
			score[3] = good(score[3] - i);
		}
		else if (arr[3][good(score[3] - 2)] != arr[2][good(score[2] + 2)] && arr[2][good(score[2] - 2)] != arr[1][good(score[1] + 2)]) {
			score[1] = good(score[1] - i);
			score[2] = good(score[2] + i);
			score[3] = good(score[3] - i);
		}
		else if (arr[3][good(score[3] - 2)] != arr[2][good(score[2] + 2)]) {
			score[2] = good(score[2] + i);
			score[3] = good(score[3] - i);
		}
		else {
			score[3] = good(score[3] - i);
		}
	}
}

void init() {
	sum = 0;

	for (int i = 0; i < 4; i++) {
		score[i] = 0;
	}

}

int main() {

	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		
		cin >> k;
		
		init();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> arr[i][j];

			}
		}

		for (int i = 0; i < k; i++) {
			int j, k;
			cin >> j >> k;
			spin(j - 1, k);
		}
		

		for (int i = 0; i < 4; i++) {
			sum += arr[i][score[i]] * pow(2,i);
		}

		ans.push_back(sum);

	}

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << " " << ans[i] << '\n';
	}

	return 0;
}