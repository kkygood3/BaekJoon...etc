#include<iostream>
using namespace std;

int main() {

	int a, b, c;

	cin >> a >> b >> c;

	int time;
	cin >> time;

	c += time;

	while (c >= 60) {
		c -= 60;
		b += 1;
	}

	while (b >= 60) {
		b -= 60;
		a += 1;
	}

	while (a >= 24) {
		a -= 24;
	}

	cout << a << ' ' << b << ' ' << c << '\n';

	return 0;
}