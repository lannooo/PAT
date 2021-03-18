#include <cstdio>
#include <cstdlib>
#include <ctime>

int total = 0;
int colors[600 * 800];

void swap(int colors[], int p1, int p2) {
	int temp = colors[p1];
	colors[p1] = colors[p2];
	colors[p2] = temp;
}

int randomPos(int left, int right) {
	//return (int)((1.0*rand()/RAND_MAX)*(right-left)+left);
	return (left+right)/2;
}

int partition(int colors[], int left, int right) {
	int p = randomPos(left, right);
	swap(colors, left, p);
	int temp = colors[left];
	while(left < right) {
		while(left < right && colors[right] >= temp) right--;
		colors[left] = colors[right];
		while(left < right && colors[left] <= temp) left++;
		colors[right] = colors[left];
	}
	colors[left] = temp;
	return left;
}

int gather(int colors[], int left, int right, int p) {
	if (right + 1 == p) { // [left...right,p]
		while(left <= right) {
			while(left <= right && colors[right] == colors[p]) right--;
			while(left <= right && colors[left] != colors[p]) left++;
			if (left < right) {
				swap(colors, left, right);
				left++;
				right--;
			}
		}
		return right+1;
	} else { // [p, left...right]
		while(left <= right) {
			while(left<=right && colors[left] == colors[p]) left++;
			while(left<=right && colors[right]!= colors[p]) right--;
			if(left < right) {
				swap(colors, left, right);
				left++;
				right--;
			}
		}
		return left-1;
	}
}

int sortAndFind(int colors[], int left, int right) {
	if (left > right) return -1;// can not happen actually
	else if (left == right) return colors[left]; //only one element in colors[]
	
	int p = partition(colors, left, right);

	int lb = (p==left) ? left : gather(colors, left, p-1, p);
	int rb = (p==right)? right: gather(colors, p+1, right, p);
	if ((rb-lb+1) > total/2) return colors[p];
	else {
		if ((lb-left) > total/2) 
			return sortAndFind(colors, left, lb-1);
		else 
			return sortAndFind(colors, rb+1, right);
	}
}

int _1054() {
	int m, n;
	int i;
	scanf("%d%d", &m, &n);
	total=m*n;

	for(i=0; i<total; i++) {
		scanf("%d", &colors[i]);
	}

	srand((unsigned)time(NULL));

	int color = sortAndFind(colors, 0, total-1);
	printf("%d", color);
	return 0;
}