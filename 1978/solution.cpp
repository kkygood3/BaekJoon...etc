#include <iostream>
using namespace std;

int main() {

	int n, num, sum = 0;
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (n == 1) sum++;
		for (int j = 2; j <= num; j++) {
			if (j == num) sum++;
			if (num % j == 0) break;
		}
	}

	cout << sum;

	return 0;
}