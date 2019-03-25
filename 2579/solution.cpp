#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int stack_val[300][2]; // 불연속0 연속1

// DP

int main() {

	int n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;


	for (int i = 0; i < n; i++) {
		int su;
		cin >> su;
		v.push_back(su);
	}

	stack_val[0][0] = v[0];
	stack_val[1][0] = v[1];
	stack_val[1][1] = v[0] + v[1];

	for (int i = 2; i < n; i++) {
		stack_val[i][0] = max({ stack_val[i][0],
								stack_val[i - 2][0] + v[i],
								stack_val[i - 2][1] + v[i] });

		stack_val[i][1] = max(stack_val[i][1], stack_val[i - 1][0] + v[i]);
	}

	cout << (stack_val[n - 1][0] > stack_val[n - 1][1] ? stack_val[n - 1][0] : stack_val[n - 1][1]);

	return 0;
}