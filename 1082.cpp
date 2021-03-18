#include <iostream>
#include <string>
#include <vector>
using namespace std;

string chinese[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

void to4Digits(vector<string> &v, int num, bool hasHigh){
	int d1 = num % 10; num /=10;
	int d10 = num % 10; num /=10;
	int d100 = num % 10; num /=10;
	int d1000 = num % 10; num /=10;
	int option = (d1>0?1:0)+(d10>0?2:0)+(d100>0?4:0)+(d1000>0?8:0);
	switch(option) {
	case 0:break;
	case 1:
		if (hasHigh) v.push_back(chinese[0]); 
		v.push_back(chinese[d1]);
		break;
	case 2:
		if (hasHigh) v.push_back(chinese[0]);
		v.push_back(chinese[d10]);v.push_back("Shi");
		break;
	case 3:
		if (hasHigh) v.push_back(chinese[0]);
		v.push_back(chinese[d10]);v.push_back("Shi");
		v.push_back(chinese[d1]);
		break;
	case 4:
		if (hasHigh) v.push_back(chinese[0]);
		v.push_back(chinese[d100]);v.push_back("Bai");
		break;
	case 5:
		if (hasHigh) v.push_back(chinese[0]);
		v.push_back(chinese[d100]);v.push_back("Bai");
		v.push_back(chinese[0]);
		v.push_back(chinese[d1]);
		break;
	case 6:
		if (hasHigh) v.push_back(chinese[0]);
		v.push_back(chinese[d100]);v.push_back("Bai");
		v.push_back(chinese[d10]);v.push_back("Shi");
		break;
	case 7:
		if (hasHigh) v.push_back(chinese[0]);
		v.push_back(chinese[d100]);v.push_back("Bai");
		v.push_back(chinese[d10]);v.push_back("Shi");
		v.push_back(chinese[d1]);
		break;
	case 8:
		v.push_back(chinese[d1000]);v.push_back("Qian");
		break;
	case 9:
		v.push_back(chinese[d1000]);v.push_back("Qian");
		v.push_back(chinese[0]);
		v.push_back(chinese[d1]);
		break;
	case 10:
		v.push_back(chinese[d1000]);v.push_back("Qian");
		v.push_back(chinese[0]);
		v.push_back(chinese[d10]);v.push_back("Shi");
		break;
	case 11:
		v.push_back(chinese[d1000]);v.push_back("Qian");
		v.push_back(chinese[0]);
		v.push_back(chinese[d10]);v.push_back("Shi");
		v.push_back(chinese[d1]);
		break;
	case 12:
		v.push_back(chinese[d1000]);v.push_back("Qian");
		v.push_back(chinese[d100]);v.push_back("Bai");
		break;
	case 13:
		v.push_back(chinese[d1000]);v.push_back("Qian");
		v.push_back(chinese[d100]);v.push_back("Bai");
		v.push_back(chinese[0]);
		v.push_back(chinese[d1]);
		break;
	case 14:
		v.push_back(chinese[d1000]);v.push_back("Qian");
		v.push_back(chinese[d100]);v.push_back("Bai");
		v.push_back(chinese[d10]);v.push_back("Shi");
		break;
	case 15:
		v.push_back(chinese[d1000]);v.push_back("Qian");
		v.push_back(chinese[d100]);v.push_back("Bai");
		v.push_back(chinese[d10]);v.push_back("Shi");
		v.push_back(chinese[d1]);
		break;
	default:break;
	}
}

// p1,p2,p3 -> 1,2222,3333
void to3Parts(vector<string> &v, int p1, int p2, int p3) {
	int option = (p1>0?4:0)+(p2>0?2:0)+(p3>0?1:0);
	switch(option) {
	case 0:
		v.push_back(chinese[0]);
		break;
	case 1:
		to4Digits(v, p3, false);
		break;
	case 2:
		to4Digits(v, p2, false);
		v.push_back("Wan");
		break;
	case 3:
		to4Digits(v, p2, false);
		v.push_back("Wan");
		to4Digits(v, p3, true);
		break;
	case 4:
		to4Digits(v, p1, false);
		v.push_back("Yi");
		break;
	case 5:
		to4Digits(v, p1, false);
		v.push_back("Yi");
		v.push_back(chinese[0]);
		to4Digits(v, p3, false);
		break;
	case 6:
		to4Digits(v, p1, false);
		v.push_back("Yi");
		to4Digits(v, p2, true);
		v.push_back("Wan");
		break;
	case 7:
		to4Digits(v, p1, false);
		v.push_back("Yi");
		to4Digits(v, p2, true);
		v.push_back("Wan");
		to4Digits(v, p3, true);
		break;
	default:break;
	}
}

int _1082() {
	long long number;
	vector<string> chi;
	cin >> number;
	if (number<0){
		number = -number;
		chi.push_back("Fu");
	}
	int p1,p2,p3;
	p1 = number/100000000;number %= 100000000;
	p2 = number/10000; number %= 10000;
	p3 = number;
	to3Parts(chi, p1, p2, p3);
	
	for (int i=0; i<chi.size(); i++) {
		if (i!=0) cout<< " " << chi[i];
		else cout << chi[i];
	}


	return 0;
}