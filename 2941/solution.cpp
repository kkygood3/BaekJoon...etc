#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	string s;
	vector<string> vec = {"c=","c-","dz=","d-","lj","nj","s=","z=" };
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> s;

	for (int i = 0; i < vec.size(); i++) {

		int index = s.find(vec.at(i), 0);
		while (index != string::npos) {
			s.replace(index, vec.at(i).size(), "l");
			index = s.find(vec.at(i), index + 1);
		}
	}

	cout << s.size();

	return 0;
}