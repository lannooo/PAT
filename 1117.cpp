#include <cstdio>
#include <map>
using namespace std;

int _1117() {
	map<int, int> miledays;
	int n, mile;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &mile);
		miledays[mile]++;
	}
	int cnt=0;
	int E = 0;
	// n-total days
	for (int i=0; i<=n; i++) {
		int days = (miledays.count(i) == 0) ? 0 : miledays[i]; // the days of riding i miles
		cnt += days; // days rides less or equal to i miles
		// (n-cnt) days rides more than i miles
		if ((n-cnt) >= i) E = i;
		else break;
	}

	printf("%d", E);
	return 0;
}