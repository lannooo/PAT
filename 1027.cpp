#include <cstdio>

const char radix13[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

void change(int n, char chs[]) {
	int count=0;
	if (n < 13) {
		chs[0] = '0';
		chs[1] = radix13[n];
		chs[2] = 0;
	} else {
		chs[0] = radix13[n / 13];
		chs[1] = radix13[n % 13];
		chs[2] = 0;
	}
	
}

int _1027(){
	int r, g, b;// decimal value for RGB
	scanf("%d%d%d", &r, &g, &b);
	printf("#");
	char chs[3];
	change(r, chs);
	printf("%s", chs);
	change(g, chs);
	printf("%s", chs);
	change(b, chs);
	printf("%s", chs);
	getchar();getchar();
	return 0;
}