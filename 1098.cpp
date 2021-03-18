#include <cstdio>


void adjustdown(int nums[], int now, int n) {
	int child = now * 2;
	while(child < n) {
		if (child+1<n && nums[child+1] > nums[child]) child++;
		int temp = nums[child];
		nums[child] = nums[now];
		nums[now] = temp;
		now = child;
		child = now * 2;
	}
}

int _1098() {
	int n;
	int origin[101], partial[101];
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &origin[i]);
	for (int i=1; i<=n; i++) scanf("%d", &partial[i]);
	// judge whether it is a Insertion Sort
	int unsortp = n;
	for (int i=2; i<=n; i++) {
		if (partial[i] < partial[i-1]) {
			unsortp = i;
			break;
		}
	}
	bool insertsort = true;
	for (int i=unsortp; i<=n; i++) {
		if (partial[i] != origin[i]) {
			insertsort=false;
			break;
		}
	}

	if (insertsort) {
		int temp = partial[unsortp];
		int i;
		for (i=unsortp-1; i>=1; i--) {
			if (partial[i] > temp) {
				partial[i+1] = partial[i];
			} else break;
		}
		partial[i+1] = temp;
	} else {
		int temp = partial[1];
		int i;
		for (i=n; i>=1; i--) {
			if (partial[i] < temp) break;
		}
		// partial[0]-partial[i] is unsorted
		partial[1] = partial[i];
		partial[i] = temp;
		adjustdown(partial, 1, i);
	}
	if (insertsort) {
		printf("Insertion Sort\n");
	} else {
		printf("Heap Sort\n");
	}
	for (int i=1; i<=n; i++) {
		if (i == 1)
			printf("%d", partial[i]);
		else 
			printf(" %d", partial[i]);
	}
	//getchar();getchar();
	return 0;
}
