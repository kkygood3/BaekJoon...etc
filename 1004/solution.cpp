#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v;

int main() {

	int t;
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
	
		int n;
		cin >> n;

		int cnt = 0;
		for (int i = 1; i <= n; ++i) {		//행성계의 수
			int cx, cy, r;
			cin >> cx >> cy >> r;

			if (pow(cx - x1, 2) + pow(cy - y1, 2) < pow(r, 2) && pow(cx - x2, 2) + pow(cy - y2, 2) < pow(r, 2));
			else if (pow(cx - x1, 2) + pow(cy - y1, 2) < pow(r, 2)) cnt++;
			else if (pow(cx - x2, 2) + pow(cy - y2, 2) < pow(r, 2)) cnt++;

		}
		v.push_back(cnt);
	}
	int sz = v.size();
	for (int i = 0; i < sz; ++i) cout << v[i] << '\n';

	return 0;
}