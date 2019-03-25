#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

struct Table {
	string name;
	string occupation;
	string city;
	string zip;
};

struct Table1 {
	string name;
	string occupation;
};

struct Table2 {
	string city;
	string zip;
};

map<int, Table> m;
map<int, Table1> m1;
map<int, Table2> m2;

vector<int> ans;

int main(void) {

	int n;
	cin >> n;
	string tmp;

	cin >> tmp >> tmp >> tmp;

	for (int i = 0; i < n - 1; ++i) {
		int id;
		string name;
		string occupation;

		cin >> id >> name >> occupation;

		Table1 t1 = { name, occupation };
		m1.insert(make_pair(id, t1));
		ans.push_back(id);
	}

	cin >> n;

	cin >> tmp >> tmp >> tmp;

	for (int i = 0; i < n - 1; ++i) {
		int id;
		string city;
		string zip;

		cin >> id >> city >> zip;

		Table2 t2 = { city, zip };
		m2.insert(make_pair(id, t2));
	}

	sort(ans.begin(), ans.end());

	int sz = ans.size();

	cout << "id name occupation city zip" << '\n';
	for (int i = 0; i < sz; ++i) {
		cout << ans[i] << ' '; 
		cout << m1[ans[i]].name << ' ' << m1[ans[i]].occupation << ' ';
		if (m2.find(ans[i]) == m2.end()) {
			cout << "NULL NULL" << '\n';
		}
		else {
			cout << m2[ans[i]].city << ' ' << m2[ans[i]].zip << '\n';
		}
	}

	return 0;
}