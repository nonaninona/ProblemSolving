#pragma once
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int A[200000];

int main_25644() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int MAX = INT_MIN;
	int MAX_PROFIT = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] > MAX)
			MAX = A[i];
		if (MAX - A[i] > MAX_PROFIT)
			MAX_PROFIT = MAX - A[i];
	}

	cout << MAX_PROFIT;

	return 0;
}