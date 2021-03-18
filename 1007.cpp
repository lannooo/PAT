#include <cstdio>

int seq[10000];

int _1007() {
	int k;
	scanf("%d", &k);
	for(int i=0; i<k; i++) scanf("%d", &seq[i]);
	// to find the first positive number , if not exist, print 0
	int first = 0;
	for (; first<k; first++) {
		// if has zero ...
		if (seq[first] >= 0) break;
	}
	// all negative
	if(first == k) {
		printf("0 %d %d", seq[0], seq[k-1]);
		return 0;
	}

	// search from first positive number
	int from = first;
	long long sum = seq[first];
	long long max_sum = -1;
	int max_from = -1;
	for(int i=first+1; i<k; i++) {
		if (seq[i] > 0){
			sum += seq[i];
		} else if (seq[i] + sum > 0){ // seq[i]<=0 but seq[i]+sum is still positive
			if (sum > max_sum){
				max_sum = sum;
				max_from = from;
			}
			sum+=seq[i];
		} else { // seq[i]<=0 and seq[i]+sum is negative, we need to reset the start point to sum
			if (sum > max_sum) {
				max_sum = sum;
				max_from = from;
			}
			// re-search the first positive number
			while(i<k && seq[i] <= 0) i++;
			if (i == k) break;// stop for-loop
			from = i;
			sum = seq[i];
		}
	}
	if (sum > max_sum) {
		max_sum = sum;
		max_from = from;
	}
	int max_to = max_from;
	long long temp = seq[max_to];
	while(temp != max_sum) {
		max_to++;
		temp += seq[max_to];
	}

	printf("%lld %d %d", max_sum, seq[max_from], seq[max_to]);
	//getchar();getchar();

	return 0;
}