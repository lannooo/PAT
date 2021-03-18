#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct TNode {
	int key;
	int level;
	TNode *left, *right;
};

TNode* build_node(int key) {
	TNode *node = new TNode;
	node->left = node->right = NULL;
	node->key = key;
	node->level = -1;
	return node;
}

TNode* build_tree(vector<int> &in, int inL, int inR, vector<int> &post, int postL, int postR) {
	if (inL > inR) return NULL;
	int rootkey = post[postR];
	TNode *root = build_node(rootkey);
	if (inL == inR) return root;
	int index = -1;
	for (int i=inL; i<=inR; i++) {
		if (in[i] == rootkey) {
			index = i;break;
		}
	}
	if (index == inL) {
		root->right = build_tree(in, inL+1, inR, post, postL, postR-1);
	} else if (index == inR) {
		root->left = build_tree(in, inL, inR-1, post, postL, postR-1);
	} else {
		int len = index - inL;
		root->left = build_tree(in, inL, index-1, post, postL, postL+len-1);
		root->right = build_tree(in, index+1, inR, post, postL+len, postR-1);
	}
	return root;
}

void reverseLevel(vector<TNode*> &list, int start, int stop, int &reversecnt) {
	if (reversecnt % 2 == 0) {
		reverse(list.begin()+start, list.begin()+stop+1);
	}
	reversecnt++;
}

int _1127() {
	int n, d;
	scanf("%d", &n);
	vector<int> inorder, postorder;
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		inorder.push_back(d);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		postorder.push_back(d);
	}
	TNode *root = build_tree(inorder, 0, n-1, postorder, 0, n-1);
	// get level-order
	queue<TNode*> q;
	vector<TNode*> list;
	root->level = 1;
	q.push(root);
	while(!q.empty()) {
		TNode *node = q.front();q.pop();

		list.push_back(node);

		if (node->left != NULL) {
			node->left->level = node->level+1;
			q.push(node->left);
		}
		if (node->right != NULL) {
			node->right->level = node->level+1;
			q.push(node->right);
		}
	}
	// reverse by zigzag
	if (n > 2) {
		int start = 1, stop = 1;
		int index = 2;
		int reversecnt = 1;
		while(index < n) {
			if (list[index]->level != list[stop]->level) {
				// reverse from start to stop
				reverseLevel(list, start, stop, reversecnt);
				// reset start and stop
				start = stop = index;
			} else {
				stop = index;
				if (stop == n-1) {
					// reverse from start to stop
					reverseLevel(list, start, stop, reversecnt);
				}
			}
			index++;
		}
	}

	for (int i=0; i<list.size(); i++) {
		if (i!=0) printf(" %d", list[i]->key);
		else printf("%d", list[i]->key);
	}
	//getchar();getchar();
	return 0;
}