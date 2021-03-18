#include <cstdio>
#include <map>
using namespace std;
struct bstnode{
	int key;
	int level;
	bstnode *left, *right;
};

map<int, int, greater<int>> levelcnt;

bstnode* newbstnode(int key) {
	bstnode *node = new bstnode;
	node->key = key;
	node->level = -1;
	node->left = node->right = NULL;
	return node;
}

void insert_bst(bstnode* &root, int key) {
	if (root == NULL) {
		root = newbstnode(key);
		return;
	}
	if (key <= root->key) {
		insert_bst(root->left, key);
	} else {
		insert_bst(root->right, key);
	}
}

void storelevel(bstnode *root) {
	if (root == NULL) return;
	int lv = root->level;
	levelcnt[lv]++;
	if (root->left != NULL) {
		root->left->level = lv+1;
		storelevel(root->left);
	}
	if (root->right != NULL) {
		root->right->level = lv+1;
		storelevel(root->right);
	}
}

int _1115() {
	int n, d;
	scanf("%d", &n);
	bstnode *root = NULL;
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		insert_bst(root, d);
	}
	root->level = 1;
	storelevel(root);
	map<int, int, greater<int>>::iterator it = levelcnt.begin();
	int n1 = it->second;it++;
	int n2 = it->second;
	printf("%d + %d = %d", n1, n2, n1+n2);
	//getchar();getchar();
	return 0;
}