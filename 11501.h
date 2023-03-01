#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int T;
int N;
int price[1000000];

long long solve() {
	long long ret = 0;
	int max = 0;
	for (int i = N-1; i >= 0; i--) {
		if (price[i] > max) max = price[i];
		ret += (max - price[i]);
	}
	return ret;
}

int main_11501() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> price[j];
		}
		cout << solve() << endl;
	}

	return 0;
}