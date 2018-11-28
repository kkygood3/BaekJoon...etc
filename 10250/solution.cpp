#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

	int t, result[10000] = { 0, };
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;


	for (int i = 0; i < t; i++) {

		int h, w, n;
		cin >> h >> w >> n;
		int temp = ((n - 1) / h);
		result[i] += temp + 1;
		result[i] += (n - (h * temp)) * 100;
	}

	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
	return 0;

}