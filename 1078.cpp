#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;
	int sqr = (int)sqrt((double)n);
	for(int i=2; i<=sqr; i++) if (n % i == 0) return false;
	return true;
}

int _1078() {
	int msize, n;
	int tsize;
	scanf("%d%d", &msize, &n);
	for(int i=msize;;i++) {
		if (isPrime(i)) {
			tsize = i;
			break;
		}
	}
	vector<int> table(tsize);
	fill(table.begin(), table.end(), -1);
	int key;
	for(int i=0; i<n; i++) {
		scanf("%d", &key);
		int h = key % tsize;
		if (i == 0) {
			table[h] = key;
			printf("%d", h);
			continue;
		}
		if (table[h] == -1) {
			table[h] = key;
			printf(" %d", h);
		} else {
			int probeh, inc;
			for (inc = 1; inc < tsize; inc++) {
				probeh = (h + inc * inc) % tsize;
				if (table[probeh] == -1) {
					table[probeh] = key;
					printf(" %d", probeh);
					break;
				}
			}
			if (inc >= tsize) printf(" -");
		}
	}
	return 0;
}