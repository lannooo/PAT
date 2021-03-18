#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct Testee {
	string regisNumber;
	int score;
	int location;
	int localRank;
	int finalRank;
} testees[30003];

bool cmp(Testee a, Testee b) {
	if (a.score != b.score) return a.score > b.score;
	return a.regisNumber < b.regisNumber;
}

int _1025() {
	int n,k;
	int total=0;
	int score;
	string regisNumber;

	cin>>n;

	for(int location=1; location<=n; location++) {
		cin>>k;
		for(int i=total; i<total+k; i++) {
			cin>>regisNumber>>score;
			testees[i].score = score;
			testees[i].regisNumber = regisNumber;
			testees[i].location = location;
		}
		// sort from testees[total] to testees[total + k]
		sort(testees+total, testees+total+k, cmp);

		int r = 1;
		testees[total].localRank = 1;
		for (int i=total+1; i<total+k; i++) {
			r++;
			if(testees[i].score == testees[i-1].score) {
				testees[i].localRank = testees[i-1].localRank;
			} else {
				testees[i].localRank = r;
			}
		}

		total+=k;
	}

	sort(testees, testees+total, cmp);
	int r = 1;
	testees[0].finalRank = 1;

	cout<<total<<endl;
	cout<<testees[0].regisNumber<<" "<<testees[0].finalRank<<" "<<testees[0].location<<" "<<testees[0].localRank<<endl;
	for(int i=1; i<total; i++) {
		r++;
		if (testees[i].score == testees[i-1].score) {
			testees[i].finalRank = testees[i-1].finalRank;
		} else {
			testees[i].finalRank = r;
		}
		cout<<testees[i].regisNumber<<" "<<testees[i].finalRank<<" "<<testees[i].location<<" "<<testees[i].localRank<<endl;
	}

	//cin.get();cin.get();
	return 0;
}