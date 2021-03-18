#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

struct groupNode {
	string name;
	int height;
}photonodes[10000];

bool cmp_1109(groupNode a, groupNode b) {
	if (a.height != b.height) return a.height > b.height;
	return a.name < b.name;
}

int _1109() {
	int k, n;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> photonodes[i].name >> photonodes[i].height;
	}
	sort(photonodes, photonodes+n, cmp_1109);
	int cnt_row = n/k;
	int cnt_lastrow = (n % cnt_row) + cnt_row;
	int index = 0;
	deque<groupNode> dq;
	

	for (int i=1; i<=k; i++) {
		int cnt = (i!=1)?cnt_row:cnt_lastrow;
		bool front = true;
		dq.push_front(photonodes[index++]);
		for (int j=1; j<cnt; j++) {
			if (front) {
				front = false;
				dq.push_front(photonodes[index++]);
			} else {
				front = true;
				dq.push_back(photonodes[index++]);
			}
		}
		bool firstIn = true;
		while(!dq.empty()) {
			groupNode one = dq.front();dq.pop_front();
			if (!firstIn) {
				cout << " " << one.name;
			} else {
				firstIn = false;
				cout << one.name;
			}
		}
		if (i!=k)
			cout << endl;
	}
	//cin.get();cin.get();
	return 0;
}