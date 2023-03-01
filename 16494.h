#pragma once
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int N, M;
int A[20];

int subSum(int from, int to) {
	int ret = 0;
	for (int i = from; i < to + 1; i++)
		ret += A[i];
	return ret;
}

int getMax(int m, int from) {
	if (m == 0)
		return 0;

	int ret = INT_MIN;
	for (int i = from; i < N - m+1; i++)
		for (int j = i; j < N - m+1; j++)
			ret = max(ret, subSum(i, j) + getMax(m - 1, j + 1));

	return ret;
}

int main_16494() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cout << getMax(M, 0) << endl;



	return 0;
}
