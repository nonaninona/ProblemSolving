#pragma once
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N;
int A[100000];

bool compare(int a, int b) {
	return a > b;
}

int main_1758() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N, compare);

	ll total = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] - i <= 0)
			continue;
		total += (A[i] - i);
	}

	cout << total << endl;

	return 0;
}