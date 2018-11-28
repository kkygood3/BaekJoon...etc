#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> Graph[MAX];
bool D[MAX];
int idx = 1;

int check(int n) {
	for (int i = idx; i <= n; i++) {
		if (!D[i]) {
			idx = i;
			return i;
		}
	}
	return 0;
}

void DFS(int cur) {

	for (int i = 0; i < Graph[cur].size(); i++) {
		int next = Graph[cur][i];
		if (!D[next]) {
			D[next] = true;
			DFS(next);
		}
	}

}

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	D[1] = true;
	DFS(1);
	int cnt = 1;
	while (check(n)) {
		if (Graph[idx].empty()) {
			D[idx] = true;
			cnt++;
		}
		else {
			DFS(idx);
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}