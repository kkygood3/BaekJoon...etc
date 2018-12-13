#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
bool visit[201];
int answer = 0;

void BFS(int i, vector<vector<int>> computers, int n) {

	q.push(i);
	visit[i] = true;
	
	while (!q.empty()) {

		int current = q.front();
		q.pop();
		for (int j = 0; j < n; ++j) {
			if (computers[current][j] == 1 && !visit[j]) {
				visit[j] = true;
				q.push(j);
			}
		}
	}

}

int solution(int n, vector<vector<int>> computers) {
	
	n = computers.size();

	for (int i = 0; i < n; ++i) {
		if (!visit[i]) {

			BFS(i, computers, n);
			answer++;

		}
	}
	
	return answer;
}