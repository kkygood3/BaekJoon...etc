#include <iostream>
#include <string>
using namespace std;

string arr[21];

int main() {

	int n;
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n;

	arr[1] = '1';
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + to_string(i) + arr[i - 1];
	}

	cout << arr[n] << '\n';

	return 0;
}