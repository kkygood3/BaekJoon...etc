#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

	int t, result[10000] = { 0, }, arr[15][14];
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;

	
	for (int i = 0; i < 14; i++) {
		arr[0][i] = i + 1;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 0; j < 14; j++) {
			int temp = 0;
			for (int k = 0; k <= j; k++) {
				temp += arr[i - 1][k];
			}
			arr[i][j] = temp;
		}
	}

	/*for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 14; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << '\n';
	}*/
	for (int i = 0; i < t; i++) {

		int k, n;
		cin >> k >> n;

		result[i] = arr[k][n - 1];
	}

	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
	return 0;

}