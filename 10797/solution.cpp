#include <iostream>
using namespace std;

int arr[5];

int main() {

	int n;
	cin >> n;
	int cnt = 0;

	for (int i = 0; i < 5; ++i) {
		cin >> arr[i];
		if (arr[i] == n) cnt++;
	}


	cout << cnt << '\n';



	return 0;
}