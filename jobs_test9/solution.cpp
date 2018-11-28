#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int state = 0;
int arr[25][25];

int main() {

	int n;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;

	int cnt = 1;
	int i = 0, j = 0;

	while (1) {
		arr[j][i] = cnt++;
		if (state == 0) {
			i++;
			if (i == n || arr[j][i] != 0) {
				state = 1;
				i--;
				j++;
				if (arr[j][i] != 0) break;
			}
		}
		else if (state == 1) {
			j++;
			if (j == n || arr[j][i] != 0) {
				state = 2;
				j--;
				i--;
				if (arr[j][i] != 0) break;
			}
		}
		else if (state == 2) {
			i--;
			if (i == -1 || arr[j][i] != 0) {
				state = 3;
				i++;
				j--;
				if (arr[j][i] != 0) break;
			}
		}
		else if (state == 3) {
			j--;
			if (j == -1 || arr[j][i] != 0) {
				state = 0;
				j++;
				i++;
				if (arr[j][i] != 0) break;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}