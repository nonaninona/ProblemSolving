#pragma once
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N;

int main_25214() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	int temp;
	cin >> temp;
	int localMAX = temp;
	int localMIN = temp;
	int subMIN = INT_MAX;
	cout << localMAX - localMIN << "\n";
	for (int i = 0; i < N - 1; i++) {
		cin >> temp;
		if (temp - subMIN > localMAX - localMIN) {
			localMAX = temp;
			localMIN = subMIN;
		}
		else if (temp >= localMAX)
			localMAX = temp; 
		else if (temp < localMIN)
			subMIN = temp;
		cout << localMAX - localMIN << "\n";
	}
	return 0;
}