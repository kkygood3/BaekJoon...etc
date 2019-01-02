//#include <iostream>
//#include <vector>
//#include <utility>
//#include <queue>
//using namespace std;
//
//vector<pair<int,int>> node[20001];	// node[a] = (b,c)	a 노드 b노드 c 가중치
//vector<long long> ans;
//queue<pair<int,long long>> q;	// node, 현재 가중치
//bool visit[20001];
//long long max_visit[20001];
//bool max_visit_sw;
//int n;
//long long max_dis;
//int max_node;
//long long next_max_dis;
//int next_max_node;
//long long tc_ans;
//long long share;
//	
//void BFS_MAX(int start) {
//
//	q.push(make_pair(start,0));
//	visit[start];
//
//	while (!q.empty()) {
//		int cur = q.front().first;
//		int dis = q.front().second;
//		q.pop();
//		int sz = node[cur].size();
//		for (int i = 0; i < sz; ++i) {
//			int next_cur = node[cur][i].first;
//			int next_dis = dis + node[cur][i].second;
//			if (!visit[next_cur] && !max_visit[next_cur]) {
//				visit[next_cur] = true;
//				q.push(make_pair(next_cur, next_dis));
//				if (next_dis > max_dis) {
//					max_node = next_cur;
//					max_dis = next_dis;
//				}
//
//			}
//		}
//	}
//
//}
//
//void BFS(int start) {
//
//	q.push(make_pair(start, 0));
//	visit[start];
//	
//	while (!q.empty()) {
//		int cur = q.front().first;
//		int dis = q.front().second;
//		q.pop();
//		int sz = node[cur].size();
//		for (int i = 0; i < sz; ++i) {
//			int next_cur = node[cur][i].first;
//			int next_dis = dis + node[cur][i].second;
//			if (!visit[next_cur] && !(next_cur <= n && max_visit[next_cur])) {
//				visit[next_cur] = true;
//				q.push(make_pair(next_cur, next_dis));
//				if (next_dis > next_max_dis) {
//					next_max_node = next_cur;
//					next_max_dis = next_dis;
//				}
//
//			}
//		}
//	}
//}
//
//void DFS_MAX(int cur, long long dis) {
//	
//	if (cur == n * 2) {
//		max_visit_sw = true;
//		max_visit[cur] = true;
//		return;
//	}
//
//	int sz = node[cur].size();
//	for (int i = 0; i < sz; ++i) {
//		int next = node[cur][i].first;
//		long long minus = dis - node[cur][i].second;
//		if (!visit[next] && next > n) {
//			visit[next] = true;
//			DFS_MAX(next, minus);
//			visit[next] = false;
//			if (max_visit_sw) {
//				max_visit[next] = minus;
//				int sz = node[next].size();
//				for (int i = 0; i < sz; ++i) {
//					if (node[next][i].first <= n && !max_visit[node[next][i].first]) {
//						max_visit[node[next][i].first] = 1;
//						tc_ans += (max_dis - minus - node[next][i].second);
//						//cout << "더함" << (max_dis - minus - node[next][i].second - share);
//					}
//				}
//				return;
//			}
//		}
//	}
//}
//
//void DFS(int cur, long long dis) {
//
//	if (max_visit[cur] && cur >= n) {
//		max_visit_sw = true;
//		int sz = node[cur].size();
//		for (int i = 0; i < sz; ++i) {
//			if (!max_visit[node[cur][i].first]) {
//				//cout << cur << "과" << node[cur][i].first << "에 가중치 " << max_dis - next_max_dis << "만큼 증가하고 비용 증가" << '\n';
//				node[cur][i].second += max_dis - next_max_dis;
//				int ssz = node[node[cur][i].first].size();
//				for(int j = 0; j < ssz; ++j) if(node[node[cur][i].first][j].first == cur)node[node[cur][i].first][j].second += max_dis - next_max_dis;
//				tc_ans += max_dis - next_max_dis;
//				share = max_dis - next_max_dis;
//				max_visit[node[cur][i].first] = true;
//			}
//		}
//		return;
//	}
//
//	int sz = node[cur].size();
//	for (int i = 0; i < sz; ++i) {
//		int next = node[cur][i].first;
//		long long minus = dis - node[cur][i].second;
//		if (!visit[next] && next > n) {
//			visit[next] = true;
//			DFS(next, minus);
//			visit[next] = false;
//			if (max_visit_sw) {
//				max_visit[next] = minus;
//				int sz = node[next].size();
//				for (int i = 0; i < sz; ++i) {
//					if (node[next][i].first <= n && !max_visit[node[next][i].first]) {
//						max_visit[node[next][i].first] = 1;
//						tc_ans += (max_dis - minus - node[next][i].second - share);
//						//cout << "더함" << (max_dis - minus - node[next][i].second - share);
//					}
//				}
//				return;
//			}
//		}
//	}
//}
//
//int main() {
//
//	cin.tie(0); ios::sync_with_stdio(0);
//	int t;
//	cin >> t;
//
//	for (int tc = 0; tc < t; ++tc) {
//		max_dis = 0;	// 최대 길이
//		cin >> n;
//		tc_ans = 0;
//		share = 0;
//
//		for (int i = 0; i < 2 * n - 1; ++i) {
//			int a, b, c;
//			cin >> a >> b >> c;
//			node[a].push_back(make_pair(b, c));
//			node[b].push_back(make_pair(a, c));
//		}
//		
//		BFS_MAX(2 * n);
//		for (int i = 0; i <= 2 * n; ++i) visit[i] = false;	// 초기화
//		//cout << "최대값 : " << max_node << '\n';
//
//		max_visit_sw = false;	//DFS안에서 도착 확인
//		DFS_MAX(max_node, max_dis);
//		max_visit[max_node] = true;
//
//		next_max_dis = 0;
//		
//		int cnt = 0;
//		while (1) {
//			BFS(2 * n);
//			if (max_visit[next_max_node]) {
//				for (int i = 0; i <= 2 * n; ++i) visit[i] = false;	// 초기화
//				break;
//			}
//			//cout << "최대값 : " << next_max_node << '\n';
//
//			for (int i = 0; i <= 2 * n; ++i) visit[i] = false;	// 초기화
//
//			max_visit_sw = false;	//DFS안에서 도착 확인
//			DFS(next_max_node, next_max_dis);
//			max_visit[next_max_node] = true;
//			next_max_dis = 0;
//		}
//
//
//		ans.push_back(tc_ans);
//
//		for (int i = 0; i <= 2 * n; ++i) {
//			node[i].clear();
//			max_visit[i] = 0;
//
//		}
//
//	}
//
//	for (int tc = 0; tc < t; ++tc) cout << "#" << tc + 1 << ' ' << ans[tc] << '\n';
//
//	return 0;
//}