#include <iostream>
#include <vector>
#define MAX 100000
using namespace std;

vector<int> myGraph[MAX];
bool D[MAX];
int cnt = 0;
void DFS(int cur) {

	D[cur] = true;
	
	for (int i = 0; i < myGraph[cur].size(); i++) {
		int next = myGraph[cur][i];

		if (!D[next]) {
			cnt++;
			DFS(next);
		}
	}

}

int main() {

	int n, v;
	cin >> n >> v;

	for (int i = 0; i < v; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		myGraph[n1].push_back(n2);
		myGraph[n2].push_back(n1);
	}

	DFS(1);

	cout << cnt << '\n';

	return 0;
}