#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define null 0
using namespace std;

int n;
queue<int> q;
bool visit[20001];
vector<pair<int,int>> node[20001];		// 연결 노드, 가중치
vector<long> ans;

struct Tree {				

	int dis = 0;		// 가중치
	int index = 0;
	Tree* left = null ;
	Tree* right = null;
	Tree* parent = null;
	long path = 0;		// 해당노드에서 리프까지의 최장경로
	long sum = 0;		// 해당노드에서 리프들까지 최장경로로 바꿨을 때 합
};

Tree T_node[20001];

void BFS(int start) {
	q.push(start);
	visit[start] = true;
	T_node[start].index = start;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int sz = node[cur].size();
		for (int i = 0; i < sz; ++i) {
			int next = node[cur][i].first;
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
				if(T_node[cur].left == null) T_node[cur].left = &T_node[next];
				else T_node[cur].right = &T_node[next];
				T_node[next].index = next;
				T_node[next].parent = &T_node[cur];
				T_node[next].dis = node[cur][i].second;
			}
		}
	}
}

long PATH(int root) {
	
	if (root <= n) return 0;

	T_node[root].path = max(PATH(T_node[root].left->index) + T_node[root].left->dis, PATH(T_node[root].right->index) + T_node[root].right->dis);
	return T_node[root].path;
}

long SUM(int root) {

	if (root <= n) return 0;

	T_node[root].sum = SUM(T_node[root].left->index) + SUM(T_node[root].right->index) + (T_node[root].path - T_node[root].left->path) + (T_node[root].path - T_node[root].right->path);
	
	return T_node[root].sum;
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;

	for (int tc = 0; tc < t; ++tc) {

		cin >> n;

		for (int i = 0; i < n * 2 - 1; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			node[a].push_back(make_pair(b, c));
			node[b].push_back(make_pair(a, c));
		}

		BFS(2 * n);

		for (int i = 1; i <= 2 * n; ++i) {
			visit[i] = false;
		}
		/*for (int i = 1; i <= 2 * n - 1; ++i) {
			cout << i << "번 째 가중치" << T_node[i].dis << " 부모는" << T_node[i].parent->index << '\n';
			if (T_node[i].left != 0) cout << i << "번 째 왼쪽 자식" << T_node[i].left->index << '\n';
			if (T_node[i].right != 0) cout << i << "번 째 오른쪽 자식" << T_node[i].right->index << '\n';
		}*/
		int root = T_node[2 * n].left->index;
		T_node[root].path = PATH(root);
		T_node[root].sum = SUM(root);

		/*for (int i = 1; i <= 2 * n - 1; ++i) cout << i << "번 째 가중치 : " << T_node[i].dis << '\n';
		for (int i = 1; i <= 2 * n - 1; ++i) cout << i << "번 째 SUM : " << T_node[i].sum << '\n';*/

		long tmp = 0;
		for (int i = 1; i <= 2 * n - 1; ++i) if (i != root) tmp += T_node[i].dis;

		ans.push_back(T_node[root].sum - tmp);



		for (int i = 1; i <= 2 * n; ++i) {
			visit[i] = false;
			node[i].clear();
		}
		memset(T_node, 0, sizeof(T_node));
	}

	for (int tc = 0; tc < t; ++tc) cout << "#" << tc + 1 << " " << ans[tc] << '\n';

	return 0;
}