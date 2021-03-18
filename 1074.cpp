#include <cstdio>
#include <iostream>
using namespace std;
struct Node {
	int data;
	int next;
} nodes[100000];


int reverseLinkedList(int head, int k) {
	if (head == -1) return -1;
	int tail = head;
	int cnt = 1;
	while (cnt < k && tail != -1) {
		tail = nodes[tail].next;
		cnt ++;
	}
	if (tail == -1) return head;
	// need to reverse
	int temp = head;
	while(head != tail) {
		head = nodes[head].next;
		nodes[temp].next = nodes[tail].next;
		nodes[tail].next = temp;
		temp = head;
	}
	cnt = 1;
	while(cnt < k) {
		tail = nodes[tail].next;
		cnt++;
	}
	nodes[tail].next = reverseLinkedList(nodes[tail].next, k);
	return head;
}

int _1074() {
	int head, n, k;
	cin >> head >> n >> k;
	int addr, data, next;
	for (int i=0; i<n; i++) {
		cin >> addr >> data >> next;
		nodes[addr].data = data;
		nodes[addr].next = next;
	}
	int first = reverseLinkedList(head, k);
	while(first != -1) {
		next = nodes[first].next;
		if (next != -1) {
			printf("%05d %d %05d\n", first, nodes[first].data, next);
		} else {
			printf("%05d %d -1", first, nodes[first].data);
		}
		first = next;
	}

	return 0;
}