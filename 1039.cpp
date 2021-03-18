#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int _1039() {
	map<string, set<int> > studentCourses;
	int n, k;
	cin >> n >> k;
	int course, number;
	string name;
	for (int i=0; i<k; i++) {
		cin >> course >> number;
		for(int j=0; j<number; j++) {
			cin >> name;
			if (studentCourses.count(name) == 0) {
				studentCourses[name] = set<int>();
			}
			studentCourses[name].insert(course);
		}
	}
	
	for (int i=0; i<n; i++) {
		cin >> name;
		cout << name;
		if (studentCourses.count(name) == 0) {
			cout << " " << 0;
		} else {
			set<int> courses = studentCourses[name];
			cout << " " << courses.size();
			for (set<int>::iterator it = courses.begin(); it !=courses.end(); it++) {
				cout << " " << *it;
			}
		}
		if (i < n-1) cout<< endl;
	}
	//getchar();getchar();
	return 0;
}