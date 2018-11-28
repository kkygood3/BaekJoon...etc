#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 15
using namespace std;

bool D[MAX];
int n;
int max_val = 0;
int checks[MAX];
int sum;

bool check(int row, int col) {
	
	if (D[col]) return false;
	for (register int i = 0; i < row; i++) {
		if (checks[i] == col) return false;
		if (abs(checks[i] - col) == abs(i - row)) return false;
	}
	return true;
}


void DFS(int row, int select) {

	if (select == n) {
		max_val = select;
		sum++;
	}

	for (register int j = 0; j < n; j++) {
		if (check(row, j)) {
			checks[row] = j;
			D[j] = true;
			DFS(row + 1, select + 1);
			D[j] = false;
		}
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	if (n == 2) {
		cout << 0 << '\n';
		return 0;
	}
	if (n == 3) {
		cout << 8 << '\n';
		return 0;
	}
	DFS(0, 0);

	cout << sum << '\n';

	return 0;
}

// BRUTE FORCE 시간초과...
//#include <iostream>
//#include <cstring>
//#define MAX 15
//using namespace std;
//
//int arr[MAX][MAX];
//bool D[MAX][MAX];
//int n;
//int max_val = 0;
//
//bool check(int row, int col) {
//
//	if (D[row][col]) return false;
//	if (arr[row][col]) return false;
//	return true;
//}
//
//void range(int row, int col) {
//	for (int k = 0; k < n; k++) {
//		arr[row][k]++;
//		arr[k][col]++;
//	}
//	arr[row][col]--;
//	for (int i = 1; i < n; i++) {
//		if (row + i < n && col + i < n) arr[row + i][col + i]++;
//		if (row - i >= 0 && col - i >= 0) arr[row - i][col - i]++;
//		if (row - i >= 0 && col + i < n) arr[row - i][col + i]++;
//		if (row + i < n && col - i >= 0) arr[row + i][col - i]++;
//	}
//}
//
//void range_off(int row, int col) {
//
//	for (int k = 0; k < n; k++) {
//		arr[row][k]--;
//		arr[k][col]--;
//	}
//	arr[row][col]++;
//	for (int i = 1; i < n; i++) {
//		if (row + i < n && col + i < n) arr[row + i][col + i]--;
//		if (row - i >= 0 && col - i >= 0) arr[row - i][col - i]--;
//		if (row - i >= 0 && col + i < n) arr[row - i][col + i]--;
//		if (row + i < n && col - i >= 0) arr[row + i][col - i]--;
//	}
//
//}
//
//void DFS(int cur) {
//
//	if (cur > max_val) max_val = cur;
//
//	for (int row = 0; row < n; row++) {
//		for (int col = 0; col < n; col++) {
//			cout << D[row][col] << ' ';
//		}
//		cout << '\n';
//	}
//	for (int row = 0; row < n; row++) {
//		for (int col = 0; col < n; col++) {
//			cout << arr[row][col] << ' ';
//		}
//		cout << '\n';
//	}
//
//	cout << '\n';
//	for (int row = 0; row < n; row++) {
//		for (int col = 0; col < n; col++) {
//			if (check(row, col)) {
//				D[row][col] = true;
//				range(row, col);
//				DFS(cur + 1);
//				D[row][col] = false;
//				range_off(row, col);
//			} 
//		}
//	}	
//
//}
//
//int main() {
//
//	cin.tie(0); ios::sync_with_stdio(0);
//	cin >> n;
//
//	DFS(0);
//
//	cout << max_val << '\n';
//
//	return 0;
//}