#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

queue<int> q;
bool visit[200001];

int BFS(int c, int b) {
	q.push(b);
	if (c == b) return 0;

	c++;
	int plus = 2;
	int time = 1;
	while (!q.empty()) {
		int qs = q.size();
		for (int sz = 0; sz < qs; ++sz) {
			int cur = q.front();
			q.pop();
			visit[cur] = false;

			for (int i = 0; i < 3; ++i) {
				int next;
				if (i == 0) next = cur - 1;
				else if (i == 1) next = cur + 1;
				else if (i == 2) next = 2 * cur;

				if (next < 0 || next > 200000 || visit[next]) continue;
				
				if (next == c) {
					return time;
				}

				visit[next] = true;
				q.push(next);
			}
		}
		c += plus;
		plus++;
		time++;
	}
	return -1;
}

int main(void) {

	int c, b;
	cin >> c >> b;

	cout << BFS(c, b) << '\n';

	return 0;
}