#include <iostream>
using namespace std;

int l, a, b, c, d;

int main() {

	cin >> l >> a >> b >> c >> d;

	while (b > 0 || a > 0) {
		l--;
		a -= c;
		b -= d;
	}
	cout << l << '\n';

	return 0;
}