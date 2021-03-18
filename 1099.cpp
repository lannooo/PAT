#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Node_BST {
	int key;
	int count;// count of the tree nodes
	int left_index, right_index;
}nodes[100];

int countNode(int index) {
	if (index == -1) return 0;
	if (nodes[index].count != -1) return nodes[index].count;
	nodes[index].count = countNode(nodes[index].left_index) + countNode(nodes[index].right_index) + 1;
	return nodes[index].count;
}

void fillTree(int seq[], int L, int R, int root) {
	if (root == -1 || L > R)return; 
	int leftcnt = countNode(nodes[root].left_index);
	int rightcnt = countNode(nodes[root].right_index);
	nodes[root].key = seq[L+leftcnt];
	if (leftcnt > 0) fillTree(seq, L, L+leftcnt-1, nodes[root].left_index);
	if (rightcnt> 0) fillTree(seq, L+leftcnt+1, R, nodes[root].right_index);
}

void printLevelOrder(int seq[], int root) {
	queue<int> q;
	vector<int> level;
	q.push(root);
	while(!q.empty()){
		int nodeIndex = q.front();q.pop();
		level.push_back(nodes[nodeIndex].key);
		if (nodes[nodeIndex].left_index != -1) q.push(nodes[nodeIndex].left_index);
		if (nodes[nodeIndex].right_index != -1) q.push(nodes[nodeIndex].right_index);
	}
	for (int i=0; i<level.size(); i++) {
		if (i!=0) printf(" ");
		printf("%d", level[i]);
	}
}

int _1099() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d%d", &nodes[i].left_index, &nodes[i].right_index);
		nodes[i].count = -1;
	}
	int cnt = countNode(0);
	int sequence[100];
	for (int i=0; i<n; i++) {
		scanf("%d", &sequence[i]);
	}
	// sort increasingly
	sort(sequence, sequence+n);
	fillTree(sequence, 0, n-1, 0);
	printLevelOrder(sequence, 0);
	//getchar();getchar();
	return 0;
}