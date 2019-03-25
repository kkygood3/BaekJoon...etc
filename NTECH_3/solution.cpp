#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string encrypted_text, string key, int rotation) {
	string answer = "";

	int sz = encrypted_text.size();
	int index = rotation;
	while (index < 0 || index >= sz) {
		if (index < 0) index += sz;
		if (index >= sz) index -= sz;
	}

	for (int i = 0; i < sz; ++i) {
		answer.push_back(encrypted_text[index++]);
		if (index >= sz) index = 0;
	}

	for (int i = 0; i < sz; ++i) {
		cout << answer << '\n';
		char temp = answer[i] - (key[i] - 'a' + 1);
		if (temp < 'a') temp += 26;
		answer[i] = temp;
	}

	return answer;
}