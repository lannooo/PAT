#include <cstdio>
#include <vector>
using namespace std;

vector<int> topoadj[1001];
vector<int> in_degree;

bool isTopoOrder(vector<int> v) {
	vector<int> indeg(in_degree.begin(), in_degree.end());
	for (int i=0; i<v.size(); i++) {
		int v1 = v[i];
		if (indeg[v1] != 0) return false;
		// remove all the edges of v[i]
		//(i.e. decrease the corresponding indegree of the end vertex on an edge)
		for (int j=0; j<topoadj[v1].size(); j++) {
			indeg[topoadj[v1][j]]--;
		}
	}
	return true;
}

int _1146() {
	int N, M, K;
	scanf("%d%d", &N, &M);
	in_degree.resize(N+1, 0);
	in_degree[0]=-1;// not used
	int v1, v2;
	for (int i=0; i<M; i++) {
		scanf("%d%d", &v1, &v2);
		topoadj[v1].push_back(v2);
		in_degree[v2]++;
	}
	scanf("%d", &K);
	vector<int> ans;
	for (int i=0; i<K; i++) {
		vector<int> v;
		int d;
		for (int j=0; j<N; j++) {
			scanf("%d", &d);
			v.push_back(d);
		}
		if (!isTopoOrder(v)) {
			ans.push_back(i);
		}
	}
	for (int i=0; i<ans.size(); i++) {
		if (i!=0) printf(" %d", ans[i]);
		else printf("%d", ans[i]);
	}
	//getchar();getchar();
	return 0;
}