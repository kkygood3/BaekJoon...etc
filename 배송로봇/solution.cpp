//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//int r, n, p1, p2, t1, t2;
//int max_time;
//vector<int> ans;
//int tc_ans;
//vector<int> comp;
//int complex = 0;
//
//struct A {
//	int s;
//	int d;
//	int s_t;
//	int d_t;
//	bool carry = false;
//	bool goal = false;
//	int c_t = 0;
//	int g_t = 0;
//	int lim_c = 2100000000;
//	int lim_d = 2100000000;
//};
//
//vector<A> v;
//
//void DFS(int cur, int time, int goal_cnt) {
//	complex++;
//	if (time > max_time) {
//		for (int i = 0; i < n; ++i) {
//			if (v[i].lim_c > v[i].c_t && v[i].carry) v[i].lim_c = v[i].c_t;
//			if (v[i].lim_d > v[i].g_t && v[i].goal) v[i].lim_d = v[i].g_t;
//		}
//		return;
//	}
//	if (time >= tc_ans) {
//		for (int i = 0; i < n; ++i) {
//			if (v[i].lim_c > v[i].c_t && v[i].carry) v[i].lim_c = v[i].c_t;
//			if (v[i].lim_d > v[i].g_t && v[i].goal) v[i].lim_d = v[i].g_t;
//		}
//		return;
//	}
//	if (goal_cnt == n) {
//		//cout << "��� ���� �ð� " << time << '\n';
//		for (int i = 0; i < n; ++i) {
//			if (v[i].lim_c > v[i].c_t) v[i].lim_c = v[i].c_t;
//			if (v[i].lim_d > v[i].g_t) v[i].lim_d = v[i].g_t;
//		}
//		tc_ans = time;
//		return;
//	}
//
//	if (time > comp[goal_cnt]) {
//
//		return; // ���� �ð��� ���� �ؾ��� �ͺ��� �ʾ����� ����
//	}
//
//	for (int i = 0; i < n; ++i) {
//		int n_start;
//		int n_time;
//		if (!v[i].carry) {
//			
//			v[i].c_t = time;
//			n_start = v[i].s;
//			n_time = time + (abs(cur - v[i].s));		// �ش� ��ġ ���� �ð�
//			if (v[i].lim_c < time) continue;		// ��¦ ����!
//			if (n_time < v[i].s_t) n_time = v[i].s_t;	// �����ߴµ� �ð��� ������ ��ٸ�
//			//cout << i + 1 << " ��° " << time << "�ð��� " << "carry����" << "���� ��ۿϷ� : " << goal_cnt << '\n';
//			v[i].carry = true;
//			DFS(n_start, n_time, goal_cnt);
//			v[i].carry = false;
//		}
//
//		else if (!v[i].goal) {
//
//			v[i].g_t = time;
//			n_start = v[i].d;
//			n_time = time + (abs(cur - v[i].d));		// �ش� ��ġ ���� �ð�
//
//			if (v[i].lim_d < time) continue;		// ��¦ ����!
//			if (n_time > v[i].d_t) {	// �����ߴµ� �ð��� �Ѿ����� �ȵǴ� ��� �����ϰ� ����
//				continue;
//			}
//			//cout << i + 1 << " ��° " << n_time << "�ð��� " << "��� ��" << "���� ��ۿϷ� : " << goal_cnt << '\n';
//
//			v[i].goal = true;
//			DFS(n_start, n_time, goal_cnt + 1);
//			v[i].goal = false;
//		}
//	}
//
//}
//
//int main() {
//
//	cin.tie(0); ios::sync_with_stdio(0);
//	int t;
//	cin >> t;
//
//	for (int tc = 0; tc < t; ++tc) {
//		cin >> r >> n;
//		
//		tc_ans = 2100000000;
//		max_time = 0;
//		//complex = 0;
//
//		for (int i = 0; i < n; ++i) {
//			cin >> p1 >> p2 >> t1 >> t2;
//			A a;
//			a.s = p1;
//			a.d = p2;
//			a.s_t = t1;
//			a.d_t = t2;
//			v.push_back(a);
//			comp.push_back(t2); 
//			if (t2 > max_time) max_time = t2;
//		}
//
//		sort(comp.begin(), comp.end());		// �ð� ����
//
//		DFS(r, 0, 0);
//
//		if(tc_ans != 2100000000) ans.push_back(tc_ans);
//		else ans.push_back(-1);
//		//cout << complex << '\n';
//		v.clear();
//		comp.clear();
//	}
//
//	for (int tc = 0; tc < t; ++tc) cout << "#" << tc + 1 << " " << ans[tc] << '\n';
//
//	return 0;
//}