#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int main() {

	list<int> li;
	queue<int> q;
	char c[300];
	string str[100];
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	char num[100];
	int temp;
	bool item[7] = {false,};
	vector<int> v;
	list<int>::iterator iter;
	list<int>::iterator p;
	
	cin.getline(c, 300);

	char *ptr = strtok(c, " ");
	while (ptr != NULL) {
		v.push_back(ptr[0] - '0');
		ptr = strtok(NULL, " ");
	}



	for (int i = 0; i < v.size(); i++) {
		if (item[v.at(i)] == true) {
			for (iter = li.begin(); iter != li.end(); iter++) {
				if (*iter == v.at(i)) 
				{
					iter = li.erase(iter);
				}
			}
		}
		li.push_back(v.at(i));
		item[v.at(i)] = true;
		if (li.size() > 3) {
			q.push(li.front());
			item[li.front()] = false;
			li.pop_front();
		}
	}
	int size = q.size();
	if (size == 0) cout << 0;
	else {
		for (int i = 0; i < size; i++) {
			cout << q.front() << '\n';
			q.pop();
		}
	}

	return 0;
}