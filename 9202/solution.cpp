#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct Answer {
	long long a;
	string b;
	long long c;
};

map<string, bool> m;
vector<Answer> final;
int w, b;
vector<string> v;
char arr[4][4];
int d_row[8] = { -1,1,0,0,1,1,-1,-1 };
int d_col[8] = { 0,0,-1,1,-1,1,-1,1 };
int Rank[9] = { 0,0,0,1,1,2,3,5,11 };	// 단어 갯수, 최대 점수
bool visit[4][4];
string ans;
bool sw;
Answer answer;

bool compare(string a, string b) {

	if (a.size() != b.size()) return a.size() > b.size();
	else return a < b;

}

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= 4 || col >= 4) return false;
	return true;
}

void DFS(int row, int col, int cur, int v_num, int sz) {
	
	visit[row][col] = true;

	if (cur == sz) {
		sw = true;
		answer.c++;
		answer.a += Rank[sz];
		if (!answer.b.compare("x")) {
			answer.b = v[v_num];
		}
		visit[row][col] = false;
		return;
	}

	for (int i = 0; i < 8; ++i) {
		if (sw) {
			visit[row][col] = false;
			return;
		}
	
		int next_row = row + d_row[i];
		int next_col = col + d_col[i];
		if (check(next_row, next_col) && !visit[next_row][next_col]) {
			if (arr[next_row][next_col] == v[v_num][cur]) DFS(next_row, next_col, cur + 1, v_num, sz);
		}
		
	}
	visit[row][col] = false;
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> w;
	for (int i = 0; i < w; ++i) {
		string s;
		cin >> s;
		if(!m[s]) v.push_back(s);
		m.insert(make_pair(s, true));
	}

	sort(v.begin(), v.end(), compare);

	cin >> b;

	for (int i = 0; i < b; ++i) {
		answer.a = 0;
		answer.b = "x";
		answer.c = 0;
		cin.clear();
		for (int row = 0; row < 4; ++row) {
			for (int col = 0; col < 4; ++col) {
				cin >> arr[row][col];
			}
		}

		for (int v_num = 0; v_num < w; ++v_num) {
			sw = false;
			int sz = v[v_num].size();
			for (int row = 0; row < 4; ++row) {
				for (int col = 0; col < 4; ++col) {
					if (sw) break;
					if (arr[row][col] == v[v_num][0]) DFS(row, col, 1, v_num, sz);
				}
			}
		}

		final.push_back(answer);

	}

	int sz = final.size();

	for (int i = 0; i < sz; ++i) {
		cout << final[i].a << ' ' << final[i].b << ' ' << final[i].c << '\n';
	}

	return 0;
}