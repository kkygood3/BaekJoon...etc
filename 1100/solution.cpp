#include <iostream>
using namespace std;

char arr[8][8];

int main() {

	int ans = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> arr[i][j];
			if (!((i + j) % 2) && arr[i][j] == 'F') ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}