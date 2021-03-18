#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct btnode{
	int left, right;
} nodes[10];

void level_order(int root, vector<int> &v) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int r = q.front();
		v.push_back(r);
		q.pop();
		if (nodes[r].right != -1) q.push(nodes[r].right);
		if (nodes[r].left != -1) q.push(nodes[r].left);
	}
}

void in_order(int root, vector<int> &v) {
	if (root == -1) return;
	in_order(nodes[root].right, v);
	v.push_back(root);
	in_order(nodes[root].left, v);
}

int _1102() {
	bool roots[10];
	fill(roots, roots+10, true);
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		char c1, c2;
		getchar();
		scanf("%c %c", &c1, &c2);
		int left, right;
		if (c1 == '-') left = -1;
		else left = c1 - '0';
		if (c2 == '-') right = -1;
		else right = c2 - '0';
		nodes[i].left = left;
		nodes[i].right = right;
		if (left != -1) roots[left] = false;
		if (right!= -1) roots[right] = false;
	}
	int r=-1;
	for (int i=0; i<n; i++) {
		if (roots[i]) {
			r=i;
			break;
		}
	}
	vector<int> inorder, levelorder;
	level_order(r, levelorder);
	in_order(r, inorder);
	for (int i=0; i<levelorder.size(); i++) {
		if (i==0) printf("%d", levelorder[i]);
		else printf(" %d", levelorder[i]);
	}
	printf("\n");
	for (int i=0; i<inorder.size(); i++) {
		if (i==0) printf("%d", inorder[i]);
		else printf(" %d", inorder[i]);
	}
	//getchar();getchar();
	return 0;
}