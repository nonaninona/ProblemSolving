#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int T;
int set[20][3];
int answer[20];

int euclid(int a, int b) {
	int big = max(a, b);
	int small = min(a, b);
	if (big % small == 0)
		return small;
	return euclid(small, big % small);
}

int main_25333() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 3; j++)
			cin >> set[i][j];
		int a = set[i][0];
		int b = set[i][1];
		int x = set[i][2];
	
		answer[i] = x / euclid(a, b);
	}

	for (int i = 0; i < T; i++)
		cout << answer[i] << endl;

	return 0;
}