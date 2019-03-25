#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[300][300];

int solution(string name) {
	int answer = 0;

	for (int i = 'A'; i <= 'Z'; ++i) {
		for (int j = i; j <= 'Z'; ++j) {
			arr[i][j] = min(j - i, i - 'A' + 'Z' - j + 1); // �ٷΰ��°�, A ���ļ� ���°� �� ������
			arr[j][i] = arr[i][j];
		}
	}

	for (int i = 'A'; i <= 'Z'; ++i) {
		for (int j = 'A'; j <= 'Z'; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	int sz = name.size();

	for (int i = 0; i < sz; ++i) answer += arr['A'][name[i]];

	

	return answer;
}