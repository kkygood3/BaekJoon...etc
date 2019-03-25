#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

	int n;
	cin >> n;

	int a = sqrt(n);

	while (a >= 1) {

		if (n % a == 0) {
			cout << abs(a - (n / a)) << '\n';
			return 0;
		}

		--a;
	}

	return 0;
}