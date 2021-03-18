#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int _1113() {
	vector<int> nums;
	int n, d;
	scanf("%d", &n);
	nums.resize(n);
	for (int i=0; i<n; i++) {
		scanf("%d", &d);
		nums[i] = d;
	}
	sort(nums.begin(), nums.end());

	int mid = n / 2;
	int sum1=0, sum2=0;
	for (int i=0; i<mid; i++) {
		sum1+=nums[i];
	}
	for (int i=mid; i<n; i++) {
		sum2+=nums[i];
	}

	printf("%d %d", n%2, abs(sum1-sum2));
	//getchar();getchar();
	return 0;
}