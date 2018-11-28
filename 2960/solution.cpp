#include <iostream>
using namespace std;

bool arr[1010];

int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 2; i <= n; ++i) {
		arr[i] = true;
	}

	int p;
	int count = 0;
	for (int i = 2; i <= n; ++i) {
		if (arr[i]) {
			p = i;
			arr[i] = false;
			count++;
			if (count == k) {
				cout << p << '\n';
				return 0;
			}
			for (int j = p; j <= n; j+=p) {
				if (arr[j]) {
					arr[j] = false;
					count++;
					if (count == k) {
						cout << j << '\n';
						return 0;
					}
				}
			}
		}

	}

	return 0;
}