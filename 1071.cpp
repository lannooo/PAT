#include <cstring>
#include <map>
#include <string>
#include <iostream>
using namespace std;

map<string, int> wordcount;

const int MAX_BUF_SIZE = 1048586;
char buf[MAX_BUF_SIZE];

int _1071() {
	cin.getline(buf, MAX_BUF_SIZE);
	int total = strlen(buf);
	char wordbuf[100];
	int cnt = 0;
	char ch;
	for (int i=0; i<total; i++) {
		ch = buf[i];
		if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
		if ( ch >= 'a' && ch <= 'z' || ch>='A' && ch<= 'Z' || ch>='0' && ch <='9') {
			wordbuf[cnt++] = ch;
		} else if (cnt > 0){
			wordbuf[cnt] = 0;
			wordcount[string(wordbuf)]++;
			cnt = 0;
		}
	}
	if (cnt > 0) {
		wordbuf[cnt] = 0;
		wordcount[string(wordbuf)]++;
	}
	int maxcount = 0;
	string mstr;
	for (map<string,int>::iterator it = wordcount.begin(); it != wordcount.end(); it++) {
		if(it->second > maxcount) {
			mstr = it->first;
			maxcount = it->second;
		}
	}
	cout<<mstr<<" "<<maxcount;
	//getchar();getchar();
	return 0;
}