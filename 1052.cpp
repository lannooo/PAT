#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct LinkedNode{
	int addr;
	int key;
	int next;
}list[100000];

bool cmp_1052(LinkedNode a, LinkedNode b) {
	return a.key <b.key;
}

int _1052() {
	int n;
	int head;
	int addr, key, next;
	scanf("%d%d", &n, &head);
	for (int i=0; i<n; i++) {
		scanf("%d%d%d", &addr, &key, &next);
		list[addr].addr = addr;
		list[addr].key = key;
		list[addr].next = next;
	}
	if (head == -1) {
		printf("0 -1");
		return 0;
	}
	vector<LinkedNode> v;
	while(head != -1) {
		v.push_back(list[head]);
		head = list[head].next;
	}
	sort(v.begin(), v.end(),cmp_1052);
	int size = v.size();
	printf("%d %05d\n", size, v[0].addr);
	for (int i=0; i<size; i++) {
		if (i != size-1) {
			printf("%05d %d %05d\n", v[i].addr, v[i].key, v[i+1].addr);
		} else {
			printf("%05d %d %d", v[i].addr, v[i].key, -1);
		}
	}
	//getchar();getchar();
	return 0;
}