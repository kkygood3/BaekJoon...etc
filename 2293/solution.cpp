#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int d[1002][1002];

int main() {
	
	
	string s1, s2;
	cin >> s1 >> s2;
	//for (int i = 0; i <= 1000; i++) {
	//	for (int j = 0; j <= 1000; j++) {
	//		d[i][j] = '0';
	//	}
	//}
	int s1_size = s1.size();
	int s2_size = s2.size();
	for (int i = 1; i <= s1_size; i++) {
		d[i][0] = s1[i - 1];
	}
	for (int i = 1; i <= s2_size; i++) {
		d[0][i] = s2[i - 1];
	}
	/*for (int i = 0; i <= s1_size; i++) {
		for (int j = 0; j <= s2_size; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}*/
	for (int i = 1; i <= s1_size; i++) {
		for (int j = 1; j <= s2_size; j++) {
			if (i == 1 || j == 1) {
				if (d[0][j] == d[i][0]) d[i][j] = 1;
				else if(d[i-1][j] == 1 || d[i][j-1] == 1) d[i][j] = 1;
				else d[i][j] == 0;
			}
		}
	}
	for (int i = 2; i <= s1_size; i++) {
		for (int j = 2; j <= s2_size; j++) {
				if (d[i][0] == d[0][j]) d[i][j] = d[i-1][j-1] + 1;
				else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
				if (d[i][j] >= min(i, j)) d[i][j] = min(i, j);
		}
	}
	/*for (int i = 0; i <= s1_size; i++) {
		for (int j = 0; j <= s2_size; j++) {
			if(d[i][j] >= 50)cout << char(d[i][j]) << ' ';
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
*/
	cout << d[s1_size][s2_size];

	return 0;
}