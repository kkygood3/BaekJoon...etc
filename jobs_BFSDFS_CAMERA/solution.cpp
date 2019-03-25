#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 1001
using namespace std;

int g, h;
vector<int> Graph[MAX];
queue<int> q;
bool visit[MAX];
bool bright[MAX];
int sum = 0;

void BFS(int cur) {

	while (!q.empty())q.pop();
	int cnt = 0;
	if (Graph[cur].empty()) {
		sum++;
		return;
	}
	visit[cur] = true;
	q.push(cur);

	while (!q.empty()) {
		int qs = q.size();
		for (int sz = 0; sz < qs; sz++) {
			int current = q.front();
			q.pop();
			for (int i = 0; i < Graph[current].size(); i++) {
				int next = Graph[current][i];
				if (!visit[next]) {
					if (Graph[next].size() != 0)
					q.push(next);
					visit[next] = true;
				}
				if (!bright[next] && Graph[next].size()) {
					cnt++;
					bright[current]
				}
			}
		}
	}

	sum += cnt;

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> g >> h;

	for (int i = 0; i < h; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		Graph[v1].push_back(v2);
		Graph[v2].push_back(v1);
	}

	for (int i = 0; i < g; i++) {
		if (!visit[i]) BFS(i);
	}

	cout << sum << '\n';

	return 0;
}