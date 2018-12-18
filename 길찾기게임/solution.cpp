#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#define null 0
using namespace std;

vector<vector<int>> answer;
vector<int> pre;
vector<int> post;

struct Node {
	int x;
	int y;
	int data;
	int l_lim;
	int r_lim;
	Node* left_node;
	Node* right_node;

};

vector<Node> v;

bool compare(Node T1,Node T2) {

	return T1.y > T2.y;

}

void Tree(Node* node, Node* root) {
	
	Node* current = root;

	if (node->x > root->l_lim && node->x < root->x && root->left_node == null) {
		root->left_node = node;
		node->l_lim = root->l_lim;
		node->r_lim = root->x;
	}
	else if (node->x > root->l_lim && node->x < root->x && root->left_node != null) Tree(node, root->left_node);
	else if (node->x > root->x && node->x < root->r_lim && root->right_node == null) {
		root->right_node = node;
		node->l_lim = root->x;
		node->r_lim = root->r_lim;
	}
	else if (node->x > root->x && node->x < root->r_lim && root->right_node != null) Tree(node, root->right_node);

}

void preorder(Node* node) {
	if (node != null) {
		pre.push_back(node->data);
		preorder(node->left_node);
		preorder(node->right_node);
	}
}

void postorder(Node* node) {
	if (node != null) {
		postorder(node->left_node);
		postorder(node->right_node);
		post.push_back(node->data);
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

	int sz = nodeinfo.size();
	for (int i = 0; i < sz; ++i) {
		Node node = {nodeinfo[i][0],nodeinfo[i][1], i + 1,-999999,999999,null,null };
		v.push_back(node);
	}
	sort(v.begin(), v.end(), compare);

	Node* root = &v[0];

	for (int i = 1; i < sz; ++i) {
		Tree(&v[i], root);
	}

	preorder(root);
	postorder(root);

	answer.push_back(pre);
	answer.push_back(post);

	return answer;
}