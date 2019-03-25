#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int r, n;
int cur_time;
int end_time;
vector<int> ans;
int arr[11][11];

struct Item {

	int p1;
	int p2;
	int t1;
	int t2;
	int state = 0;			// 0 : 배송 전, 1 : 배송 중, 2 : 배송 완료

};

vector<Item> v;

bool compare(Item a, Item b) {

	int t_a, t_b, mov_a, mov_b;

	if (a.state == 0) {
		t_a = a.t1;
		mov_a = a.p1;
	}
	else {
		t_a = a.t2;
		mov_a = a.p2;
	}
	if (b.state == 0) {
		t_b = b.t1;
		mov_b = b.p1;
	}
	else {
		t_b = b.t2;
		mov_b = b.p2;
	}

	return abs(t_a - mov_a) < abs(t_b - mov_b);
}

void DFS(int index, int cur, int ship, int carry) {		// 현 위치, 현재 시간

	if (cur >= end_time) return;

	if (arr[ship][carry] < cur) return;
	if (arr[ship][carry] > cur) arr[ship][carry] = cur;

	if (ship == n) {
		if (cur < end_time) end_time = cur;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (v[i].state == 2) continue;						// 배송 끝난거면 No
		else if (v[i].state == 1) {
			int move_time = abs(index - v[i].p2);
			if (cur + move_time > v[i].t2) continue;		// 배송 중 제한 시간 초과하면 No
			else {
				//cout << i + 1 << "번째 배송 완료, 현재 배송 완료 : " << ship + 1 << ", 현재 배송 중 : " << carry - 1 << "		완료 시간 : " << cur + move_time << '\n';
				v[i].state = 2;
				DFS(v[i].p2, cur + move_time, ship + 1, carry - 1);
				v[i].state = 1;

			}
		}
		else if (v[i].state == 0) {
			int move_time = abs(index - v[i].p1);
			if (cur + move_time > v[i].t2) continue;		// 물품 찾으러 가기전 제한 시간 초과하면 No
			else {
				//cout << i + 1 << "번째 배송 시작, 현재 배송 완료 : " << ship << ", 현재 배송 중 : " << carry + 1 << "		완료 시간 : " << (cur + move_time < v[i].t1 ? v[i].t1 : cur + move_time) << '\n';
				v[i].state = 1;
				DFS(v[i].p1, (cur + move_time < v[i].t1 ? v[i].t1 : cur + move_time), ship, carry + 1);
				v[i].state = 0;

			}
		}
	}

}


int main() {

	int t;
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		cin >> r >> n;
		end_time = 2100000000;

		for (int i = 0; i < n; ++i) {
			Item item;
			int p1, p2, t1, t2;
			cin >> p1 >> p2 >> t1 >> t2;

			item.p1 = p1;
			item.p2 = p2;
			item.t1 = t1;
			item.t2 = t2;

			v.push_back(item);
		}


		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				arr[i][j] = 2100000000;
			}
		}

		sort(v.begin(), v.end(), compare);			//t2 순서대로 정렬

		DFS(r, 0, 0, 0);

		if (end_time != 2100000000) ans.push_back(end_time);
		else ans.push_back(-1);



		v.clear();
	}

	for (int tc = 0; tc < t; ++tc) cout << "#" << tc + 1 << " " << ans[tc] << '\n';

	return 0;
}