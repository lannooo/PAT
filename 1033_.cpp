#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct GasStation {
	int distance;
	float price;
}station;

vector<GasStation> stations;
int destination;
float costs = 0; // total money cost
int max_miles;// distance that car could run once filled the tank
int remain_miles = 0; // more distance that the remained gas can support
float units_per_mile; // gas cost that run 1 mile distance

int distbetween(int i, int j) {
	return stations[j].distance - stations[i].distance;
}

// moreMiles used to reflect the amount of remained gas in tank
int reachNext(int stationNum, int moreMiles) {
	GasStation st = stations[stationNum];
	// at last station, just see whether can reach destination
	if (stationNum == stations.size()-1) {
		if (destination <= st.distance + max_miles) {
			costs += st.price * units_per_mile * (destination - st.distance - moreMiles);
			return destination;
		} else { // we can not reach there! return a furtherest distance
			costs += st.price * units_per_mile * (max_miles-moreMiles);
			return st.distance + max_miles;
		}
	}

	int findnext = -1;
	bool higheprice = true;
	// find a next proper station
	for (int i=stationNum+1; i<stations.size(); i++) {
		// this station is out of range
		if (stations[i].distance - st.distance > max_miles) break;
		
		if (stations[i].price < st.price) { // find the first station which gas price is cheaper than current
			findnext = i;
			higheprice = false;
			break;
		}

		if (findnext == -1) findnext = i;
		else if (stations[i].price <= stations[findnext].price) findnext = i;
	}
	// not found, stop travel
	if (findnext == -1) {
		costs += st.price * units_per_mile * (max_miles - moreMiles);
		return st.distance + max_miles;
	}
	// found the next station which has higher price
	if (higheprice) {
		// but we can just reach destination right now
		if (st.distance + max_miles >= destination) {
			costs += st.price * units_per_mile * (destination - st.distance - moreMiles);
			return destination;
		}
		// reach next station
		costs += st.price*units_per_mile*(max_miles-moreMiles);
		return reachNext(findnext, max_miles-(stations[findnext].distance - st.distance));
	} else {
		costs += st.price*units_per_mile*(stations[findnext].distance - st.distance - moreMiles);
		return reachNext(findnext, 0);
	}
}

int travel() {
	if(stations[0].distance > 0) return 0; // no where to go
	return reachNext(0, 0);
}

bool cmp(GasStation a, GasStation b) {
	if (a.distance != b.distance) return a.distance < b.distance;
	return a.price < b.price;
}

int _1033() {
	int dist_per_unit,capacity_of_tank, n;
	cin >> capacity_of_tank >> destination >> dist_per_unit >> n;
	max_miles = dist_per_unit * capacity_of_tank;
	units_per_mile = 1.0/dist_per_unit;

	for(int i=0; i<n; i++) {
		cin >> station.price >> station.distance;
		stations.push_back(station);
	}
	sort(stations.begin(), stations.end(), cmp);

	int dist_reached = travel();
	if (dist_reached != destination) {
		printf("The maximum travel distance = %.2f", (float)dist_reached);
	} else {
		printf("%.2f", costs);
	}
	
	//getchar();getchar();
	return 0;
}