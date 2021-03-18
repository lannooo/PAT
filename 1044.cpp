#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
	int from;
	int to;
}solution;

long long minpayment = 200000000;
int diamonds[100001];

int _1044() {
	int n;
	long long m;
	vector<Solution> solutions;
	scanf("%d%lld", &n, &m);
	
	for (int i=1; i<=n; i++) {
		scanf("%d",&diamonds[i]);
	}
	long long amount;
	for(int from=1; from<=n; from++) {
		int to = from;
		amount = 0;
		do {
			amount += diamonds[to++];
			if (amount >= m) {
				break;
			}
		}while(to <= n);

		// if amount is still smaller than m until added the last diamond,
		// there is no more solution in the next loop, just break to print all the solutions
		if (amount < m) break;
		// this amount is greater or equal to m, update solutions
		if (amount < minpayment){
			minpayment = amount;
			solutions.clear();
			solution.from = from;
			solution.to = to-1;
			solutions.push_back(solution);
		} else if (amount == minpayment) {
			solution.from = from;
			solution.to = to-1;
			solutions.push_back(solution);
		}
	}
	bool firstIn = true;
	for(vector<Solution>::iterator it = solutions.begin(); it != solutions.end(); it++) {
		if (firstIn) firstIn = false;
		else printf("\n");
		printf("%d-%d", (*it).from, (*it).to);
	}
	//getchar();getchar();
	return 0;
}