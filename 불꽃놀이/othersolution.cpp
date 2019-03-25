//#include <iostream>
//#include <vector>
//#include <utility>
//#include <queue>
//using namespace std;
//
//vector<pair<int, int>> node[20001];	// node[a] = (b,c)	a 노드 b노드 c 가중치
//vector<long long> ans;
//queue<pair<int, long long>> q;	// node, 현재 가중치
//bool visit[20001];
//bool visit_DFS[20001];
//bool cal[20001];
//bool return_sw;
//long long cost;
//int n;
//int max_dis;
//int cur_max_dis;
//int cur_max_index;
//
//void DFS(int cur, int dis, int pre_dis) {
//
//	if (cur > n && cal[cur] && !return_sw && cur_max_dis > 0) {
//
//		if (cur == n * 2) max_dis = cur_max_dis;
//		//cout << "return" << '\n';
//		return_sw = true;
//		cost += max_dis - cur_max_dis;
//		//cout << max_dis - cur_max_dis << " 돈 씀" << '\n';
//		//cout << cost << '\n';
//		int sz = node[cur].size();
//		for (int i = 0; i < sz; ++i) {
//			if (node[cur][i].first == pre_dis) {	// 오기 전 노드와의 가중치에 max - 시작한 거리
//
//				node[cur][i].second += max_dis - cur_max_dis;
//				int siz = node[node[cur][i].first].size();
//				for (int j = 0; j < siz; ++j) {
//					if (node[node[cur][i].first][j].first == cur) {
//						//cout << node[cur][i].first << "<->" << cur << "가중치 + " << max_dis - cur_max_dis << '\n';
//						node[node[cur][i].first][j].second += max_dis - cur_max_dis;
//					}
//				}
//			}
//		}
//		return;
//	}
//
//	int sz = node[cur].size();
//	for (int i = 0; i < sz; ++i) {
//		int next = node[cur][i].first;
//		int n_dis = dis - node[cur][i].second;
//		if (!visit_DFS[next] && ) {
//			visit_DFS[next] = true;
//			DFS(next, n_dis, cur);
//			visit_DFS[next] = false;
//			if (return_sw) {
//				cal[cur] = true;
//				return;
//			}
//		}
//	}
//
//}
//
//void BFS(int start) {
//
//	q.push(make_pair(start, 0));
//	visit[start] = true;
//	cal[start] = true;
//
//	while (!q.empty()) {
//		int cur = q.front().first;
//		int dis = q.front().second;
//		q.pop();
//		if (cur <= n && dis > cur_max_dis && !cal[cur]) {
//			cur_max_dis = dis;
//			cur_max_index = cur;
//		}
//
//		int sz = node[cur].size();
//		for (int i = 0; i < sz; ++i) {
//			int next = node[cur][i].first;
//			int n_dis = dis + node[cur][i].second;
//			if (!visit[next]) {
//				visit[next] = true;
//				q.push(make_pair(next, n_dis));
//			}
//		}
//
//	}
//
//}
//
//void BFS_cal(int start) {
//
//	q.push(make_pair(start, 0));
//	visit[start] = true;
//
//	while (!q.empty()) {
//		int cur = q.front().first;
//		int dis = q.front().second;
//		q.pop();
//
//		int sz = node[cur].size();
//		for (int i = 0; i < sz; ++i) {
//			int next = node[cur][i].first;
//			int n_dis = dis + node[cur][i].second;
//			if (!visit[next] && ((cal[next] && next >= n * 2) || (!cal[next] && next <= n))) {
//				if (!cal[next] && next <= n) {
//					cal[next] = true;
//					cost += max_dis - n_dis;
//				}
//				visit[next] = true;
//				q.push(make_pair(next, n_dis));
//			}
//		}
//
//	}
//}
//
//void init() {
//	for (int i = 0; i <= 2 * n; ++i) {
//		node[i].clear();
//		visit_DFS[i] = false;
//		cal[i] = false;
//	}
//	while (!q.empty()) q.pop();
//}
//
//int main() {
//
//	cin.tie(0); ios::sync_with_stdio(0);
//	int t;
//	cin >> t;
//
//	for (int tc = 0; tc < t; ++tc) {
//
//		cin >> n;
//		cost = 0;
//
//		for (int i = 0; i < 2 * n - 1; ++i) {
//			int a, b, c;
//			cin >> a >> b >> c;
//			node[a].push_back(make_pair(b, c));
//			node[b].push_back(make_pair(a, c));
//		}
//		while (1) {
//			cur_max_dis = 0;
//			return_sw = false;
//			BFS(2 * n);
//			for (int i = 0; i <= 2 * n; ++i) visit[i] = false;
//			DFS(cur_max_index, cur_max_dis, 0);
//			if (cur_max_dis == 0) break;
//			BFS_cal(2 * n);
//		}
//
//		ans.push_back(cost);
//		init();
//
//	}
//
//	for (int tc = 0; tc < t; ++tc) cout << "#" << tc + 1 << " " << ans[tc] << '\n';
//
//	return 0;
//}