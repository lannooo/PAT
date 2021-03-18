#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool isMaxHeap2 = false;
bool isMinHeap2 = false;
bool isNotHeap2 = false;

void postOrderTraversal(int heap[], int i, int n, vector<int> &v) {
	if (i > n) return;
	if (i*2 > n) {
		// leaf node
		v.push_back(heap[i]);
		return;
	}
	int left = i*2, right;
	if (left+1 > n) {//noly left child
		if (heap[i] < heap[left]) isMinHeap2 = true;
		else if (heap[i] > heap[left]) isMaxHeap2 = true;
		//if equals, cannot judge
		postOrderTraversal(heap, left, n, v);
		v.push_back(heap[i]);
	} else {//both child
		right = left+1;
		if (heap[i] < min(heap[left], heap[right])) isMinHeap2 = true;
		else if (heap[i] > max(heap[left], heap[right])) isMaxHeap2 = true;
		else if (heap[i]==heap[left] && heap[i]==heap[right]);//do nothing
		else isNotHeap2 = true;
		postOrderTraversal(heap, left, n, v);
		postOrderTraversal(heap, right, n, v);
		v.push_back(heap[i]);
	}
}

int _1147() {
	int M, N;
	scanf("%d%d", &M, &N);
	int heap[1001];
	for (int i=0; i<M; i++) {
		for (int j=1;j<=N; j++) {
			scanf("%d", &heap[j]);
		}
		vector<int> v;
		postOrderTraversal(heap, 1, N, v);
		if (isNotHeap2) printf("Not Heap\n");
		else if (isMaxHeap2 && !isMinHeap2) printf("Max Heap\n");
		else if (isMinHeap2 && !isMaxHeap2) printf("Min Heap\n");
		else printf("Not Heap\n");
		for (int i=0; i<v.size(); i++) {
			if (i!=0) printf(" %d", v[i]);
			else printf("%d", v[i]);
		}
		printf("\n");
		isMaxHeap2 = isMinHeap2 =isNotHeap2= false;
	}
	//getchar();getchar();
	return 0;
}