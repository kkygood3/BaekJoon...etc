#include <iostream>
#include <vector>
#define MAX 1000010
using namespace std;

vector<long int> ans;
long int arr[MAX];
bool visit[MAX];
int n;

void init() {

	for (int i = 0; i < n; ++i) {
		visit[i] = false;
	}
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	
	int t;

	cin >> t;

	for (int tc = 0; tc < t; ++tc) {
		cin >> n;
		init();

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		while (1) {
			int max = -1;
			int index;	

			for (int i = 0; i < n; ++i) {
				if (!visit[i] && max <= arr[i]) {
					max = arr[i];
					index = i;
				}
			}

			if (max == -1) break;

			for (int i = 0; i <= index; ++i) {
				if (!visit[i]) {
					arr[i] = max - arr[i];
					visit[i] = true;
				}
			}
		}
		long int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += arr[i];
		}
		ans.push_back(sum);


	}


	int sz = ans.size();
	for (int i = 0; i < sz; ++i) {
		cout << "#" << i + 1 << " " << ans[i] << '\n';
	}


	return 0;
}