#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string BigNumMinus(string num1, string num2) {

	int sum = 0, i = 0;
	bool sign = false;
	num1 = &num1[1];
	string big, small;
	if (num1.size() < num2.size()) {
		big = num2;
		small = num1;
	}
	else if (num1.size() > num2.size()) {
		big = num1;
		small = num2;
		sign = true;
	}
	else {
		while (1) {
			if (num1[i] > num2[i]) {
				big = num1;
				small = num2;
				sign = true;
				break;
			}
			if (num1[i] < num2[i]) {
				big = num2;
				small = num1;
				break;
			}
			if (i == num1.size()) return "0";
			i++;
		}
	}
	string temp;
	while (!big.empty() || !small.empty() || sum) {

		if (!big.empty()) {
			sum += big.back() - '0';
			big.pop_back();
		}
		if (!small.empty()) {
			sum -= small.back() - '0';
			small.pop_back();
		}
		if (sum >= 0) {
			if (sum == 0 && big.empty()) break;
			temp.push_back(sum % 10 + '0');
			sum /= 10;
		}
		else {
			temp.push_back((10 + sum) + '0');
			sum = -1;
		}
	}

	while (temp.back() == '0') {
		temp.pop_back();
		if (temp.empty()) {
			return "0";
		}
	}

	if (sign) temp.push_back('-');

	reverse(temp.begin(), temp.end());
	return temp;
}

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

string BigNumMinusAdd(string num1, string num2) {

	int sum = 0;
	num1 = &num1[1];
	num2 = &num2[1];
	string temp;
	if (num1 == "0" && num2 == "0" ) return "0";
	while (!num1.empty() || !num2.empty() || sum) {

		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		if (sum >= 0) {
			temp.push_back(sum % 10 + '0');
			sum /= 10;
		}
		
	}
	temp.push_back('-');
	reverse(temp.begin(), temp.end());
	return temp;
}

int main() {

	string a, b;
	cin >> a >> b;

	if (a[0] == '-' && b[0] == '-') cout << BigNumMinusAdd(a, b);
	else if (a[0] == '-') cout << BigNumMinus(a, b);
	else if (b[0] == '-') cout << BigNumMinus(b, a);
	else cout << BigNumAdd(a, b);

	return 0;
}