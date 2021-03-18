#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct expnode {
	string data;
	int left, right;
}expnodes[21];

void infixExpression(vector<string> &v, int root) {
	if (root == -1) return;
	string str = expnodes[root].data;
	if (expnodes[root].left == -1 && expnodes[root].right == -1) {//a leaf node, must be operand
		v.push_back(str);
	} else {
		v.push_back("(");
		infixExpression(v, expnodes[root].left);
		v.push_back(str);
		infixExpression(v, expnodes[root].right);
		v.push_back(")");
	}
}

int _1130() {
	bool isRoot[21];
	fill(isRoot, isRoot+21, true);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> expnodes[i].data >> expnodes[i].left >> expnodes[i].right;
		if (expnodes[i].left != -1) isRoot[expnodes[i].left] = false;
		if (expnodes[i].right != -1) isRoot[expnodes[i].right] = false;
	}

	if (n == 1) {
		cout << expnodes[1].data;
		return 0;
	}

	int root;
	for (root=1; root<=n; root++) {
		if (isRoot[root]) break; 
	}
	vector<string> v;
	infixExpression(v, root);

	for (int i=1; i<v.size()-1; i++) {
		cout << v[i];
	}

	//cin.get();cin.get();
	return 0;
}