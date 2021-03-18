#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct AVLNode {
	int key;
	int height;
	int level;
	AVLNode *left, *right;
};

AVLNode* newAVLNode(int key) {
	AVLNode *node = new AVLNode;
	node->height = 1;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

int heightOf(AVLNode *root) {
	if (root == NULL) return 0;
	return root->height;
}

void updateHeight(AVLNode *root) {
	root->height = max(heightOf(root->left), heightOf(root->right))+1;
}

void rotationR(AVLNode* &root) {
	AVLNode *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void rotationL(AVLNode* &root) {
	AVLNode *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

int balanceFactorOf(AVLNode *root) {
	return heightOf(root->left)-heightOf(root->right);
}

void insertAVL(AVLNode* &root, int key) {
	if (root == NULL) {
		root = newAVLNode(key);
		return;
	}
	if (key < (root->key)) {
		insertAVL(root->left, key);
		int bf = balanceFactorOf(root);
		if (bf == 2) {
			if (balanceFactorOf(root->left) == 1) {
				rotationR(root);
			} else {
				rotationL(root->left);
				rotationR(root);
			}
		}
	} else {
		insertAVL(root->right, key);
		int bf = balanceFactorOf(root);
		if (bf == -2) {
			if (balanceFactorOf(root->right) == -1) {
				rotationL(root);
			} else {
				rotationR(root->right);
				rotationL(root);
			}
		}
	}
	updateHeight(root);
}

bool isCompleteAVL(vector<AVLNode*> list){
	if (list.size() == 1) return true;
	int index = list.size()/2;
	// from 0 to index-1 all the nodes have 2 childs and index-1'th node has 1 left node or 2 childs
	// from index to size-1 all the nodes are leaf nodes
	for (int i=0; i<index-1; i++) {
		if (list[i]->left == NULL || list[i]->right == NULL) return false;
	}
	if (list[index-1]->left == NULL) return false;
	for (int i=index; i<list.size(); i++) {
		if (list[i]->left != NULL || list[i]->right != NULL) return false;
	}
	return true;
}

int _1123() {
	int n, d;
	AVLNode *root = NULL;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		insertAVL(root, d);
	}

	queue<AVLNode*> q;
	vector<AVLNode*> list;
	root->level = 1;
	q.push(root);
	while(!q.empty()) {
		AVLNode *node = q.front();q.pop();
		list.push_back(node);
		if (node->left != NULL) {
			node->left->level = node->level +1;
			q.push(node->left);
		} 
		if (node->right != NULL) {
			node->right->level =node->level+1;
			q.push(node->right);
		}
	}
	bool iscomplete = isCompleteAVL(list);
	for(int i=0; i<n; i++) {
		if (i!=0) printf(" %d", list[i]->key);
		else printf("%d", list[i]->key);
	}
	printf("\n");
	if (iscomplete) printf("YES");
	else printf("NO");
	
	//getchar();getchar();
	return 0;
}