#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Mooncake {
	float storage;
	float price;
	float price_per_unit;
};

bool cmpMooncake(Mooncake a, Mooncake b) {
	return a.price_per_unit > b.price_per_unit;
}

int _1070() {
	int n,d;
	scanf("%d%d", &n, &d);
	vector<Mooncake> mooncakes(n);
	for (int i=0; i<n; i++) {
		scanf("%f", &mooncakes[i].storage);
	}
	for (int i=0; i<n; i++) {
		scanf("%f", &mooncakes[i].price);
		mooncakes[i].price_per_unit = mooncakes[i].price / mooncakes[i].storage;
	}
	sort(mooncakes.begin(), mooncakes.end(),cmpMooncake);
	float profit = 0.0;
	for (int i=0; i<n; i++) {
		if (mooncakes[i].storage <= 0) continue;
		if (mooncakes[i].storage <= d) {
			d -= mooncakes[i].storage;
			profit += mooncakes[i].price;
		} else {
			profit += (d * mooncakes[i].price_per_unit);
			break;
		}
	}
	printf("%.2f", profit);
	//getchar();getchar();
	return 0;
}