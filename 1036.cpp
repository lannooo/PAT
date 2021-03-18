#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
	string name;
	string id;
	int grade;
}student;

bool cmp(Student a, Student b){
	return a.grade > b.grade;
}

int _1036() {
	vector<Student> males;
	vector<Student> females;
	string gender;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> student.name >> gender >> student.id >> student.grade;
		if (gender == "M") males.push_back(student);
		else females.push_back(student);
	}
	sort(males.begin(), males.end(), cmp);
	sort(females.begin(), females.end(), cmp);
	int high = -1, low = -1;
	if (females.empty()) {
		cout << "Absent"<<endl;
	} else {
		cout << females[0].name << " " << females[0].id << endl;
		high = females[0].grade;
	}
	if (males.empty()) {
		cout << "Absent"<<endl;
	} else {
		cout << males[males.size()-1].name << " " << males[males.size()-1].id << endl;
		low = males[males.size()-1].grade;
	}
	if (high == -1 || low == -1) cout << "NA";
	else cout << (high - low);
	return 0;
}