#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct RetailNode {
	int amount;
	int id;
}node;

int members[100000] = {-1};
int paths[100000] = {0};
vector<RetailNode> retails;

int pathOf(int pid) {
	if (pid == 0) return 0;
	if (paths[pid] != -1) return paths[pid];
	paths[pid] = 1 + pathOf(members[pid]);
	return paths[pid];
}

int _1079() {
	int n, cnt, amount, temp;
	double p, r;
	scanf("%d%lf%lf", &n, &p, &r);
	r = r/100;
	fill(paths, paths+n, -1);
	paths[0] = 0;
	for (int i=0; i<n; i++) {
		scanf("%d", &cnt);
		if (cnt == 0){
			// retails
			scanf("%d", &amount);
			node.amount = amount;
			node.id = i;
			retails.push_back(node);
		} else {
			// suppliers
			for(int j=0; j<cnt; j++) {
				scanf("%d", &temp);
				members[temp] = i;
				if(paths[i] != -1) paths[temp] = paths[i]+1;
			}
		}
	}
	double sum = 0.0;
	for(int i=0; i<retails.size(); i++) {
		int amount = retails[i].amount;
		int pid = retails[i].id;
		int path = pathOf(pid);
		sum += (1.0 * amount * p * pow(1.0+r, path));
	}
	printf("%.1f", sum);
	//getchar();getchar();
	return 0;
}