#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INVALID = 1000000;

int countBlackNode(vector<int> &seq, int L, int R, int parent) {
	if (L > R) return 0;
	if (parent < 0 && seq[L] < 0) return INVALID;
	if (L == R) {
		if (seq[L] > 0) return 1;// this node is black
		else return 0;//this node is red, but parent node is black
	} else {
		int root = seq[L];
		int index = -1;
		for (int i=L+1; i<=R; i++){
			if (abs(seq[i]) >= abs(root)) {
				index = i;
				break;
			}
		}
		if (index == -1 || index == 1) {
			int blackcnt = countBlackNode(seq, L+1, R, root);
			if (blackcnt>0) return INVALID;//not balanced
			else return (root > 0)? 1:0;
		} else {
			int cnt_left = countBlackNode(seq, L+1, index-1, root);
			int cnt_right = countBlackNode(seq, index, R, root);
			if (cnt_left != cnt_right || (cnt_left>=INVALID || cnt_right >= INVALID)) return INVALID;
			else return ((root > 0)? 1:0) + cnt_left;
		}
	}
}

bool judgeRedBlackTree(vector<int> seq){
	int root = seq[0];
	if (root < 0) return false;//root node bust be black
	return countBlackNode(seq, 0, seq.size()-1, 1) < INVALID;
}

int _1135() {
	int K, N, d;
	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		scanf("%d", &N);
		vector<int> v(N);
		for (int j=0; j<N; j++) {
			scanf("%d", &d);
			v[j] = d;
		}
		if (judgeRedBlackTree(v)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	//getchar();getchar();
	return 0;
}