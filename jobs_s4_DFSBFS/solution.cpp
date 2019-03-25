#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

int n, v;
queue<int> q;
vector<int> myGraph[MAX];
bool visit[MAX];
bool D[MAX];

void BFS() {

	q.push(0);
	visit[0] = true;

	while (!q.empty()) {
		int current = q.front();
		cout << current << ' ';
		q.pop();
		for (int i = 0; i < myGraph[current].size(); i++) {
			int next = myGraph[current][i];

			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

void DFS(int cur) {
	
	D[cur] = true;
	cout << cur << ' ';
	for (int i = 0; i < myGraph[cur].size(); i++) {
		int next = myGraph[cur][i];

		if (!D[next]) {
			DFS(next);
		}
	}
}

int main() {

	cin >> n >> v;

	for (int i = 0; i < v; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		myGraph[n1].push_back(n2);
		myGraph[n2].push_back(n1);
	}
	
	for (int i = 0; i < n; i++) {
		sort(myGraph[i].begin(), myGraph[i].end());
	}

	DFS(0);
	cout << '\n';
	BFS();
	cout << '\n';
	return 0;
}