#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


int main() {

	int n, v, u;
	
	cin >> n >> v >> u;
	int v_game = (v - 1);
	int u_game = (u - 1);
	int final = sqrt(n) + 1;
	for (int round = 1; round <= final; round++) {
		v_game = v_game / 2;
		u_game = u_game / 2;
		if (v_game == u_game) {
			cout << round;
			return 0;
		}
	}
	cout << -1;
	return 0;
}