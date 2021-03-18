#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> posiCoupons;
vector<int> negaCoupons;
vector<int> posiProducts;
vector<int> negaProducts;

bool cmp_1037(int a, int b) {
	return a > b;
}

int _1037() {
	int nc, np;
	int c, p;
	scanf("%d", &nc);
	for (int i=0; i<nc; i++){
		scanf("%d", &c);
		if (c > 0) posiCoupons.push_back(c);
		else if (c < 0) negaCoupons.push_back(c);
	}
	scanf("%d", &np);
	for (int i=0; i<np; i++) {
		scanf("%d", &p);
		if (p > 0) posiProducts.push_back(p);
		else if (p < 0) negaProducts.push_back(p);
	}
	long long sum = 0;
	if (!posiCoupons.empty() && !posiProducts.empty()) {
		// sort from big to small
		sort(posiCoupons.begin(), posiCoupons.end(), cmp_1037);
		sort(posiProducts.begin(), posiProducts.end(), cmp_1037);
		int size = min(posiCoupons.size(), posiProducts.size());
		for(int i=0; i<size; i++) sum += (posiCoupons[i] * posiProducts[i]);
	}
	if (!negaCoupons.empty() && !negaProducts.empty()) {
		sort(negaCoupons.begin(), negaCoupons.end());
		sort(negaProducts.begin(), negaProducts.end());
		int size = min(negaCoupons.size(), negaProducts.size());
		for(int i=0; i<size; i++) sum += (negaCoupons[i] * negaProducts[i]);
	}
	printf("%lld", sum);
	//getchar();getchar();
	
	return 0;
}