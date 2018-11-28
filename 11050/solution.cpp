#include <iostream>
using namespace std;

int factorial(int n) {
	if (n <= 1) return 1;
	n *= factorial(n - 1);
	return n;
}

int main() {

	int n, k;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	
	cout << factorial(n) / (factorial(k) * factorial(n - k));

	return 0;
}