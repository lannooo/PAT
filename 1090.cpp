#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int members2[100000];
bool visit2[100000] = {false};
int path2[100000]= {0};

int pathOf2(int i) {
	if (i == -1) return 0;
	if (visit2[i]) return path2[i];
	path2[i] = pathOf2(members2[i]) + 1;
	visit2[i] = true;
	return path2[i];
}

int _1090() {
	int n;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	r = r / 100.0;
	for (int i=0; i<n; i++) {
		scanf("%d", &members2[i]);
	}
	if (n==1) {
		printf("%.2f %d", p, 1);
		return 0;
	}

	int maxcnt = 1;
	int maxpath = 0;
	int pv;
	for (int i=0; i<n; i++) {
		pv = pathOf2(i);
		if (pv > maxpath) {
			maxcnt = 1;
			maxpath = pv;
		} else if (pv == maxpath){
			maxcnt++;
		}
	}

	printf("%.2f %d", p*pow(1.0+r, (double)(maxpath-1)), maxcnt);
	//getchar();getchar();
	return 0;
}