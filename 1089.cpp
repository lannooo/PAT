#include <cstdio>
#include <algorithm>
using namespace std;

bool isSorted(int nums[], int from , int to) {
	for (int i=from+1; i < to; i++) {
		if (nums[i] < nums[i-1]) return false;
	}
	return true;
}

void mergeSortOnceMore(int nums[], int from , int to) {
	sort(nums+from, nums+to);
}

int _1089() {
	int origin[100];
	int partial[100];
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &origin[i]);
	for(int i=0; i<n; i++) scanf("%d", &partial[i]);
	// find the unsorted part start index
	int unsortp;
	for (unsortp = 1; unsortp<n; unsortp++) {
		if (partial[unsortp] < partial[unsortp-1]) break;
	}
	bool isInsertSort = true;
	for (int i=unsortp; i<n; i++) {
		if (partial[i] != origin[i]) {
			isInsertSort = false;
			break;
		}
	}
	if (isInsertSort) {
		int index, temp = partial[unsortp];
		for (index=unsortp-1; index>=0; index--) {
			if (partial[index] > temp) {
				partial[index+1] = partial[index];
			}else break;
		}
		partial[index+1] = temp;
	} else {
		int step;
		// find minimum sorted sublist length
		for (step=2; step <= n; step=step*2) {
			bool sorted = true;
			for(int i=0; i*step<n; i++) {
				if (!isSorted(partial, i*step, min(i*step+step, n))) {
					sorted = false;
					break;
				}
			}
			if (!sorted) break;
		}
		for (int i=0; i*step<n; i++) {
			mergeSortOnceMore(partial, i*step, min(i*step+step, n));
		}
	}
	if (isInsertSort)
		printf("Insertion Sort\n");
	else
		printf("Merge Sort\n");
	for(int i=0; i<n; i++) {
		if (i!=0) printf(" %d", partial[i]);
		else printf("%d", partial[i]);
	}

	//getchar();getchar();
	return 0;
}