#include<iostream>
#include<queue>
#include<utility>
using namespace std;

bool arr[102][102];
int n;

int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {

		int x, y;
		cin >> x >> y;

		for (int row = x; row < x + 10; ++row) {
			for (int col = y; col < y + 10; ++col) {
				arr[row][col] = true;
			}
		}

	}
	int cnt = 0;
	for (int row = 0; row < 100; ++row) {
		for (int col = 0; col < 100; ++col) {
			if (arr[row][col]) cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}