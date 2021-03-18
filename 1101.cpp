#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
long long qs_origin[100000];
long long qs_sort[100000];
int _1101() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &qs_origin[i]);
	}
	copy(qs_origin, qs_origin+n, qs_sort);
	sort(qs_sort, qs_sort+n);
	vector<int> pivots;
	int max=-1;
	for (int i=0; i<n; i++) {
		if (qs_origin[i] > max) max = qs_origin[i];
		if (qs_origin[i] == qs_sort[i] && qs_origin[i] == max) {
			pivots.push_back(qs_origin[i]);
		}
	}
	printf("%d\n", pivots.size());
	for (int i=0; i<pivots.size(); i++) {
		if (i == 0) printf("%d", pivots[i]);
		else printf(" %d", pivots[i]);
	}
	printf("\n");
	//getchar();getchar();
	return 0;
}