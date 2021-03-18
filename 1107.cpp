#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NUM = 1001;
// -1 means a single person,
// -n means there are n persons in a cluster, 
// positive x means its father's index is x
int father[MAX_NUM];
int hobby[MAX_NUM];

int findCluster(int x) {
	if (father[x] < 0) return x;
	int p = findCluster(father[x]);
	father[x] = p;
	return p;
}

void unionCluster(int x, int y) {
	int px = findCluster(x);
	int py = findCluster(y);
	if (px != py) {
		int temp = father[py];
		father[py] = px;
		father[px] += temp;// add count
	}
}

int _1107() {
	fill(father, father+MAX_NUM, -1);
	for(int i=0; i<MAX_NUM; i++) hobby[i] = -1;
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		int k, h;
		scanf("%d", &k);getchar();
		for(int j=0; j<k; j++) {
			scanf("%d", &h);
			if (hobby[h] == -1) {
				hobby[h] = i;
			} else {
				unionCluster(hobby[h], i);
			}
		}
	}
	vector<int> cnt;
	for (int i=1; i<=n; i++) {
		if (father[i] < 0) {
			cnt.push_back(abs(father[i]));
		}
	}
	sort(cnt.begin(), cnt.end());
	printf("%d\n", cnt.size());
	bool firstIn = true;
	for (int i=cnt.size()-1; i>=0; i--) {
		if (firstIn) {
			firstIn = false;
			printf("%d", cnt[i]);
		} else {
			printf(" %d", cnt[i]);
		}
	}

	return 0;
}