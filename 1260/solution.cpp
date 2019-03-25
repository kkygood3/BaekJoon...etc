#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n, m, start;

// dfs bfs

void dfs(int start, vector<int> graph[], bool check[]) {
	check[start] = true;
	cout << start << ' ';

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];

		if (check[next] == false) {
			dfs(next, graph, check);
		}
	}
}

void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << ' ';
		for (int i = 0; i < graph[tmp].size(); i++) {
			int next = graph[tmp][i];

			if (check[next] == false) {
				q.push(next);
				check[next] = true;
			}
		}
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m >> start;

	vector<int> *graph = new vector<int>[n+1];
	bool *check = new bool[n + 1];
	fill(check, check + n + 1, false);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	dfs(start, graph, check);
	cout << '\n';
	fill(check, check + n + 1, false);
	bfs(start, graph, check);

	return 0;
}