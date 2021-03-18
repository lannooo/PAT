#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int supplymember[100000];
int supplylevel[100000];

int levelOf(int index) {
	if (index == -1) return 0;
	if (supplylevel[index] != -1) return supplylevel[index];
	supplylevel[index] = 1 + levelOf(supplymember[index]);
	return supplylevel[index];
}

int _1106() {
	int n;
	double P, r;
	cin >> n >> P >> r;
	r = r / 100.0;
	supplymember[0] = -1;// root supplier
	fill(supplylevel, supplylevel+n, -1);
	vector<int> retailers;
	for (int i=0; i<n; i++) {
		int k, id;
		cin >> k;
		if (k > 0) { // not retailer
			for (int j=0; j<k; j++) {
				cin >> id;
				supplymember[id] = i;
			}
		} else { // a retailer
			retailers.push_back(i);
		}
	}
	int cnt = 0;
	int minLevel = n;
	for (int i=0; i<retailers.size(); i++) {
		int level = levelOf(retailers[i]);
		if (level < minLevel) {
			minLevel = level;
			cnt = 1;
		} else if (level == minLevel) {
			cnt++;
		}
	}
	double price = P * pow((1.0+r), minLevel-1);
	printf("%.4f %d", price, cnt);
	//getchar();getchar();
	return 0;
}