#include <cstdio>
#include <cmath>

bool is_prime(int r){
	int sqr = (int)sqrt((double)r);
	for (int i=2; i<=sqr; i++) {
		if (r % i == 0) return false;
	}
	return true;
}

int _1116() {
	int ranks[10000] = {0};
	bool checked[10000] = {false};
	int n, id;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%04d", &id);
		ranks[id] = i;
	}

	int k;
	scanf("%d", &k);
	for (int i=0; i<k; i++) {
		scanf("%04d", &id);
		if (checked[id]) printf("%04d: Checked", id);
		else {
			int r = ranks[id];
			if (r == 0) printf("%04d: Are you kidding?", id);
			else {
				if (r == 1) printf("%04d: Mystery Award", id);
				else if(is_prime(r)) printf("%04d: Minion", id);
				else printf("%04d: Chocolate", id);
				checked[id]=true;
			}
		}
		if(i != k-1) printf("\n");
	}

	//getchar();getchar();
	return 0;
}