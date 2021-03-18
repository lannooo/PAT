#include <cstdio>
#include <unordered_map>
using namespace std;

struct BiTreeNode {
	int data;
	BiTreeNode *left, *right;
	BiTreeNode *parent;
	int mark;
};

unordered_map<int, BiTreeNode*> nodesMap;
BiTreeNode * newTreeNode(int key, BiTreeNode *p) {
	BiTreeNode *node = new BiTreeNode;
	node->data = key;
	node->mark = -1;
	node->left = node->right = NULL;
	node->parent = p;
	nodesMap[key] = node;
	return node;
}

int inorder[10000];
int preorder[10000];

BiTreeNode* buildBiTree(int preL, int preR, int inL, int inR, BiTreeNode *parent) {
	if (preL > preR || inL > inR) return NULL;
	int key = preorder[preL];
	BiTreeNode *root = newTreeNode(key, parent);
	if (preL == preR) return root;
	int index;
	for (index = inL; index <= inR; index++) {
		if (inorder[index] == key) break;
	}
	int len = index-inL;
	root->left = buildBiTree(preL+1, preL+len, inL, index-1, root);
	root->right = buildBiTree(preL+len+1, preR, index+1, inR, root);
	return root;
}

BiTreeNode* findInTree(BiTreeNode *root, int x) {
	if (nodesMap.count(x) != 0) {
		return nodesMap[x];
	} else return NULL;
}

int mark = 0;
void judgeLCA(int u, int v, BiTreeNode *root) {
	BiTreeNode *unode, *vnode;
	unode = findInTree(root, u);
	vnode = findInTree(root, v);
	if (unode != NULL && vnode != NULL) {
		BiTreeNode *temp = unode;
		while(temp != NULL) {
			temp->mark = mark;
			temp = temp->parent;
		}
		temp = vnode;
		while(temp != NULL) {
			if (temp->mark == mark) break;
			temp = temp->parent;
		}
		if (temp->data == unode->data) {
			printf("%d is an ancestor of %d.\n", u, v);
		} else if (temp->data == vnode->data) {
			printf("%d is an ancestor of %d.\n", v, u);
		} else {
			printf("LCA of %d and %d is %d.\n", u, v, temp->data);
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
	mark++;
}

int _1151() {
	int M, N;
	scanf("%d%d", &M, &N);
	for (int i=0; i<N; i++)
		scanf("%d", &inorder[i]);
	for (int i=0; i<N; i++)
		scanf("%d", &preorder[i]);
	BiTreeNode *root = buildBiTree(0, N-1, 0, N-1, NULL);
	for (int i=0; i<M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		judgeLCA(u, v, root);
	}
	//getchar();getchar();
	return 0;
}