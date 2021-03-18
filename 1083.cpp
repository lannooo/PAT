#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct StuRecord {
	string name;
	string id;
	int grade;
} record;

bool cmp_1083(StuRecord a, StuRecord b) {
	return a.grade > b.grade;
}

int _1083() {
	int n;
	vector<StuRecord> v;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> record.name >> record.id >> record.grade;
		v.push_back(record);
	}
	int from, to;
	cin >> from >> to;
	sort(v.begin(), v.end(), cmp_1083);
	int cnt = 0;
	for(int i=0; i<v.size(); i++) {
		if (v[i].grade <= to && v[i].grade >= from) {
			if (cnt != 0) cout << endl;
			cnt++;
			cout << v[i].name << " " << v[i].id;
		}
	}
	if (cnt == 0) cout << "NONE";
	//cin.get();cin.get();
	return 0;
}