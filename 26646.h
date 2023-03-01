#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int H[50000];

int square(int x) {
	return x * x;
}

int solve() {
	int ret = 0;
	for (int i = 0; i < N-1; i++)
		ret += square(H[i] + H[i + 1]) + square(abs(H[i] - H[i + 1]));
	return ret;
}

int main_26646() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> H[i];

	cout << solve() << endl;

	return 0;
}