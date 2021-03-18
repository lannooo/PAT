#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<int> hamigraph[201];
bool hamivisit[201];

bool allnodesvisited(int n) {
	for (int i=1; i<=n; i++) {
		if (!hamivisit[i]) return false;
	}
	return true;
}

bool isHamiltonian(int n, vector<int> v){
	if (v.size() != n+1) return false;
	fill(hamivisit, hamivisit+201, false);
	int start = v[0];
	int last = start;
	int now = start;
	hamivisit[start] = true;
	for (int i=1; i<v.size(); i++) {
		now = v[i];
		if (!hamivisit[now]) {// has not visited, test whether there is a path from last to now
			if (hamigraph[last].count(now) != 0) {
				hamivisit[now] = true;
			} else {// no path to here
				return false;
			}
		} else {// has visited
			// if it is a hamiltonian circle, the conditions are as follows:
			// 1. end last node should be the start node
			// 2. all the node should be only visited only once except the first(last) one
			// 3. there is a path to get to here
			// 4. all node is visited before the last node
			if (i == n  && now == start && hamigraph[last].count(now) != 0 && allnodesvisited(n)) {
				// a hamiltonian circle
				return true;
			} else {
				return false;
			}
		}
		last = now;
	}
	return false;
}

int _1122() {
	int n, m;
	scanf("%d%d", &n, &m);
	int v1, v2;
	for (int i=0; i<m; i++) {
		scanf("%d%d", &v1, &v2);
		hamigraph[v1].insert(v2);
		hamigraph[v2].insert(v1);
	}
	int k;
	scanf("%d", &k);
	for (int i=0; i<k; i++) {
		int cnt, d;
		vector<int> v;
		scanf("%d", &cnt);
		for (int j=0; j<cnt; j++) {
			scanf("%d", &d);
			v.push_back(d);
		}
		if (isHamiltonian(n, v)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	//getchar();getchar();
	return 0;
}