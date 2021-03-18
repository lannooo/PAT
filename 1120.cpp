#include <cstdio>
#include <algorithm>
using namespace std;

int getfriendid(int n) {
	int id = 0;
	while (n > 0) {
		id += (n%10);
		n /= 10;
	}
	return id;
}

int _1120() {
	bool exists[100] = {false};//exists[id] to mark whether the friend id has be caculated and added to ids set.
	int fids[100];
	int idcount = 0;
	int n, d;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &d);
		int id = getfriendid(d);
		if(!exists[id]) {
			fids[idcount++] = id;
			exists[id] = true;
		}
	}
	sort(fids, fids+idcount);
	printf("%d\n", idcount);
	for(int i=0; i<idcount; i++) {
		if (i!=0) printf(" ");
		printf("%d", fids[i]);
	}
	//getchar();getchar();
	return 0;
}