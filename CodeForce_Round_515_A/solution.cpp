#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000000000


int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int l, v, ll, r;
		cin >> l >> v >> ll >> r;
		int cnt = 0;
		int des = l / v;
		des = des * v;
		int start = (ll - 1) / v;
		int end = ceil(double((double(r) + 1.) / double(v)));
		end = end * v;
		end = (des - end) / v + 1;
		if (r + 1 > des) end = 0;
		cout << start + end << '\n';
	}

	return 0;
}