#include <iostream>
using namespace std;

int factorial(int n) {
	if (n <= 1) return 1;
	n *= factorial(n - 1);
	return n;
}

int main() {

	int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;

	cout << factorial(n);

	return 0;
}