#pragma once
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int N, K;
int A[100000];
int S[100001];

int main_24499() {
	cin >> N;
	cin >> K;
	int totalSum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		totalSum += A[i];
	}

	S[0] = 0;
	for (int i = 1; i < N + 1; i++)
		S[i] = S[i - 1] + A[i - 1];

	int MAX = INT_MIN;
	for (int i = 0; i < N-K+1; i++) {
		int v = S[i + K] - S[i];
		MAX = max(v, MAX);
	}
	for (int i = 0; i < K + 1; i++) {
		int v = S[i + N - K] - S[i];
		MAX = max(totalSum - v, MAX);
	}

	cout << MAX << endl;

	return 0;
}