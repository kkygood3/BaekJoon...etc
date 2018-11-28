#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char d[7][7];

void check(int i, int j) {

	char tmp = d[i][j];
	
	if(tmp < d[i + 1][j] && tmp < d[i - 1][j] && tmp < d[i][j + 1] && tmp < d[i][j - 1]) d[i][j] = '*';

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			d[i][j] = '9';
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> d[i][j];
		}
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			check(i, j);
		}
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}