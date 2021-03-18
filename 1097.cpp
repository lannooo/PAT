#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

struct llnode {
	int key;
	int next;
}nodes[100000];
set<int> vset;

bool exist(int key) {
	return (vset.count(abs(key)) > 0);
}

void add(int key) {
	vset.insert(abs(key));
}

int _1097() {
	int first, n;
	scanf("%d%d", &first, &n);
	int addr, v, next;
	for (int i=0; i<n; i++) {
		scanf("%d%d%d", &addr, &v, &next);
		nodes[addr].key = v;
		nodes[addr].next = next;
	}
	int delfirst = -1;
	int dellast = -1;
	int now = first, pre;
	while(now != -1) {
		if (exist(nodes[now].key)) {
			int temp = nodes[now].next;
			nodes[pre].next = nodes[now].next;
			// already in list, remove to deletelist
			if (delfirst == -1) {
				dellast = delfirst = now;
			} else {
				nodes[dellast].next = now;
				dellast = now;
			}
			nodes[now].next = -1;
			now = temp;
		} else {
			// kept in list
			add(nodes[now].key);
			pre = now;
			now = nodes[now].next;
		}
	}
	now = first;
	while (now != -1){
		if (nodes[now].next != -1) {
			printf("%05d %d %05d\n", now, nodes[now].key, nodes[now].next);
		} else {
			printf("%05d %d -1\n", now, nodes[now].key);
		}
		now = nodes[now].next;
	}
	now = delfirst;
	while(now != -1) {
		if (nodes[now].next != -1) {
			printf("%05d %d %05d\n", now, nodes[now].key, nodes[now].next);
		} else {
			printf("%05d %d -1\n", now, nodes[now].key);
		}
		now = nodes[now].next;
	}
	//getchar();getchar();

	return 0;
}