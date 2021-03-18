#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

struct Richman {
	string name;
	int age;
	int worth;
}richmans[100000];

bool cmp_1055(Richman a, Richman b) {
	if (a.worth != b.worth) return  a.worth > b.worth;
	if (a.age != b.age) return a.age < b.age;
	return a.name < b.name;
}

int _1055() {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> richmans[i].name >> richmans[i].age >> richmans[i].worth;
	}
	sort(richmans, richmans+n, cmp_1055);
	for (int query=1; query<=k; query++) {
		int m, amin, amax;
		int cnt = 0;
		cin >> m >> amin >> amax;
		cout << "Case #" <<query <<":"<<endl;
		for (int i=0; i<n; i++) {
			if (richmans[i].age <= amax && richmans[i].age >= amin) {
				cout << richmans[i].name <<" "<< richmans[i].age <<" "<<richmans[i].worth<<endl;
				cnt++;
				if (cnt == m) break;
			}
		}
		if (cnt==0) cout << "None"<<endl;
	}
	//cin.get();cin.get();
	return 0;
}