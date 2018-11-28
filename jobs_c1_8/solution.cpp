#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> //memcpy
#include <queue>
#define MAX 25
using namespace std;

int arr[MAX][MAX];
queue<int> q;

bool check() {
	int cnt = 0;
	bool bingo;

	for (int i = 0; i < 5; i++) {
		if (arr[i][i] == 0) bingo = true;
		else {
			bingo = false;
			break;
		}
	}
	if (bingo) cnt++;

	for (int i = 0; i < 5; i++) {
		if (arr[i][4 - i] == 0) bingo = true;
		else {
			bingo = false;
			break;
		}
	}
	if (bingo) cnt++;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == 0) bingo = true;
			else {
				bingo = false;
				break;
			}
		}
		if (bingo) cnt++;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] == 0) bingo = true;
			else {
				bingo = false;
				break;
			}
		}
		if (bingo) cnt++;
	}

	if(cnt >= 3) return true;
	else return false;
}

int main() {

	cin.tie(0); ios::sync_with_stdio(0);
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 25; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	int cnt = 0;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if( tmp == arr[i][j] ) arr[i][j] = 0;
			}
		}
		if (check()) {
			cout << cnt;
			return 0;
		}
	}

	return 0;
}