#include <iostream>
using namespace std;

int main() {

	int n;

	cin >> n;

	int x = 64;
	int count = 0;
	int sum = 0;

	while (sum != n) {
		if (x + sum <= n) {
			sum += x;
			count++;
		}
		if (x + sum > n) x /= 2;
	}

	cout << count << '\n';

	return 0;
}