#include <iostream>
using namespace std;

long long n;

int main() {

	cin >> n;
	long long sum = 0;
	
	sum = (n * (n + 1)) / 2;

	if (sum % 2 == 0) cout << 0 << '\n';
	else cout << 1 << '\n';

	return 0;
}