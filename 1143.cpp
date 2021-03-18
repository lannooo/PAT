#include <cstdio>
#include <vector>
using namespace std;
struct BiNode{
	int key;
	BiNode *left, *right;
	BiNode *parent;
	int mark;
};

BiNode* newBiNode(int key, BiNode *parent) {
	BiNode *node =new BiNode;
	node->left = node->right = NULL;
	node->key = key;
	node->parent = parent;
	node->mark = -1;
	return node;
}

void insertNode(BiNode* &root, int key, BiNode *parent) {
	if (root == NULL) {
		root = newBiNode(key, parent);
		return;
	}
	if (key < root->key) {
		insertNode(root->left, key, root);
	} else {
		insertNode(root->right, key, root);
	}
}

BiNode* buildBiTree2(vector<int> &v, int L, int R, BiNode *p) {
	int rootkey = v[L];// v[L], v[L+1]-v[k-1], v[k]-v[R]
	BiNode *root = newBiNode(rootkey, p);
	if (L == R) return root;
	int k=-1;
	for (int i=L+1; i<=R; i++) {
		if (v[i] >= rootkey) {
			k = i;
			break;
		}
	}
	// if k==-1, all the rest elements are smaller than rootkey
	// if k==L+1,all the rest elements are greater or equals to rootkey
	if(k == -1) {
		root->left = buildBiTree2(v, L+1, R, root);
	} else if (k==L+1) {
		root->right = buildBiTree2(v, L+1, R, root);
	} else {
		root->left = buildBiTree2(v, L+1, k-1, root);
		root->right = buildBiTree2(v, k, R, root);
	}
	return root;
}

BiNode* findBiNode(BiNode *root, int x) {
	if (root==NULL) return NULL;
	if (root->key == x) return root;
	if (x < root->key) return findBiNode(root->left, x);
	else return findBiNode(root->right, x);
}

void judgeLCA2(BiNode *root, int u, int v, int mark) {
	BiNode *unode, *vnode;
	unode = findBiNode(root, u);
	vnode = findBiNode(root, v);
	if (unode != NULL && vnode != NULL) {
		BiNode *temp = unode;
		while(temp != NULL) {
			temp->mark = mark;
			temp=temp->parent;
		}
		temp = vnode;
		while(temp!=NULL) {
			if (temp->mark == mark) break;
			temp = temp->parent;
		}
		if (temp->key != unode->key && temp->key != vnode->key) {
			printf("LCA of %d and %d is %d.\n", u, v, temp->key);
		} else if (temp->key == unode->key) {
			printf("%d is an ancestor of %d.\n", u, v);
		} else {
			printf("%d is an ancestor of %d.\n", v, u);
		}
	} else {
		if (unode != NULL) {
			printf("ERROR: %d is not found.\n", v);
		} else if (vnode != NULL) {
			printf("ERROR: %d is not found.\n", u);
		} else {
			printf("ERROR: %d and %d are not found.\n", u, v);
		}
	}
}

int _1143() {
	int M, N, d;
	scanf("%d%d", &M, &N);
	vector<int> preorder(N);
	for (int i=0; i<N; i++) {
		scanf("%d", &d);
		preorder[i] =d;
	}
	BiNode *root = buildBiTree2(preorder, 0, N-1, NULL);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		judgeLCA2(root, u, v, i);
	}

	return 0;
}