#include <iostream>
using namespace std;

int main() {

	int min_ham = 9999;
	int min_cok = 9999;

	for (int i = 0; i < 3; ++i) {
		int temp;
		cin >> temp;
		if (temp <= min_ham) min_ham = temp;
	}

	for (int i = 0; i < 2; ++i) {
		int temp;
		cin >> temp;
		if (temp <= min_cok) min_cok = temp;
	}

	int cost = min_ham + min_cok - 50;

	cout << cost << '\n';

	return 0;
}