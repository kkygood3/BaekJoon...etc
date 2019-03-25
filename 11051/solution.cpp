#include <iostream>
using namespace std;

int arr[1001][1001];

int test[10];
int main() {

	int n, k;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> k;

	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;

	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= k; j++) {
			arr[i][j] = arr[i - 1][j - 1] % 10007 + arr[i - 1][j] % 10007;
			arr[i][j] %= 10007;
		}
	}


	cout << arr[n][k];

	return 0;
}