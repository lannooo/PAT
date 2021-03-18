#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct TTNode {
	int data;
	TTNode *left, *right;
};

vector<int> preorder,inorder;

TTNode* newNode(int key) {
	TTNode *node = new TTNode;
	node->data = key;
	node->left = node->right = NULL;
	return node;
}

void buildTree(TTNode* &root, int preL, int preR, int inL, int inR) {
	if (preL > preR || inL > inR) return;
	int rootkey = preorder[preL];
	root = newNode(rootkey);
	if (preL == preR || inL == inR) return; // only one node, return
	// find the index of rootkey in inorder sequence[inL, inR]
	int index;
	for (index = inL; index <= inR; index++) {
		if (inorder[index] == rootkey) break;
	}
	buildTree(root->left, preL+1, preL+(index-inL), inL, index-1);
	buildTree(root->right, preL+(index-inL)+1, preR, index+1, inR);
}

void postorder(vector<int> &v, TTNode *root) {
	if (root == NULL) return;
	postorder(v, root->left);
	postorder(v, root->right);
	v.push_back(root->data);
}

vector<int> traversal(vector<int> preorder, vector<int> inorder) {
	vector<int> v;
	TTNode *root;
	buildTree(root, 0, preorder.size()-1, 0, inorder.size()-1);
	postorder(v, root);
	return v;
}

int _1086() {
	int n, key;
	stack<int> s;
	string op;
	cin >> n;
	for(int i=0; i<2*n; i++) {
		cin >> op;
		if (op == "Push") {
			cin >> key;
			s.push(key);
			preorder.push_back(key);
		} else if (op == "Pop"){
			inorder.push_back(s.top());
			s.pop();
		}
	}
	vector<int> postorder = traversal(preorder, inorder);
	for(int i=0; i<postorder.size(); i++) {
		if (i!=0) cout << " " << postorder[i];
		else cout << postorder[i];
	}

	//getchar();getchar();
	return 0;
}