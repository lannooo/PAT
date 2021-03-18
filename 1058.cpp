#include <cstdio>

int _1058() {
	// 17 sickles to 1 galleon
	// 29 knuts to 1 sickle
	int galleon=0, sickles=0, knuts=0;
	int a, b, c;
	scanf("%d.%d.%d", &a, &b, &c);
	galleon+=a;
	sickles+=b;
	knuts  +=c;
	scanf("%d.%d.%d", &a, &b, &c);
	galleon+=a;
	sickles+=b;
	knuts  +=c;

	if (knuts > 28) {
		int moreSickle = knuts/29;
		knuts = knuts % 29;
		sickles += moreSickle;
	}
	if (sickles > 16) {
		int moreGalleon = sickles/17;
		sickles = sickles % 17;
		galleon += moreGalleon;
	}
	printf("%d.%d.%d", galleon, sickles, knuts);

	return 0;
}