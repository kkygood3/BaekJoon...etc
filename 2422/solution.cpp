	#include <iostream>
	using namespace std;

	int n, m;
	bool visit[250];
	bool hate[10100][10100];
	int ans = 0;

	void DFS(int cur, int select){

		if (cur == 3) {
			for (int i = 0; i < n; ++i) {
				if (visit[i]) {
					for (int j = i + 1; j < n; ++j) {
						if (visit[j]) {
							if (hate[i][j]) return;
						}
					}
				}
			}
			ans++;
			/*for (int i = 0; i < n; ++i) {
				cout << visit[i] << ' ';
			}
			cout << '\n';*/
			return;
		}

		for (int i = select; i < n; ++i) {
			if (!visit[i]) {
				visit[i] = true;
				DFS(cur + 1, i + 1);
				visit[i] = false;
			}
		}
	}

	int main() {

		cin >> n >> m;

		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			a -= 1;
			b -= 1;
			hate[a][b] = true;
			hate[b][a] = true;
		}

		DFS(0, 0);

		cout << ans << '\n';

		return 0;
	}