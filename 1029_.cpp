#include <cstdio>
#include <vector>
using namespace std;

vector<int> v1, v2;

int mid(int low, int high) {
	if ((high -low +1)%2 == 0) return low + (high-low+1)/2-1;
	return low + (high-low+1)/2;
}

int findMedianSingle(vector<int> &v, int x, int low, int high) {
	v[high+1] = x;
	int temp;
	// buble sort the last number
	for (int i=high; i>=low; i--) {
		if (v[i] > v[i+1]) {
			temp = v[i+1];
			v[i+1] = v[i];
			v[i] = temp;
		} else {
			break;
		}
	}
	return v[mid(low, high+1)];
}

int findMedian(int low1, int high1, int low2, int high2) {
	int length1 = high1-low1+1;
	int length2 = high2-low2+1;
	if (length1 == 1) {
		return findMedianSingle(v2, v1[low1], low2, high2);
	}
	if (length2 == 1) {
		return findMedianSingle(v1, v2[low2], low1, high1);
	}
	int mid1 = mid(low1, high1);
	int mid2 = mid(low2, high2);
	if (v1[mid1] == v2[mid2]) return v1[mid1];
	else if(v1[mid1] < v2[mid2]) {
		int minRemove = min(mid1-low1, high2-mid2);
		if (minRemove > 0) return findMedian(low1+minRemove, high1, low2, high2-minRemove);
		else return findMedian(low1+1, high1, low2, high2-1);
	} else {
		int minRemove = min(mid2-low2, high1-mid1);
		if (minRemove > 0) return findMedian(low1, high1-minRemove, low2+minRemove, high2);
		else return findMedian(low1, high1-1, low2+1, high2);
	}
}

int _1029() {
	int n1, n2;
	// read sequences
	scanf("%d", &n1);
	v1.resize(n1+1);
	for(int i=0; i<n1; i++) {
		scanf("%d", &v1[i]);
	}
	scanf("%d", &n2);
	v2.resize(n2+1);
	for(int i=0; i<n2; i++) {
		scanf("%d", &v2[i]);
	}

	int x = findMedian(0, n1-1, 0, n2-1);

	printf("%d", x);

	//getchar();getchar();
	return 0;
}
