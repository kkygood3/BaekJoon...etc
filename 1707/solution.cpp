#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define MAX 20010
using namespace std;

bool sw;
int visit[MAX];
int v, e;
vector<string> ans;
vector<int> graph[MAX];
queue<int> q;

void BFS(int node) {

	if (visit[node] == 0) {
		q.push(node);
		visit[node] = 1;
	}
	int color = 1;

	while (!q.empty()) {
		int qs = q.size();
		color++;
		if (color == 3) color = 1;
		for (int sz = 0; sz < qs; ++sz) {
			node = q.front();
			q.pop();
			int v_sz = graph[node].size();
			for (int i = 0; i < v_sz; ++i) {
				int cur = graph[node][i];
				if (visit[cur] == 0) {
					visit[cur] = color;
					q.push(cur);
				}
				else if (visit[cur] == 1 && color == 2) {
					sw = true;
					break;
				}
				else if (visit[cur] == 2 && color == 1) {
					sw = true;
					break;
				}
				else if (visit[node] == visit[cur]) {
					sw = true;
					break;
				}
			}
			
		}

	}
}

void init() {
	while (!q.empty()) q.pop();
	for (int i = 0; i <= v; ++i) visit[i] = 0;

	for (int i = 0; i <= v; ++i) graph[i].clear();
}

int main() {

	int t;

	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		cin >> v >> e;
		sw = false;
		for (int i = 1; i <= e; ++i) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		for (int i = 1; i <= v; ++i) {
			BFS(i);
		}

		if (sw) ans.push_back("NO");
		else ans.push_back("YES");

		init();
	}

	int sz = ans.size();
	for (int i = 0; i < sz; ++i) cout << ans[i] << '\n';

	return 0;
}