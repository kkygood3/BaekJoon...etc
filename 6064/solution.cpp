#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	int t, m, n, x, y, result[100000];
	int mul;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> m >> n >> x >> y;
		mul = m * n;
		result[i] = -1;
		if (x <= m && y <= n) {
			for (int j = x; j <= mul; j += m) {
				if ((j - 1) % n + 1 == y) {
					result[i] = j;
					break;
				}
			}
		}
		}
	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
	return 0;
}


//시간초과 코드 ㅜㅜ
//int main() {
//
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//	int t;
//	int co[100000] = { 0, };
//	cin >> t;
//
//	for (int i = 0; i < t; i++) {
//		co[i]++;
//		int m, n, x, y, x_s = 1, y_s = 1;
//		cin >> m >> n >> x >> y;
//		if (x == 1 && y == 1) continue;
//		while (1) {
//			co[i]++;
//			if (x_s < m) {
//				x_s++;
//			}
//			else x_s = 1;
//
//			if (y_s < n) {
//				y_s += 1;
//			}
//			else y_s = 1;
//
//			if (x_s == x && y_s == y) {
//				break;
//			}
//			if (x_s == m && y_s == n) {
//				co[i] = -1;
//				break;
//			}
//			if (x_s == 1 && y_s == 1) break;
//			if (co[i] >= m * n) {
//				co[i] = -1; break;
//			}
//		}
//	}
//	for (int i = 0; i < t; i++) {
//		cout << co[i] << endl;
//	}
//	return 0;
//}