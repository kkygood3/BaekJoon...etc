#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

struct Node {
	int x;
	int y;
	int parent_index;
	int child_index;
};
Node node[10010];

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;
	int node_size = nodeinfo.size();
	int top_index;
	int top_y = -1;
	for (int i = 0; i < node_size; ++i) {
		node[i + 1].x = nodeinfo[i][0];
		node[i + 1].y = nodeinfo[i][1];
		if (top_y < node[i].y) {
			top_y = node[i].y;
		}

	}

	for (int i = 0; i < node_size; ++i) {
		if (node[i + 1].y == top_y) node[i + 1].parent_index = -1;
	}

	for (int i = top_y; i >= 0; --i) {

	}


	return answer;
}
