#include <iostream>
#define MAX 102
#include <vector>
#include <cstring>
using namespace std;

int n;
int Graph[MAX];
int arr[MAX];
bool visit[MAX];
bool visit_[MAX];
bool D[MAX];
int sum = 0;
int idx;

void DFS(int cur, int level, int first) {

	if (!D[cur]) {
		D[cur] = true;
		int next = Graph[cur];
		if (next == first) {
				sum += level + 1;
				idx = first;
				for (int i = 1; i <= n; i++) {
					if (D[i]) visit[i] = true;
				}
				return;
		}
		DFS(next, ++level, first);
		
	}
	
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> Graph[i];
	}
	DFS(1, 0, 1);
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			memcpy(D, visit, sizeof(visit));
			DFS(i, 0, i);
		}
	}
	cout << sum << '\n';
	for (int i = 1; i <= n; i++) {
		if(visit[i]) cout << i << ' ';
	}
	cout << '\n';

	return 0;
}