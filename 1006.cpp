#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int time_to_int(int h, int m, int s) {
	return s + m*100 + h*10000;
}

int _1006() {
	int	m;
	scanf("%d", &m);
	char buf[20];
	int h1,m1,s1;
	int h2,m2,s2;
	string id_open;
	string id_close;
	int earliest = 999999;
    int latest = 0;
	for(int i=0; i<m; i++) {
		scanf("%s %02d:%02d:%02d %02d:%02d:%02d", buf, &h1,&m1,&s1, &h2,&m2,&s2);
		int signin = time_to_int(h1,m1,s1);
		int signout = time_to_int(h2, m2, s2);
		
		if (signin <= earliest) {
			earliest = signin;
			id_open = string(buf);
		}
		if (signout >= latest) {
			latest = signout;
			id_close = string(buf);
		}
	}
	cout<<id_open<<" "<<id_close;
	//cin.get();cin.get();
	return 0;
}