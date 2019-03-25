#include <iostream>
#define null 0
using namespace std;

template <class T>
class Tree;

template <class T>
class TreeNode {
	friend class Tree<T>;
private:			//값, 왼쪽 노드주소, 오른쪽 노드주소
	T data;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null) { // 아마 지정안해주면 기본값 설정 해주면 교체
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <class T>
class Tree {
private:
	TreeNode<T>* root;
public:
	Tree(T data = 0) { // 기본값 0, 노드 하나 넣어주면 그 노드가 root트리 ( 주소 반환 )
		root = new TreeNode<T>(data);
	}

	void buildTree() {
		root->left = new TreeNode<T>('B', new TreeNode<T>('D', new TreeNode<T>('H')), new TreeNode<T>('E', new TreeNode<T>('I'), new TreeNode<T>('J')));
		root->right = new TreeNode<T>('C', new TreeNode<T>('F'), new TreeNode<T>('G', null, new TreeNode<T>('K')));
	}

	TreeNode<T>* getRoot() {
		return root;
	}

	void visit(TreeNode<T>* current) {
		cout << current->data << " ";
	}

	void preorder(TreeNode<T>* current) {	// 본인 -> 왼쪽 -> 오른쪽
		if (current != null) {
			visit(current);
			preorder(current->left);
			preorder(current->right);
		}
	}

	void inorder(TreeNode<T>* current) {	// 왼쪽 -> 본인 -> 오른쪽
		if (current != null) {
			inorder(current->left);
			visit(current);
			inorder(current->right);
		}
	}
	
	void postorder(TreeNode<T>* current) {	// 왼쪽 -> 오른쪽 -> 본인
		if (current != null) {
			postorder(current->right);
			postorder(current->left);
			visit(current);
		}
	}

};

int main() {

	Tree<char> tree('A'); // 루트노드가 A인 트리 생성
	tree.buildTree(); // 예시 노드 및 트리 생성

	cout << "Preorder >> ";
	tree.preorder(tree.getRoot()); // 각 오더에 루트 노드 주소를 넘김
	cout << endl;

	cout << "Inorder >> ";
	tree.inorder(tree.getRoot());
	cout << endl;

	cout << "Postorder >> ";
	tree.postorder(tree.getRoot());
	cout << endl;


	return 0;
}