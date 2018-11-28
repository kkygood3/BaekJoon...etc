#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n;
char f[10];
int arr[10];
bool D[10];
bool D_[10];
bool first;
string s;

void DFS(int cur) {

	if (cur >= 2) {
		for (int i = 1; i < cur; i++) {
			if (f[i - 1] == '>') {
				if (arr[i - 1] > arr[i]) continue;
				else return;
			}

			if (f[i - 1] == '<') {
				if (arr[i - 1] < arr[i]) continue;
				else return;
			}
		}
	}
	
	if (cur == n + 1) {
		s = "";
		if (!first) {
			for (int i = 0; i < cur; i++) {
				cout << arr[i];
			}
			cout << '\n';
			first = true;
		}
		else {
			for (int i = 0; i < cur; i++) {
				s += to_string(arr[i]);
			}
		}
		return;
	}


	for (int i = 9; i >= 0; i--) {

		if (!D[cur] && !D_[i]) {
			D[cur] = true;
			D_[i] = true;
			arr[cur] = i;
			DFS(cur + 1);
			D[cur] = false;
			D_[i] = false;
		}

	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}

	DFS(0);

	cout << s << '\n';

	return 0;
}