#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool ismaxheap = false;
bool isminheap = false;
bool isnotheap = false;
void dfs_1155(int heap[], int root, int n, vector<int> &path) {
	if (root > n) return;
	path.push_back(heap[root]);
	int left = root * 2;
	if (left > n) {
		// a leaf node, print the path
		for (int i=0; i<path.size(); i++) {
			if (i!=0) printf(" %d", path[i]);
			else printf("%d", path[i]);
		}
		printf("\n");
	} else {
		if (left+1 <= n) {
			if (heap[root] >= max(heap[left], heap[left+1])){
				ismaxheap = true;
			} else if (heap[root] <= min(heap[left], heap[left+1])) {
				isminheap = true;
			} else {
				isnotheap = true;
			}
			dfs_1155(heap, left+1, n, path);
			dfs_1155(heap, left, n, path);
		} else {
			if (heap[root] >= heap[left]){
				ismaxheap = true;
			} else if (heap[root] <= heap[left]) {
				isminheap = true;
			} else {
				isnotheap = true;
			}
			dfs_1155(heap, left, n, path);
		}
	}
	path.pop_back();
}

int _1155() {
	int heap[1001];
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &heap[i]);
	}
	vector<int> v;
	dfs_1155(heap, 1, n, v);
	if (isnotheap) {
		printf("Not Heap");
	} else if (isminheap && !ismaxheap) {
		printf("Min Heap");
	} else if (!isminheap && ismaxheap) {
		printf("Max Heap");
	} else {
		printf("Not Heap");
	}
	//getchar();getchar();
	return 0;
}