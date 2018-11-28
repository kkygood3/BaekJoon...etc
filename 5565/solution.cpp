#include <iostream>
using namespace std;

int main() {

	int sum;
	cin >> sum;

	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		sum -= tmp;
	}

	cout << sum << '\n';

	return 0;
}