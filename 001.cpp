#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX_N = 32000;
long long squares[MAX_N]={0};
int highparts[MAX_N]={0};
void initSquares() {
	for (int i=1; i<MAX_N; i++) {
		squares[i] = i*i;
		highparts[i] = squares[i]/1000;
	}
}

bool cmp(pair<int,int> a, pair<int,int> b) {
	if(a.first != b.first) return a.first< b.first;
	return a.second <b.second;
}

vector<pair<int, int> > findSquareFriends(int maxA, int n) {
	long long maxSqr = maxA*1000+999;
	vector<pair<int, int> > ans;
	int cnt = 1;
	int mark, hmark;
	bool first=true;
	for (int i=32; i<MAX_N; i++) {
		int now = highparts[i];
		int next = highparts[i+1];
		if (now + 1 == next) {
			if (first) {
				mark = i;
				hmark = highparts[i];
				first = false;
			}
			cnt++;
		} else {
			if (!first && cnt >= n) {
				while (!first && cnt >= n) {
					ans.push_back(pair<int,int>(hmark, mark));
					mark++;hmark++;cnt--;
				}
				cnt=1;
				first = true;
			} else if (squares[i] > maxSqr) break;
		}
	}
	return ans;
}

int main() {
	initSquares();
	int n, maxA;
	cin >> n>> maxA;
	vector<pair<int,int> > ans = findSquareFriends(maxA, n);
	if (ans.empty()) {
		cout << "No Solution.";
	} else {
		sort(ans.begin(), ans.end(), cmp);
		int end = ans.size()-1;
		while(ans[end].first > maxA) end--;
		if (end < 0) cout << "No Solution.";
		else {
			for (int i=0; i<ans.size(); i++) {
				if (i!=0) cout <<endl;
				cout << ans[i].first <<" "<<ans[i].second;
			}
		}
	}
	//cin.get();cin.get();
	return 0;
}