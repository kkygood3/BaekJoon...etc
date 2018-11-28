//DFS BFS ±¸Çö
#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

queue <int> Queue;
vector <int> myGraph[MAX];
int n, v;
bool visit[MAX];
bool D[MAX];

void BFS() {
	
	Queue.push(1);
	visit[1] = true;

	while (!Queue.empty())
	{
		int current = Queue.front();
		Queue.pop();
		cout << current << ' ';
		for (int i = 0; i < myGraph[current].size(); i++) {
			int next = myGraph[current][i];
			if (!visit[next]) {
				visit[next] = true;
				Queue.push(next);
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
			D[next] = true;
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

	BFS();
	cout << '\n';
	DFS(1);
	return 0;
}