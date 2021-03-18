#include <iostream>
#include <cstring>
using namespace std;
int const MAX_STR_LEN = 100001;
char patbuf[MAX_STR_LEN];
int tcnt[MAX_STR_LEN];
int _1093() {
	cin.getline(patbuf, MAX_STR_LEN);
	int len = strlen(patbuf);
	tcnt[len-1] = (patbuf[len-1]=='T') ? 1 : 0;
	for (int i=len-2; i>=0; i--) {
		if (patbuf[i] == 'T') tcnt[i] = tcnt[i+1]+1;
		else tcnt[i] = tcnt[i+1];
	}
	int pcnt = 0;
	long long patcnt = 0;
	for (int i=0; i<len-1; i++) {
		if(patbuf[i] == 'P') pcnt++;
		else if (patbuf[i] == 'A') {
			patcnt = (patcnt + pcnt * tcnt[i+1]) % 1000000007;
		}
	}
	cout << patcnt;
	return 0;
}