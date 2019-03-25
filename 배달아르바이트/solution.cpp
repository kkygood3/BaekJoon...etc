#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> node[1010];		// 마을 간 연결 된 노드
int dist[1010][1010];	// 배달해야 하는 장소끼리 간 거리
vector<int> arr;	// 배달해야 하는 장소
vector<int> arr_tmp;
vector<int> ans;
int n, m, s, k;		// 마을수 , 연결 도로 수, 배달 해야하는 마을 수, 가게 번호
queue<int> q;
bool visit_d[1010]; // 배달해야하는 마을
bool visit[1010];
bool visit_DFS[1010];
int min_ans = 99999999;

void BFS(int start) {
	q.push(start);
	visit[start] = true;
	int dis = 1;
	while (!q.empty()) {
		int sz = q.size();
		for (int qs = 0; qs < sz; ++qs) {
			int cur_node = q.front();
			q.pop();
			int node_sz = node[cur_node].size();
			for (int i = 0; i < node_sz; ++i) {
				int next_node = node[cur_node][i];
				if (!visit[next_node]) {
					visit[next_node] = true;
					if (visit_d[next_node]) {
						dist[next_node][start] = dis;
						dist[start][next_node] = dis;
					}
					q.push(next_node);
				}
			}
		}
		dis++;
	}
}

void init() {

	for (int i = 0; i <= n; ++i) {
		node[i].clear();
		visit[i] = false;
	}

	arr.clear();
	arr_tmp.clear();
	min_ans = 99999999;

}

void DFS(int cur, int sz) {

	if (cur == 2) {
		arr_tmp.push_back(k);
		int sum = 0;
		
		for (int i = 0; i < arr_tmp.size() - 1; ++i) {
			sum += dist[arr_tmp[i]][arr_tmp[i + 1]];
		}

		if (sum < min_ans) min_ans = sum;

		arr_tmp.pop_back();
		return;
	}


	for (int i = 1; i < sz - 1; ++i) {
		if (!visit_DFS[arr[i]]) {
			visit_DFS[arr[i]] = true;
			arr_tmp.push_back(arr[i]);
			
			DFS(cur - 1, sz);
			
			visit_DFS[arr[i]] = false;
			arr_tmp.pop_back();
		}
	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		cin >> n >> m >> s >> k;
		arr.push_back(k);
		for (int i = 0; i < s; ++i) { 
			int tmp;
			cin >> tmp;
			arr.push_back(tmp);
			visit_d[tmp] = true;
		}
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			node[a].push_back(b);
			node[b].push_back(a);
		}

		int sz = arr.size();
		for (int i = 0; i < sz; ++i) {
			BFS(arr[i]);
			
			for (int i = 1; i <= n; ++i) visit[i] = false;
		}

		/*for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				cout << arr[i] << " 와 " << arr[j] << "의 최소 거리 : " << dist[arr[i]][arr[j]] << '\n';
			}
		}*/

		arr.push_back(k); // 배열을 k ... k로 만든다.

		sz = arr.size();

		arr_tmp.push_back(k);	// k ... k 로 조합 짤 벡터
		DFS(sz , sz);
		
		ans.push_back(min_ans);

		init();
	}

	for (int tc = 0; tc < t; ++tc) cout << "#" << tc + 1 << " " << ans[tc] << '\n';

	return 0;
}