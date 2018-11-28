#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char arr[101][101];

int main() {

	int a,b;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> a >> b;

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			if (i == 0 || j == 0 || i == b - 1 || j == a - 1) {
				arr[i][j] = '*';
			}
			else arr[i][j] = ' ';
		}
	}

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			cout << arr[i][j];
		}
		if(i != b-1) cout << '\n';
	}

	return 0;
}