#include <cstdio>
#include <algorithm>
using namespace std;

const int IN = 1;
const int NOT_IN = 0;
const int UNCERTAIN = -1;

bool isValidPopSeq(int seq[], int instack[], int n, int capacity) {
	int max_pop = 0;
	int element;
	fill(instack+1, instack+1001, UNCERTAIN);
	for (int j=0; j<n; j++) {
		int in_stack_cnt = 0;
		int element = seq[j];
		if (element > max_pop) {
			// change uncertain status to in-stack status
			for (int k = element; k>=1; k--) {
				if (instack[k] == UNCERTAIN) {
					instack[k] = IN;
					in_stack_cnt ++;
				} else if (instack[k] == IN) {
					in_stack_cnt ++;
				}
			}
			// now the count of in_stack elements are out of capacity
			if (in_stack_cnt > capacity) return false;
			instack[element] = NOT_IN;
			max_pop = element;
		} else {
			// check if there are IN status nodes between element and maxpop
			for (int k=element+1; k<max_pop; k++) {
				if (instack[k] == IN) return false;
			}
			instack[element] = NOT_IN;
		}
	}
	return true;
}

int _1051() {
	int instack[1001] = {NOT_IN}; // instack[0] is not used but inited as NOT_IN
	int seq[1001];
	int capacity, n, checkNum;
	scanf("%d%d%d", &capacity, &n, &checkNum);

	for(int i=0; i<checkNum; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%d", &seq[j]);
		}
		if (isValidPopSeq(seq, instack, n, capacity)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	//getchar();getchar();
	return 0;
}