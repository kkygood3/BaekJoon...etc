#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int n, r;
int arr[MAX];
int tmp[MAX];
int temp[MAX];
bool D[1001];
bool D_[1001];
int max_ = 0;
void DFS(int cnt) {

	if (cnt > n) {
		return;
	}
	else {
		memcpy(temp,tmp,sizeof(tmp));
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 1 && D[i]) {
				for (int j = i - r + 1; j <= i + r - 1; i++) {
					temp[j] = 1;
				}
			}
		}

		max_ = max_ < cnt ? cnt : max_;
		for (int i = 1; i <= n; i++) {
			if (!temp[i]) return;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!D[cnt] && arr[i]) {
			D[cnt] = true;
			D_[i] = true;
			DFS(cnt + 1);
			D_[i] = false;
			D[cnt] = false;
		}
	}

}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n >> r;
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	cout << max_ << '\n';

	return 0;
}