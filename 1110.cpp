#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
struct cbtnode {
	int left, right;
}cbt[100];

int charToInt(string s) {
	if (s == "-") return -1;
	return stoi(s);
}

void levelseq(int root, int n){
	queue<int> q;
	q.push(root);
	int cnt = 0;
	int last = -1;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == -1) {
			if (cnt == n) {
				printf("YES %d", last);
			} else {
				printf("NO %d", root);
			}
			return;
		}
		cnt++;
		last = now;
		q.push(cbt[now].left);
		q.push(cbt[now].right);
	}
}

int findRoot(bool isRoot[], int n) {
	for (int i=0; i<n; i++) {
		if (isRoot[i]) {
			return i;
		}
	}
	return -1;
}

int _1110() {
	int n;
	bool isRoot[100];
	fill(isRoot, isRoot+100, true);
	cin >> n;
	for (int i=0; i<n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		cbt[i].left = charToInt(s1);
		cbt[i].right = charToInt(s2);
		if (cbt[i].left != -1) isRoot[cbt[i].left] = false;
		if (cbt[i].right != -1) isRoot[cbt[i].right] = false;
	}
	// find root
	int root = findRoot(isRoot, n);
	
	// get the level-order of tree
	levelseq(root, n);
	//getchar();getchar();
	
	return 0;
}