#include <cstdio>

int min(int a, int b) {
	return (a < b) ? a : b;
}

int _1046() {
	int dists[100003] = {0};// distance from D1 to Di
	int total_dist=0; // the whole round trip distance 
	int n, m, i, d;
	scanf("%d", &n);
	for(i=1; i <= n; i++) {
		scanf("%d", &d);
		total_dist += d;
		dists[i+1] = total_dist;
	}
	int from, to;
	scanf("%d", &m);
	for (i=0; i<m; i++) {
		scanf("%d%d", &from, &to);
		// swap to make sure that from is smaller than to
		if (from > to){
			int temp = from;
			from = to;
			to = temp;
		}
		if (from == to) printf("0");
		else if (from == 1) printf("%d", min(dists[to], total_dist-dists[to]));
		else printf("%d", min(dists[to]-dists[from],total_dist-(dists[to]-dists[from])));

		if (i!=m-1) printf("\n");
	}

	return 0; 
}