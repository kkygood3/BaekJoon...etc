#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string BigNumAdd(string num1, string num2) {

	int sum = 0;
	string temp;
	while (!num1.empty() || !num2.empty() || sum) {

		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		temp.push_back(sum % 10 + '0');
		sum /= 10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}

int main() {
	string a, b;
	cin >> a >> b;

	cout << BigNumAdd(a, b);
	return 0;
}