#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int couples[100000];
int _1121 () {
	fill(couples, couples+100000, -1);// mark as single first
	int n, c1, c2;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d%d", &c1, &c2);
		couples[c1] = c2;
		couples[c2] = c1;
	}
	int m, id;
	unordered_set<int> notsingle;
	vector<int> guests;
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d", &id);
		if (couples[id] != -1) {
			if (notsingle.count(couples[id]) != 0) {
				// remove it
				notsingle.erase(notsingle.find(couples[id]));
			} else {
				notsingle.insert(id);
			}
		} else {
			guests.push_back(id);
		}
	}
	if (!notsingle.empty()) {
		guests.insert(guests.end(), notsingle.begin(), notsingle.end());
	}
	sort(guests.begin(), guests.end());
	printf("%d\n", guests.size());
	for (int i=0; i<guests.size(); i++) {
		if (i!=0) printf(" %05d", guests[i]);
		else printf("%05d", guests[i]);
	}
	//getchar();getchar();
	return 0;
}