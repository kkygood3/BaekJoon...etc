#include <iostream>
#include <string>
using namespace std;

int main() {

	int n[5], score = 0;
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		cin >> n[i];
	}
	for (int i = 0; i < 5; i++) {
		if (n[i] <= 40) n[i] = 40;
	}
	for (int i = 0; i < 5; i++) {
		score += n[i];
	}

	score /= 5;
	cout << score;
	return 0;
}