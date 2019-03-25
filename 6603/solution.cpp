#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> //memcpy
#include <queue>
#define MAX 25
using namespace std;

int k;
int arr[13];
bool D[13];

void DFS(int cnt, int select) {

	if (cnt > k) return;

	if (select == 6) {
		
		for (int j = 0; j < k; j++) {
			if (D[j]) cout << arr[j] << ' ';
		}
		cout << '\n';

		return;
	}


	D[cnt] = true;
	DFS(cnt + 1, select + 1);
	D[cnt] = false;
	DFS(cnt + 1, select);

	return;
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);

	while (1) {
		cin >> k;
		if (k == 0) return 0;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		DFS(0, 0);

		cout << '\n';

	}


	return 0;
}