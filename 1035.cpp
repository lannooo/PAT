#include <cstdio>
#include <cstring>

typedef struct accountInfo {
	char username[11];
	char password[11];
	bool modified;
	accountInfo () {
		modified = false;
	}
}Account;


bool modify(char password[]) {
	int len = strlen(password);
	int i;
	bool modified = false;
	for(i=0; i<len; i++) {
		if (password[i] == '1') {
			password[i] = '@';
			modified =true;
		} else if (password[i]=='0') {
			password[i] = '%';
			modified = true;
		} else if (password[i]=='l') {
			password[i] = 'L';
			modified = true;
		} else if (password[i]=='O') {
			password[i] = 'o';
			modified = true;
		}
	}
	return modified;
}

int _1035() {
	Account accounts[1000];
	int n, m, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%s %s", accounts[i].username, accounts[i].password);
	}
	m=0;
	for (i=0; i<n; i++) {
		if (modify(accounts[i].password)) {
			accounts[i].modified = true;
			m++;
		}
	}
	if (m == 0) {
		if (n == 1) printf("There is 1 account and no account is modified");
		else printf("There are %d accounts and no account is modified", n);
	} else {
		printf("%d", m);
		for (i=0; i<n; i++) {
			if (accounts[i].modified) {
				printf("\n%s %s", accounts[i].username, accounts[i].password);
			}
		}
	}
	return 0;
}