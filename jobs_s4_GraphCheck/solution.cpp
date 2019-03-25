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
int color[MAX];

void BFS() {

	q.push(1);
	visit[1] = true;
	color[1] = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < myGraph[current].size(); i++) {
			int next = myGraph[current][i];

			if (!visit[next] && !color[next]) {
				visit[next] = true;
				color[next] = color[current] * -1;
				q.push(next);
			}
			if (color[next]) {
				if (color[current] == color[next]) {
					cout << "No" << '\n';
					return;
				}
			}
		}
	}
	cout << "Yes" << '\n';
	return;
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

	BFS();

	return 0;
}