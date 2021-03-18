#include <cstdio>
#include <vector>
using namespace std;
struct splitNode {
	int addr;
	int data;
	int next;
} spnodes[100000];

int _1133() {
	int firstnode, n, k;
	scanf("%d%d%d", &firstnode, &n, &k);
	for (int i=0; i<n; i++){
		int addr, data, next;
		scanf("%d%d%d", &addr, &data, &next);
		spnodes[addr].addr = addr;
		spnodes[addr].data = data;
		spnodes[addr].next = next;
	}
	int now = firstnode;
	vector<splitNode> v;
	vector<splitNode> ans;
	while(now != -1) {
		v.push_back(spnodes[now]);
		now = spnodes[now].next;
	}
	for (int i=0; i<v.size(); i++) {
		if (v[i].data < 0) ans.push_back(v[i]);
	}
	for (int i=0; i<v.size(); i++) {
		if (v[i].data >= 0 && v[i].data <= k) ans.push_back(v[i]);
	}
	for (int i=0; i<v.size(); i++) {
		if (v[i].data > k) ans.push_back(v[i]);
	}
	for (int i=0; i<ans.size()-1; i++) {
		printf("%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i+1].addr);
	}
	printf("%05d %d -1\n", ans[ans.size()-1].addr, ans[ans.size()-1].data);

	//getchar();getchar();
	return 0;
}