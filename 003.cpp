#include <cstdio>

int postorder[50000];
int inorder[50000];

int findLastPre(int postL, int postR, int inL, int inR) {
	if (postL == postR) return postorder[postL];
	int root = postorder[postR];
	int index;
	for (int i=inL; i<=inR; i++) {
		if (inorder[i] == root){
			index = i; break;
		}
	}
	if (index < inR) { // there are right tree, recursively find in right tree
		int len = inR-index;
		return findLastPre(postR-len, postR-1, index+1, inR);
	} else { // only left_subtree
		return findLastPre(postL, postR-1, inL, inR-1);
	}
}

int _003(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &postorder[i]);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &inorder[i]);
	}
	int x = findLastPre(0, n-1, 0, n-1);
	printf("%d", x);
	//getchar();getchar();
	return 0;
}