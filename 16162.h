#pragma once
#include <iostream>
using namespace std;

int N, A, D;

int main_16162() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> A;
	cin >> D;
	int temp;
	int X = 0;
	while (N--) {
		cin >> temp;
		if (temp == (A + D * X))
			X++;
	}

	cout << X << endl;

	return 0;
}