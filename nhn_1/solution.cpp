#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

queue<int> q;
vector<int> deck[5];
int old = 0, top = 1, mid = 2, bot = 3, fin = 5;
int n;

void shufle(int c,int n, vector<int> deck[]) {

	for (int j = c - 1; j > c - n; j--) {
		deck[fin].push_back(deck[old][j]);
	}
	for (int j = n - 1; j >= 0; j--) {
		deck[fin].push_back(deck[old][j]);
	}
	for (int j = c - n; j >= n; j--) {
		deck[fin].push_back(deck[old][j]);
	}

	if ((c - (2 * n)) > (2 * n)) {
		shufle((c - (2 * n)), n, deck);
	}
	else {
		return;
	}
}

int main() {

	int c, p;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> c >> p;
	for (int i = 1; i <= c; i++) {
		deck[old].push_back(i);
	}
	for (int i = 0; i < p; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	for (int i = 0; i < p; i++) {
		n = q.front();
		q.pop();
		shufle(c, n, deck);
	}
	vector<int>::iterator iter;

	for (iter = deck[fin].begin(); iter != deck[fin].end(); iter++) {
		cout << *iter << '\n';
	}


	return 0;
}