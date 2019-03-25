#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <map>
using namespace std;

vector<pair<string, string>> v;
vector<int> v_id[100000];
map<string, string> m;
map<string, int> m_id;
int msg_cnt = 0;
int cnt = 0;

void enter(string id, string nick) {
	
	if (m[id] != nick) {
		int sz = v_id[m_id[id]].size();
		m[id] = nick;
		for (int i = 0; i < sz; ++i) {
			if (v[v_id[m_id[id]][i]].first.find("µé") != string::npos) {
				string s = "" + nick + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
				v[v_id[m_id[id]][i]].first = s;
			}
			else {
				string s = "" + nick + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
				v[v_id[m_id[id]][i]].first = s;
			}
		}
	}
	string s = "" + nick + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
	v.push_back(make_pair(s, id));
	v_id[m_id[id]].push_back(msg_cnt++);
}

void leave(string id) {
	string s = "" + m[id] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
	v.push_back(make_pair(s, id));
	v_id[m_id[id]].push_back(msg_cnt++);
}

void change(string id, string nick) {

	m[id] = nick;

	int sz = v_id[m_id[id]].size();
	for (int i = 0; i < sz; ++i) {
		if (v[v_id[m_id[id]][i]].first.find("µé") != string::npos) {
			string s = "" + nick + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			v[v_id[m_id[id]][i]].first = s;
		}
		else {
			string s = "" + nick + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			v[v_id[m_id[id]][i]].first = s;
		}
	}
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	int sz = record.size();
	for (int i = 0; i < sz; ++i) {
		string msg, id, nick;
		char arr[110];
		strcpy(arr, record[i].c_str());
		char *ptr = strtok(arr, " ");
		msg = string(ptr);


		if (msg == "Leave") {
			id = string(strtok(nullptr, " "));
		}
		else {
			id = string(strtok(nullptr, " "));
			nick = string(strtok(nullptr, " "));
		}

		if (m.find(id) == m.end()) {
			m.insert(make_pair(id, nick));
			m_id.insert(make_pair(id, cnt));
			cnt++;
		}

		if (msg == "Enter") enter(id, nick);
		if (msg == "Leave") {
			leave(id);
		}
		if (msg == "Change") change(id, nick);

	}
	int v_sz = v.size();
	for (int j = 0; j < v_sz; ++j) {
		answer.push_back(v[j].first);
	}
	
	return answer;
}