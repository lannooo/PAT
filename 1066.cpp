#include <cstdio>
#include <algorithm>
using namespace std;

struct AvlTreeNode {
	int key;
	int height;
	AvlTreeNode *left, *right;
};

AvlTreeNode* newAvlNode(int key) {
	AvlTreeNode *node = new AvlTreeNode;
	node->key = key;
	node->left = node->right = NULL;
	node->height = 1;
	return node;
}

int height(AvlTreeNode *node) {
	if (node==NULL) return 0;
	return node->height;
}

void update_height(AvlTreeNode* root) {
	root->height = max(height(root->left), height(root->right))+1;
}

int balance_factor(AvlTreeNode *root) {
	return height(root->left) - height(root->right);
}

void left_rotation(AvlTreeNode* &root) {
	AvlTreeNode *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	update_height(root);
	update_height(temp);
	root = temp;
}

void right_rotation(AvlTreeNode* &root) {
	AvlTreeNode *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	update_height(root);
	update_height(temp);
	root = temp;
}

void avl_insert(AvlTreeNode* &root, int key) {
	if (root == NULL) {
		root = newAvlNode(key);
		return;
	}
	if (key < root->key) {
		avl_insert(root->left, key);
		update_height(root);
		if (balance_factor(root) == 2) {
			if (balance_factor(root->left) == 1) { //LL type
				right_rotation(root);
			} else { // LR type
				left_rotation(root->left);
				right_rotation(root);
			}
		}
	}else {
		avl_insert(root->right, key);
		update_height(root);
		if (balance_factor(root) == -2) {
			if (balance_factor(root->right) == -1) { // RR type
				left_rotation(root);
			} else { //RL type
				right_rotation(root->right);
				left_rotation(root);
			}
		}
	}
}

int _1066() {
	int n, d;
	scanf("%d", &n);
	AvlTreeNode *root = NULL;
	for(int i=0; i<n; i++) {
		scanf("%d", &d);
		avl_insert(root, d);
	}
	printf("%d", root->key);
	//getchar();getchar();
	return 0;
}