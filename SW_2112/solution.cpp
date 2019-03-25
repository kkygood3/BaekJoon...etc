#include <iostream>
#include <vector>
#include <cstring>
#define MAX 20
using namespace std;

int t, d, w, k;
vector<int> ans;
bool arr[MAX][MAX];
bool temp[MAX][MAX];
bool D[MAX];
bool dep[MAX];
int min_cur = 999;
bool isA;

bool force_check(int d, int w, int k) {

	for (int col = 0; col < w; col++) {
		int cnt = 1;
		int max_cnt = 0;
		for (int row = 0; row < d - 1; row++) {
			if (arr[row][col] != arr[row + 1][col]) cnt = 1;
			else cnt++;

			if (max_cnt < cnt) max_cnt = cnt;
		}
		if (max_cnt < k) return false;
	}
	return true;
}

bool check(int cur, int i) {

	if (D[cur]) return false;
	
	return true;
}

void change_on(bool isA, int idx) {
	
	if (isA) {
		for (int i = 0; i < w; i++) {

			arr[idx][i] = true;

		}
	}
	else {
		for (int i = 0; i < w; i++) {

			arr[idx][i] = false;

		}
	}
}

void change_off(bool isA, int idx) {

		
	for (int i = 0; i < w; i++) {

		arr[idx][i] = temp[idx][i];

	}

}

void DFS(int cur, int idx, int x) {

	if (min_cur < 999) return;
	if (idx > d) return;
	

	if (cur == x) {
		/*cout << '\n';
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}*/
		

		if (force_check(d, w, k) && min_cur > cur) {
			min_cur = cur;
			//cout << min_cur << "----------------------------------------------\n";
			return;
		}
		return;
	}

	
		D[idx] = true;
		change_on(isA, idx);

		DFS(cur + 1, idx + 1, x);

		D[idx] = false;
		change_off(isA, idx);

		DFS(cur, idx + 1, x);

}

void init() {

	for (int i = 0; i < d; i++) {
		D[i] = false;
	}
	
	memcpy(arr, temp, sizeof(temp));
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		
		cin >> d >> w >> k;

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				temp[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i <= d; i++) {
			for (int j = 0; j < 2; j++) {
				isA = j;
				DFS(0, 0, i);
				if (min_cur < 999) {
					init();
					break;
				}
			}
			if (min_cur < 999) {
				init();
				break;
			}
		}

		ans.push_back(min_cur);
		
		min_cur = 999;

	}

	for (int i = 0; i < t; i++) {
		cout << "#" << i + 1 << " " << ans[i] << '\n';
	}

	return 0;
}


//int selected[13];
//
//void print()
//{
//	int i;
//
//	for (i = 0; i < 13; i++)
//	{
//		cout << selected[i] << " ";
//	}
//	cout << endl;
//}
//
//void func(int index, int k)
//{
//	if(k==0)
//	{
//		print();
//
//		return;
//	}
//
//	if(index==13)
//	{
//		return;
//	}
//
//	selected[index] = 1;
//	func(index+1, k-1);
//
//	selected[index] = 0;
//	func(index+1, k);
//}
//
//int main()
//{
//	func(0, 3);
//}