#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* newNode_1043(int data) {
	TreeNode* node = new TreeNode;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void insert(TreeNode* &root, int data) {
	if (root == NULL) {
		root = newNode_1043(data);
		return;
	}
	if (data < root->data) {
		insert(root->left, data);
	} else {
		insert(root->right, data);
	}
}

TreeNode* buildTree(vector<int> seq) {
	TreeNode* root = newNode_1043(seq[0]);
	for (int i=1; i<seq.size(); i++) {
		insert(root, seq[i]);
	}
	return root;
}

void preorder_1043(TreeNode* root, vector<int> &seq) {
	if (root == NULL) return;
	seq.push_back(root->data);
	preorder_1043(root->left, seq);
	preorder_1043(root->right,seq);
}

void preorderMirror_1043(TreeNode* root, vector<int> &seq) {
	if (root == NULL) return;
	seq.push_back(root->data);
	preorderMirror_1043(root->right,seq);
	preorderMirror_1043(root->left, seq);
}

void postorder_1043(TreeNode* root, vector<int> &seq) {
	if (root == NULL) return;
	postorder_1043(root->left, seq);
	postorder_1043(root->right,seq);
	seq.push_back(root->data);
}

void postorderMirror_1043(TreeNode* root, vector<int> &seq) {
	if (root == NULL) return;
	postorderMirror_1043(root->right,seq);
	postorderMirror_1043(root->left, seq);
	seq.push_back(root->data);
}

void printSeq(vector<int> &seq) {
	int size = seq.size();
	for (int i=0; i<size; i++) {
		if (i!=0) printf(" %d", seq[i]);
		else printf("%d", seq[i]);
	}
}

int _1043() {
	int n, d;
	vector<int> seq;
	vector<int> pre, preM, post, postM;

	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d",&d);
		seq.push_back(d);
	}
	TreeNode *root = buildTree(seq);
	preorder_1043(root, pre);
	preorderMirror_1043(root, preM);

	if (seq == pre) {
		printf("YES\n");
		postorder_1043(root, post);
		printSeq(post);
	} else if (seq == preM) {
		printf("YES\n");
		postorderMirror_1043(root, postM);
		printSeq(postM);
	} else {
		printf("NO");
	}
	return 0;
}