#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int arr[15];
int tmp[15];
int f[15];
int d[15];
int n;
int ans = 0;
bool show;
string s;

bool hell;

inline int plus(int a, int b) { return a + b; }
inline int minus(int a, int b) { return a - b; }

inline int dot(int a, int b) {
	if ( b < 10) return (a * 10) + b;
	else if (b >= 10) return (a * 100) + b;
}

//inline int dot(int a, int b) {
//	if (a == 0) return b;
//	string a1, a2, tmp;
//	long int re;
//	a1 = to_string(a);
//	a2 = to_string(b);
//	tmp = a1 + a2;
//	re = stoi(tmp);
//	if (re >= 10000000) return 10000000;
//	return re;
//}

void DFS(int cur) {
	if (ans == 20) {
		show = true;
	}
	if (cur == n - 1) {
		int arr_hell[15];
		int f_hell[15];
		s = "1";
		hell = false;
		memcpy(tmp, arr, sizeof(arr));

		for (int i = 1; i < n; i++) {
			if (f[i - 1] == 0) {
				s += " + ";
			}
			else if (f[i - 1] == 1) {
				s += " - ";
			}
			else if (f[i - 1] == 2) {
				s += " . ";
				hell = true;
			}
			s += to_string(arr[i]);
		}

		if (hell) {
			for (int i = 0; i < n; i++) {
				if (f[i] == 2) {
					tmp[i + 1] = dot(tmp[i], tmp[i + 1]);
					tmp[i] = 0;
				}
			}
			int cnt = 0;
			for (int i = 0; i < n - 1; i++) {
				if (f[i] == 0) {
					f_hell[cnt] = 0;
					cnt++;
				}
				else if (f[i] == 1) {
					f_hell[cnt] = 1;
					cnt++;
				}
			}
			cnt = 0;
			for (int i = 0; i < n; i++) {
				if (tmp[i] != 0) {
					arr_hell[cnt] = tmp[i];
					cnt++;
				}
			}
			for (int i = 1; i < cnt; i++) {
				if (f_hell[i - 1] == 0) {
					arr_hell[i] += arr_hell[i - 1];
				}
				if (f_hell[i - 1] == 1) {
					arr_hell[i] = arr_hell[i - 1] - arr_hell[i];
				}
			}
			if (arr_hell[cnt - 1] == 0) {
				ans++;
				if(!show) cout << s << '\n';
				return;
			}
		}
		else {
			for (int i = 1; i < n; i++) {
				if (f[i - 1] == 0) {
					tmp[i] += tmp[i - 1];
				}
				if (f[i - 1] == 1) {
					tmp[i] = tmp[i - 1] - tmp[i];
				}
			}

			if (tmp[cur] == 0) {
				ans++;
				if (!show) cout << s << '\n';
				return;
			}
		}

		
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (!d[cur]) {
			d[cur] = 1;
			f[cur] = i;
			DFS(cur + 1);
			d[cur] = 0;
		}
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	DFS(0);
	cout << ans << '\n';
	return 0;
}