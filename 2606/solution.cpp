#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int v, n;
vector<int> node[101];
bool visit[101];
queue<int> q;
int ans = 0;

void BFS(int cur) {

	visit[cur] = true;
	q.push(cur);

	int cnt = 0;
	while (!q.empty()) {
		int sz = q.size();

		for (int qs = 0; qs < sz; ++qs) {
			cur = q.front();
			q.pop();

			int no = node[cur].size();
			for (int i = 0; i < no; ++i) {
				int next = node[cur][i];

				if (!visit[next]) {
					cnt++;
					visit[next] = true;
					q.push(next);
				}
			}

		}
	}
	ans = cnt;
}

int main() {

	cin >> v >> n;

	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	BFS(1);

	cout << ans << '\n';

	return 0;
}