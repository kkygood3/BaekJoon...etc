#include <iostream>
using namespace std;

int main() {

	int t;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	int n;
	int count[10001] = { 0, };
	for (int i = 1; i <= t; i++) {
		cin >> n;
		count[n]++;
	}
	
	for (int i = 1; i <= 10000; i++) {
		while (count[i] > 0) {
			cout << i << '\n';
			count[i]--;
		}
	}

	return 0;
}