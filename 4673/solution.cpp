#include <iostream>
using namespace std;
int self_(int num);

int main() {

	int N = 10001, self;
	bool num[10001] = {false,};

	for (int i = 0; i < N; i++) {
		if (self_(i) <= 10000) {
			num[self_(i)] = true;
		}
	}
	
	for (int i = 0; i < N; i++) {
		if (!num[i]) cout << i << '\n';
	}


	return 0;
}
int self_(int i) {
	int x[5] = { 0, };
	x[0] = i % 10;
	x[1] = (i / 10) % 10;
	x[2] = (i / 100) % 10;
	x[3] = (i / 1000) % 10;
	x[4] = (i / 10000) % 10;
	return i + x[0] + x[1] + x[2] + x[3] + x[4];
	
}