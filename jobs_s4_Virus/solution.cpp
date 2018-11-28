#include <iostream>
#include <queue>
#define MAX 100000

using namespace std;

bool visit[MAX + 1];
int n, k;
queue<int> q;

bool check_mul(int num) {
	if (num * 2 > n) return false;
	if (visit[num * 2]) return false;
	else return true;
}

bool check_div(int num) {

	if (visit[num / 3]) return false;
	else return true;
}

void BFS(int start) {

	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (check_mul(cur) && cur * 2) {
			q.push(cur * 2);
			visit[cur * 2] = true;
		}
		if (check_div(cur)) {
			q.push(cur / 3);
			visit[cur / 3] = true;
		}

	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> k;

	BFS(k);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}