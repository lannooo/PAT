#include <cstdio>
#include <vector>
using namespace std;

vector<int> pre_seq;
vector<int> in_seq;

int findPostFirst(int preL, int preR, int inL, int inR) {
	if (preL == preR) return pre_seq[preL];
	int root = pre_seq[preL];
	int index;
	for (index=inL; index<=inR; index++) {
		if (in_seq[index] == root) break;
	}
	int len = index-inL;
	if (len == 0) {//find from right sub-tree
		return findPostFirst(preL+1, preR, inL+1, inR);
	} else { // find from left sub-tree
		return findPostFirst(preL+1, preL+len, inL, index-1);
	}
}

int _1138() {
	int n, d;
	scanf("%d", &n);
	pre_seq.resize(n);
	in_seq.resize(n);
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		pre_seq[i] = d;
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		in_seq[i] = d;
	}
	int x = findPostFirst(0, n-1, 0, n-1);
	printf("%d", x);
	//getchar();getchar();
	return 0;
}