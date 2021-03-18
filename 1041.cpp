#include <cstdio>

struct BetNode {
	int number;
	int count;
	struct BetNode *next;
	BetNode() {
		number = -1;
		count = -1;
		next = NULL;
	}
	BetNode(int n) {
		number = n;
		count = 1;
		next = NULL;
	}
};

typedef BetNode Node;
typedef BetNode *NodeP;

NodeP nodes[10001] = {NULL};

int _1041() {
	NodeP head = new Node();
	NodeP tail = head;
	int n, i, d;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &d);
		if(nodes[d] == NULL){ // add a new node to link list
			NodeP node = new BetNode(d);
			tail->next = node;
			tail = node;
			nodes[d] = node;
		} else {
			(nodes[d]->count)++;
		}
	}
	NodeP p;
	for (p=head->next; p != NULL; p=p->next) {
		if (p->count == 1) break;
	}
	if (p==NULL) printf("None");
	else printf("%d", p->number);

	return 0;
}