#include <cstdio>

struct cnode {
	char data;
	int next;
	int flag;
} nodes[100001];

int _1032() {
	int address1, address2;
	int n;
	scanf("%d%d%d", &address1, &address2, &n);
	for(int i=0; i<n; i++) {
		int addr, next;
		char c;
		scanf("%d %c %d", &addr, &c, &next);
		nodes[addr].data = c;
		nodes[addr].next = next;
		nodes[addr].flag = 0;
	}
	int now = address1;
	while(now != -1) {
		nodes[now].flag = 1;
		now = nodes[now].next;
	}
	int common = -1;
	now = address2;
	while(now != -1) {
		if (nodes[now].flag == 1) {
			common = now;
			break;
		}
		now = nodes[now].next;
	}
	if (common == -1) {
		printf("-1");
	} else {
		printf("%05d", common);
	}
	//getchar();getchar();
	return 0;
}