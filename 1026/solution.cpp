#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;

int A[MAX];
int B[MAX];

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> B[i];
	}
	sort(&A[0], &A[n]);
	sort(&B[0], &B[n]);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += A[i] * B[n - 1 - i];
	}

	cout << sum << '\n';

	return 0;
}