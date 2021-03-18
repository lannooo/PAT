#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool primeSize[20000];

int toPrimeSize(int msize) {
	while (!primeSize[msize]) msize++;
	return msize;
}

void findAllPossiblePrimeSize() {
	fill(primeSize, primeSize+20000, true);
	primeSize[0]=primeSize[1]=false;
	for (int i=2; i<20000; i++) {
		if (primeSize[i]) {
			for (int next = i+i; next<20000; next=next+i) 
				primeSize[next] = false;
		}
	}
}

int hashInc(int key, int tsize, int inc) {
	return ((key % tsize) + inc * inc) % tsize;
}

bool insertNum(vector<int> &v, int tsize, int x) {
	int h = hashInc(x, tsize, 0);
	if (v[h] == -1) {
		v[h] = x;
		return true;
	}
	for (int inc = 1; inc <= tsize; inc++) {
		h = hashInc(x, tsize, inc);
		if (v[h] == -1) {
			v[h] = x;
			return true;
		}
	}
	return false;
}

int compareTimes(vector<int> &v, int tsize, int x) {
	for (int inc = 0; inc <= tsize; inc++) {
		int h = hashInc(x, tsize, inc);
		if (v[h] == x || v[h] == -1) {
			return inc+1;
		}
	}
	return tsize+1;
}

int _1145() {
	findAllPossiblePrimeSize();
	int msize, n, m;
	scanf("%d%d%d", &msize, &n, &m);
	int tsize = toPrimeSize(msize);
	vector<int> v(tsize, -1);
	int d;
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		if (!insertNum(v, tsize, d)) {
			printf("%d cannot be inserted.\n", d);
		}
	}
	int cnt=0;
	for (int i=0; i<m; i++) {
		scanf("%d", &d);
		cnt+=compareTimes(v, tsize, d);
	}
	printf("%.1f", 1.0*cnt/m);
	//getchar();getchar();
	return 0;
}