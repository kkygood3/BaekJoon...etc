#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[80];
int D[80];
bool first;
int check;
void DFS(int cur) {

	if (first) return;

	if (cur >= 2 && arr[cur - 1] == arr[cur - 2]) return;

	int range = cur / 2;

	if (cur >= 4) {
		for (int i = 2; i <= range; i++) {
			check = 0;
			for (int j = 0; j < i; j++) {
				if(arr[cur - 1 - j] == arr[cur - 1 - i - j]) check++;
			}
			if (i == check) return;
		}
		
	}

	if (cur == n && !first) {
		for (int i = 0; i < cur; i++) {
			cout << arr[i];
		}
		cout << '\n';
		first = true;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (!D[cur]) {
			D[cur] = 1;
			arr[cur] = i;
			DFS(cur + 1);
			D[cur] = 0;
		}
	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;

	DFS(0);

	return 0;
}