#include <iostream>
#include <vector>
using namespace std;
int fibo[41][2];


int main() {
	int t;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	int n;

	fibo[0][0] = 1; fibo[0][1] = 0;
	fibo[1][0] = 0; fibo[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
	}

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << fibo[n][0] << ' ' << fibo[n][1] << '\n';
	}
	
	return 0;
}