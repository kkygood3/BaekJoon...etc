#include <iostream>
using namespace std;

int main() {

	int N, temp, seed = 9999;
	int x[2];
	int count = 0;
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	if (N < 10) { 
		x[0] = 0;
		x[1] = N;
	}
	else {
		x[0] = N / 10;
		x[1] = N % 10;
	}
	while (seed != N) {
		count++;
		temp = (x[0] + x[1]) % 10;
		x[0] = x[1];
		x[1] = temp;
		seed = x[0] * 10 + x[1];
	}
	cout << count;
	return 0;
}