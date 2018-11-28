#include <iostream>
#include <cmath>
#define MAX 20
using namespace std;

int arr[MAX];
int n;
int ans = 0;

bool check(int row, int col) {
	for (int i = 0; i < row; i++) {
		if (arr[i] == col || i == row || abs(arr[i] - col) == abs(i - row)) return false;	
	}
	return true;
}

void DFS(int cur) {

	if (cur == n) {
		ans++;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (check(cur, i)) {
			arr[cur] = i;
			DFS(cur + 1);
		}
	}

}


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;

	DFS(0);

	cout << ans << '\n';

	return 0;
}