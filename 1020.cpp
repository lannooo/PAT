#include <cstdio>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;

}*tree;

int postorder[31];
int inorder[31];
map<int, int> inorderIndex;

TreeNode* newNode(int data) {
	TreeNode *node = new TreeNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void buildTree(TreeNode *root, int remain, int &now, int left, int right) {
	if(remain <= 0 || left > right) return;
	int nextval = postorder[now--];
	int nextIndex = inorderIndex[nextval];
	int rootIndex = inorderIndex[root->data];
	TreeNode *node = newNode(nextval);
	if(rootIndex < nextIndex) {
		root->right = node;
	} else {
		root->left = node;
	}

	buildTree(node, right-nextIndex, now, nextIndex+1, right);
	buildTree(node, nextIndex-left, now, left, nextIndex-1);
}

int _1020() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &postorder[i]);
	}
	for(int i=0; i<n; i++) {
		scanf("%d", &inorder[i]);
		inorderIndex[inorder[i]] = i;
	}

	int now = n-1;
	tree = newNode(postorder[now--]);
	int rootIndex = inorderIndex[tree->data];
	buildTree(tree, n-1-rootIndex, now, rootIndex+1, n-1);
	buildTree(tree, rootIndex, now, 0, rootIndex-1);

	queue<TreeNode*> q;
	q.push(tree);
	bool firstIn = true;
	while(!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		// print
		if (firstIn) {
			firstIn = false;
			printf("%d", node->data);
		} else {
			printf(" %d", node->data);
		}

		if (node -> left != NULL)
			q.push(node ->left);
		if (node ->right != NULL)
			q.push(node ->right);

	}

	//getchar();getchar();
	return 0;
}