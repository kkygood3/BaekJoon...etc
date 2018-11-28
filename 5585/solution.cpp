#include <iostream>
using namespace std;

int coin[6] = { 500,100,50,10,5,1 };

int main() {

	int sum = 1000;
	int n;
	cin >> n;
	sum -= n;
	int ans = 0;
	int count = 0;
	while (sum != 0) {
		if (sum >= coin[count]) {
			ans++;
			sum -= coin[count];
		}
		else count++;
	}

	cout << ans << '\n';

	return 0;
}