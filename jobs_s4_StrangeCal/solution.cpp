#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int n;
queue<int> q;
bool visit[MAX];

bool check_mul(int num) {
	if (num * 2 >= MAX) return false;
	if (visit[num * 2]) return false;
	else return true;
}

bool check_div(int num) {

	if (visit[num / 3]) return false;
	else return true;
}

void BFS() {

	q.push(1);
	visit[1] = true;
	int cnt = 0;
	while (!q.empty()) {
		int qs = q.size();
		for (int sz = 0; sz < qs; sz++) {
			int cur = q.front();
			if(cur == n){
				cout << cnt << '\n';
				return;
			}
			q.pop();
			if (cur >= MAX) break;

			if (check_mul(cur) && cur * 2) {
				q.push(cur * 2);
				visit[cur * 2] = true;
			}
			if (check_div(cur)) {
				q.push(cur / 3);
				visit[cur / 3] = true;
			}

		}
		cnt++;
	}
}

int main() {

	cin >> n;
	
	BFS();

	return 0;
}