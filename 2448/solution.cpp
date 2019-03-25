#include <iostream>
using namespace std;
void star(int N, int x, int y);

char arr[3072][6144];

int main() {
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			if (j == 2 * N - 1) {
				arr[i][j] = '\n';
			}
			else {
				arr[i][j] = ' ';
			}
		}
	}

	star(N, N - 1, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
				cout << arr[i][j];
		}
	}
	return 0;
}

void star(int N, int x, int y) {
	
	if (N == 3) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
		return;
	}
	
	star(N / 2, x, y);
	star(N / 2, x - (N / 2), y + (N / 2));
	star(N / 2, x + (N / 2), y + (N / 2));

}
