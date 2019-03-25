#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


int main() {

	int max = 0, sum = 0;
	int n = 4;
	queue<int> q[2];

	for (int i = 0; i < n; i++) {
		int plus, minus;
		cin >> minus >> plus;
		q[0].push(minus);
		q[1].push(plus);
	}

	for (int i = 0; i < n; i++) {
		int tmp = q[0].front();
		q[0].pop();
		sum -= tmp;
		tmp = q[1].front();
		q[1].pop();
		sum += tmp;
		max = (max < sum ? sum : max);
	}
	cout << max;
	return 0;
}