#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k;
int alpha[26] = { 0, };   // 
						  //int alpha_cnt[26] = { 0, };   // 각 알파벳이 몇개의 단어에 포함되었는지 카운트
int visit[26];   // 알파벳을 배웠는지 여부
int maxValue = 0;

typedef struct WORDTYPE {
	char word[50];
}WORDTYPE;

typedef struct ALPHATYPE {
	int alphaType;
	int alphaCnt = 0;
};

vector <WORDTYPE> wordList;
ALPHATYPE alphaCnt[26];
// a, n, t, i, c (5개) 는 항상 필요


int getScore() {
	int sum = 0;
	for (int i = 0; i < wordList.size(); i++) {
		int idx = -1;
		int flag = 0;
		int tmp;
		while (wordList[i].word[++idx] != '\0') {
			tmp = wordList[i].word[idx];
			if (visit[tmp - 'a'] != 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) sum++;
	}
	return sum;
}

void dfs(int v, int d) {
	visit[v] = 1;	// 방문
	if (d == k) {
		maxValue = max(getScore(), maxValue);
		visit[v] = 0;
		return;
	}


	for (int i = v + 1; i < 26; i++) {
		if (visit[i] != 1 && alphaCnt[i].alphaCnt != 0) dfs(i, d + 1);
	}

	visit[v] = 0;	// backtracking

}


int main() {

	char input[50];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		WORDTYPE w;
		cin >> w.word;   //1단어 입력
		wordList.push_back(w);
	}

	for (int i = 0; i < wordList.size(); i++) {
		int idx = -1;
		int ch_int = 0;
		int flag[26] = { 0, };
		while (wordList[i].word[++idx] != '\0') {

			//cout << wordList[i].word[idx] << " ";
			ch_int = wordList[i].word[idx] - 'a';	// 아스키 char -> int 값으로 전환('a' - > 0)
			flag[ch_int] = 1;	// 해당 알파벳이 있는 단어라는 표시
		}

		for (int i = 0; i < 26; i++) {
			if (flag[i] == 1) alphaCnt[i].alphaCnt++;
			alphaCnt[i].alphaType = i;
		}

		//cout << endl;

	}

	for (int i = 0; i < 26; i++) {
		if (alphaCnt[i].alphaCnt > 0 && visit[i] != 1) {
			dfs(i, 1);
		}
	}
	cout << maxValue << endl;


	return 0;
}
