#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int birds[10001];
int totalbirds = 0;
int birds_find(int x) {
	if (birds[x] == -1) return x;
	else {
		int p = birds_find(birds[x]);
		birds[x] = p;
		return p;
	}
}

void birds_union(vector<int> &v) {
	if (v[0] > totalbirds) totalbirds = v[0];
	int root = birds_find(v[0]);
	int bp;
	for (int i=1; i<v.size(); i++) {
		if (v[i] > totalbirds) totalbirds = v[i];
		bp = birds_find(v[i]);
		if (root != bp) birds[bp] = root;
	}
}

int _1118() {
	int n, k;
	fill(birds, birds+10001, -1);
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &k);
		vector<int> v;
		int d;
		for (int j=0; j<k; j++) {
			scanf("%d", &d);
			v.push_back(d);
		}
		birds_union(v);
		v.clear();
	}
	int cnt = 0;
	for(int i=1; i<=totalbirds; i++) {
		if (birds[i] == -1) cnt++;
	}
	printf("%d %d\n", cnt, totalbirds);
	int query, b1, b2;
	scanf("%d", &query);
	for (int i=0; i<query;i++) {
		scanf("%d%d", &b1, &b2);
		if (birds_find(b1) == birds_find(b2)) printf("Yes\n");
		else printf("No\n");
	}
	//getchar();getchar();
	return 0;
}