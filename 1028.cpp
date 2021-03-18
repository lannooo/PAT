#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct StudentInfo {
	string id;
	string name;
	int grade;
};

bool cmpbyId(StudentInfo *a, StudentInfo *b) {
	return a->id < b->id;
}

bool cmpbyName(StudentInfo *a, StudentInfo *b) {
	if (a->name != b->name) return a->name < b->name;
	return a->id < b->id;
}

bool cmpbyGrade(StudentInfo *a, StudentInfo *b) {
	if (a->grade != b->grade) return a->grade < b->grade;
	return a->id < b->id;
}

int _1028() {
	vector<StudentInfo* > list;
	int n, c;
	string id, name;
	int grade;
	cin>>n>>c;
	for(int i=0; i<n; i++) {
		StudentInfo * info = new StudentInfo;
		cin >> info->id >> info->name >> info->grade;
		list.push_back(info);
	}
	if (c == 1) {
		// sort by id
		sort(list.begin(), list.end(), cmpbyId);
	} else if (c == 2) {
		// sort by name
		sort(list.begin(), list.end(), cmpbyName);
	} else {
		// sort by grade
		sort(list.begin(), list.end(), cmpbyGrade);
	}
	for(vector<StudentInfo*>::iterator it = list.begin(); it != list.end(); it++) {
		cout<<(*it)->id << " " << (*it)->name <<" "<<(*it)->grade<<endl;
	}
	
	return 0;
}