#include <cstdio>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> cliqueadj[201];

void judgeClique(unordered_set<int> &v) {
	if (v.size() == 1 && cliqueadj[*(v.begin())].size() == 0) {
		// single vertex with no edge
		printf("Yes\n");
		return;
	}
	int n = v.size();
	// judge count relations between v and e
	unordered_map<int, int> cnts;
	for (unordered_set<int>::iterator it = v.begin(); it!=v.end(); it++) {
		int vertex = *it;
		int size = cliqueadj[vertex].size();
		for (int i=0; i<size; i++) {
			cnts[cliqueadj[vertex][i]]++;
		}
	}
	for (unordered_set<int>::iterator it = v.begin(); it!=v.end(); it++) {
		int vertex = *it;
		if (cnts[vertex] != n-1) {
			printf("Not a Clique\n");
			return;
		}
	}
	for (unordered_map<int, int>::iterator it=cnts.begin();it!=cnts.end(); it++) {
		int vertex = it->first;
		int cnt = it->second;
		if (v.count(vertex) == 0) {// there more vertex to test whether it can be a maximal clique
			if (cnts[vertex] == n) {
				printf("Not Maximal\n");
				return;
			}
		}
	}
	printf("Yes\n");
	return;
}

int _1142() {
	int Nv,Ne, M, k;
	int v1, v2;
	scanf("%d%d", &Nv, &Ne);
	for (int i=0; i<Ne; i++) {
		scanf("%d%d", &v1, &v2);
		cliqueadj[v1].push_back(v2);
		cliqueadj[v2].push_back(v1);
	}
	scanf("%d", &M);
	for (int i=0; i<M; i++) {
		scanf("%d", &k);
		unordered_set<int> vertices;
		int d;
		for (int j=0; j<k; j++) {
			scanf("%d", &d);
			vertices.insert(d);
		}
		judgeClique(vertices);
	}
	//getchar();getchar();
	return 0;
}