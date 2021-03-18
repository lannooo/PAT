#include <cstdio>
#include <vector>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

Node* newnode(int key) {
	Node *node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}

vector<int> pre, post;
bool notunique = false;

Node* rebuildTree(int preL, int preR, int postL, int postR) {
	if (preL > preR) return NULL;
	int rootkey = pre[preL];
	Node *root = newnode(rootkey);
	if (preL == preR) return root;
	int nextkey = pre[preL+1];
	int inext = -1;
	for (int i=postL; i<postR; i++) {
		if (post[i] == nextkey) {
			inext = i;break;
		}
	}
	if (inext == postR-1) { // selection is not unique, nextkey can be in left-subtree or right-subtree
		notunique = true;
		root->left = rebuildTree(preL+1, preR, postL, postR-1);
	} else if (inext == postL){ //only nextkey in left sub-tree
		root->left = newnode(nextkey);
		root->right = rebuildTree(preL+2, preR, postL+1, postR-1);
	} else {
		int len = inext-postL+1;
		root->left = rebuildTree(preL+1, preL+len, postL, inext);
		root->right = rebuildTree(preL+1+len, preR, inext+1, postR-1); 
	}
	return root;
}

void print_inorder(Node *root, int &i) {
	if (root == NULL) return;
	print_inorder(root->left, i);
	if (i==0)
		printf("%d", root->key);
	else
		printf(" %d", root->key);
	i++;
	print_inorder(root->right, i);
}

int _1119() {
	int n,d;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		pre.push_back(d);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		post.push_back(d);
	}
	Node *root = rebuildTree(0, n-1, 0, n-1);
	// get print inorder sequence
	if (notunique) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
	int i = 0;
	print_inorder(root, i);
	printf("\n");
	//getchar();getchar();
	return 0;
}