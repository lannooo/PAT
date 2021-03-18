#include <cstdio>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

set<long long> allsets[51];
set<long long> uset;
set<long long> interset;
int _1063() {
	int N, M;
	long long d;
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &M);
		for(int j=0; j<M; j++) {
			scanf("%lld", &d);
			allsets[i].insert(d);
		}
	}
	int K, s1, s2;
	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		scanf("%d%d", &s1, &s2);
		set_union(allsets[s1].begin(), allsets[s1].end(), allsets[s2].begin(), allsets[s2].end(), 
			inserter(uset, uset.begin()));
		set_intersection(allsets[s1].begin(), allsets[s1].end(), allsets[s2].begin(), allsets[s2].end(), 
			inserter(interset, interset.begin()));
		printf("%.1f%%\n", interset.size() * 100.0 / uset.size());
		uset.clear();
		interset.clear();
	}
	return 0;
}