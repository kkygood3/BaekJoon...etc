#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
string arr[10] = { "" , "ÀÏ", "ÀÌ", "»ï", "»ç", "¿À", "À°", "Ä¥", "ÆÈ", "±¸" };

string solution(int num) {
	string answer = "";
	string s = "";

	while (num != 0) {
		int temp = num % 10;
		s.push_back(temp + '0');
		num /= 10;
	}

	reverse(s.begin(), s.end());

	int sz = s.size();
	if (sz == 1) answer += arr[s[0] - '0'];
	if (sz == 2) {
		if (s[0] - '0' >= 2) answer += arr[s[0] - '0'];
		answer += "½Ê";
		answer += arr[s[1] - '0'];
	}
	if (sz == 3) {
		if (s[0] - '0' >= 2) answer += arr[s[0] - '0'];
		answer += "¹é";
		if (s[1] - '0' >= 2) answer += arr[s[1] - '0'];
		if (arr[s[1] - '0'] != "") answer += "½Ê";
		answer += arr[s[2] - '0'];
	}
	if (sz == 4) {
		if (s[0] - '0' >= 2) answer += arr[s[0] - '0'];
		answer += "Ãµ";
		if (s[1] - '0' >= 2) answer += arr[s[1] - '0'];
		if (arr[s[1] - '0'] != "") answer += "¹é";
		if (s[2] - '0' >= 2) answer += arr[s[2] - '0'];
		if (arr[s[2] - '0'] != "") answer += "½Ê";
		answer += arr[s[3] - '0'];
	}
	if (sz == 5) {
		if(s[0] - '0' >= 2) answer += arr[s[0] - '0'];
		answer += "¸¸";
		if (s[1] - '0' >= 2) answer += arr[s[1] - '0'];
		if (arr[s[1] - '0'] != "") answer += "Ãµ";
		if (s[2] - '0' >= 2) answer += arr[s[2] - '0'];
		if (arr[s[2] - '0'] != "") answer += "¹é";
		if (s[3] - '0' >= 2) answer += arr[s[3] - '0'];
		if (arr[s[3] - '0'] != "") answer += "½Ê";
		answer += arr[s[4] - '0'];

	}

	return answer;
}