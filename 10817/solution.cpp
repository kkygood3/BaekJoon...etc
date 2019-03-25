#include <iostream>
using namespace std;

int main() {

	int A, B, C, n, max, min;
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C;
	n = A + B + C;
	A > B ? (A > C ? max = A : max = C) : (B > C ? max = B : max = C);
	A > B ? (B > C ? min = C : min = B) : (A > C ? min = C : min = A);

	n = n - max - min;

	cout << n;

	return 0;
}