#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, m;
int D[9];
int arr[9] = { 1,2,3,4,5,6,7,8,9 };

void DFS(int cur, int select) {

	if (cur > n) {
		return;
	}

	if (select == m) {
		for (int i = 0; i < n; i++) {
			if(D[i]) cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	D[cur] = 1;
	DFS(cur + 1, select + 1);
	D[cur] = 0;
	DFS(cur + 1, select);
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	
	DFS(0, 0);
	return 0;
}